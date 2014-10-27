/*
* Boi.cpp
*
*  Created on: 1 oct. 2014
*      Author: ifig
*/
#include "Boid.h"


Boid::Boid(long int id, float* position, int* nCase, float directionXY, float directionZ, float speed, string color) {
	_id = id;
	for (int pos = 0; pos<3; pos++) {
		_position[pos] = position[pos];
	}
	for (int poscas = 0; poscas<3; poscas++) {
		_numeroCase[poscas] = nCase[poscas];
	}
	_directionXY = directionXY;
	_directionZ = directionZ;
	_speed = speed;
	_color = color;
}


Boid::~Boid() {
	// TODO Auto-generated destructor stub
}

/**
* Move boids (perform behaviours)
*/
float* Boid::move(vector <Boid*> boids)
{
	_newDX = (dirX() / (distance_to_pos(dirX(), dirY(), dirZ()))) * _speed;	//Sets the temporary direction of X (This is equal to, "ammount of X movement / distance between X & Y movement) * velocity")
	_newDY = (dirY() / (distance_to_pos(dirX(), dirY(), dirZ()))) * _speed;	//Sets the temporary direction of Y (This is equal to, "ammount of Y movement / distance between X & Y movement) * velocity")
	_newDZ = (dirZ() / (distance_to_pos(dirX(), dirY(), dirZ()))) * _speed;	//Sets the temporary direction of Y (This is equal to, "ammount of Y movement / distance between X & Y movement) * velocity")

	flocking(boids);

	wall_bounce(); //check for border collision

	_directionXY = atan2(_newDX, _newDY);	//Sets the direction based on the new cords
	_directionZ = atan(_newDZ);	//Sets the direction based on the new cords

	if (_directionZ < -atan(1) * 4){ _directionZ += 2 * (float) atan(1) * 4; } //atan(1)*4 = Pi
	if (_directionZ > atan(1) * 4) { _directionZ -= 2 * (float) atan(1) * 4; }

	_position[0] += dirX();
	_position[1] += dirY();
	_position[2] += dirZ();

	return _position;
}

/**
* This function calls the other funcitons (separation, cohesion, alignement to create flocking
*/
void Boid::flocking(vector <Boid*> boids){
	float sepX = 0, sepY = 0, sepZ = 0;	//Stores the average X/Y pos's
	float sepCount = 0;		//Stores the number of pos's
	float cohX = 0, cohY = 0, cohZ = 0;
	float cohCount = 0;
	float alignX = 0, alignY = 0, alignZ = 0;	//Stores the average X/Y direction
	float alignCount = 0;			//Stores the number of directions
	for (unsigned int i = 0; i < boids.size(); i++)
	{
		if (boids[i]->getId() != this->getId()){
			float distance = getDistance(this, boids[i]);
			if (distance < (RADIUS_SEPARATION))
			{
				sepX += boids[i]->getX();// + boids[i]->dirX();	//Get the average FUTURE positions of the nearby boids, X
				sepY += boids[i]->getY();// + boids[i]->dirY();	//Get the average FUTURE positions of the nearby boids, Y

				sepZ += boids[i]->getZ();// + boids[i]->dirZ();	//Get the average FUTURE positions of the nearby boids, Z
				sepCount++;
			}
			else if (distance < (RADIUS_COHESION))
			{
				float dirXTmp = boids[i]->dirX();
				float dirYTmp = boids[i]->dirY();
				float dirZTmp = boids[i]->dirZ();
				cohX += boids[i]->getX() + dirXTmp; //Add the boids[i] current X position
				cohY += boids[i]->getY() + dirYTmp; //Add the boids[i] current Y position
				cohZ += boids[i]->getZ() + dirZTmp; //Add the boids[i] current Z position
				cohCount++;
				alignX += dirXTmp;	//Add the boids[i] current movement X
				alignY += dirYTmp;	//Add the boids[i] current movement Y
				alignZ += dirZTmp;	//Add the boids[i] current movement Z
				alignCount++;
			}
		}
	}
	cohesion(cohX, cohY, cohZ, cohCount);
	separation(sepX, sepY, sepZ, sepCount);
	alignment(alignX, alignY, alignZ, alignCount);
}

/**
* Performs boucing if wall detected
*/
void Boid::wall_bounce()
{
	if ((getX() < 2 && _newDX <0) || (MAX_X+2 < getX() && 0 < _newDX))
	{
		_newDX = -_newDX;
	}

	if ((getY() < 2 && _newDY <0) || (MAX_Y + 2 < getY() && 0 < _newDY))
	{
		_newDY = -_newDY;
	}
	if ((getZ() < 2 && _newDZ < 0) || (MAX_Z + 2 < getZ() && 0 < _newDZ))
	{
		_newDZ = -_newDZ;
	}
}

/**
* Performs separation
*/
void Boid::separation(float sepX, float sepY, float sepZ, float sepCount)
{
	if (sepCount > 0)	//Make sure there are some boids nearby before proceding
	{
		sepX = getX() - (sepX / sepCount);						//Difference between the two positions pos - (averagePos)
		sepY = getY() - (sepY / sepCount);						//Difference between the two positions pos - (averagePos)
		sepZ = getZ() - (sepZ / sepCount);
		sepX = (sepX / distance_to_pos(sepX, sepY, sepZ)) * _speed;		//Compute new movement based on the position / distance * velocity
		sepY = (sepY / distance_to_pos(sepX, sepY, sepZ)) * _speed;		//Compute new movement based on the position / distance * velocity
		sepZ = (sepZ / distance_to_pos(sepX, sepY, sepZ)) * _speed;		//Compute new movement based on the position / distance * velocity
	
		sepX = sepX * _speed;
		sepY = sepY * _speed;
		sepZ = sepZ * _speed;

		_newDX += (sepX - dirX()) * (float) SEPARATION;				//Adjust the new movement, Add the difference between sepDirection and current Direction * separation weighting
		_newDY += (sepY - dirY()) * (float) SEPARATION;				//Adjust the new movement, Add the difference between sepDirection and current Direction * separation weighting
		_newDZ += (sepZ - dirZ()) * (float) SEPARATION;				//Adjust the new movement, Add the difference between sepDirection and current Direction * separation weighting

	}
}

/**
* Performs cohesion
*/
void Boid::cohesion(float cohX, float cohY, float cohZ, float cohCount)
{
	if (cohCount > 0)
	{
		cohX = (cohX / cohCount) - getX();						//Difference in X position between averaged nearby X and current X (avg - curr, means we get the direction to turn towards)
		cohY = (cohY / cohCount) - getY();						//Difference in Y position between averaged nearby Y and current Y (avg - curr, means we get the direction to turn towards)
		cohZ = (cohZ / cohCount) - getZ();
		cohX = (cohX / distance_to_pos(cohX, cohY, cohZ)) * _speed;	//Compute the new X movement (Based on the average pos)
		cohY = (cohY / distance_to_pos(cohX, cohY, cohZ)) * _speed;	//Compute the new Y movement (Based on the average pos)
		cohZ = (cohZ / distance_to_pos(cohX, cohY, cohZ)) * _speed;
		_newDX += (cohX - dirX()) * (float) COHESION;					//Adjust the new X movement with, difference (average future pos - current movement) * weighting
		_newDY += (cohY - dirY()) * (float) COHESION;					//Adjust the new Y movement with, difference (average future pos - current movement) * weighting
		_newDZ += (cohZ - dirZ()) * (float) COHESION;
	}
}

/**
* Performs alignment
*/
void Boid::alignment(float alignX, float alignY, float alignZ, float alignCount)
{
	if (alignCount > 0)
	{
		alignX = alignX / alignCount;		//Average out the movement
		alignY = alignY / alignCount;		//Average out the movement
		alignZ = alignZ / alignCount;		//Average out the movement
		_newDX += alignX * (float) ALIGNEMENT;		//Add the averaged out movement * weighting to the new movement direction
		_newDY += alignY * (float) ALIGNEMENT;		//Add the averaged out movement * weighting to the new movement direction
		_newDZ += alignZ * (float) ALIGNEMENT;
	}
}

/**
* Distance between two boids
*/
float Boid::getDistance(Boid *boid1, Boid *boid2)
{
	//float dis = sqrt(pow((boid1->getX() - boid2->getX()), 2) + pow((boid1->getY() - boid2->getY()), 2) + pow((boid1->getZ() - boid2->getZ()), 2));
	float dis = sqrt((boid1->getX() - boid2->getX())*(boid1->getX() - boid2->getX()) + (boid1->getY() - boid2->getY())*(boid1->getY() - boid2->getY()) + (boid1->getZ() - boid2->getZ())*(boid1->getZ() - boid2->getZ()));
	return dis;
}

/**
* Distance between two points
*/
float Boid::distance_to_pos(float x, float y, float z)
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

/**
* Returns the amount the boid will move each step in the x direction
*/
float Boid::dirX()
{
	return _speed*sin(_directionXY);
}

/**
*  Returns the amount the boid will move ech step in the y direction
*/
float Boid::dirY()
{
	return _speed*cos(_directionXY);
}

/**
*  Returns the amount the boid will move ech step in the y direction
*/
float Boid::dirZ()
{
	return _speed*sin(_directionZ);
}