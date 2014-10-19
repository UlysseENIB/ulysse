/*
* Boi.cpp
*
*  Created on: 1 oct. 2014
*      Author: ifig
*/
#include "Boid.h"

float _separation = 0.09;
float _coheshion = 0.28;
float _alignment = 0.10;


int x = 20;
int rayonSeparation = x / 2;
int rayonCohesion = x*1.5;

Boid::Boid(int id, float x, float y, float z, float directionXY, float directionZ, float speed, string color) {
	_id = id;
	_x = x;
	_y = y;
	_z = z;
	_directionXY = directionXY;
	_directionZ = directionZ;
	_speed = speed;
	_color = color;
}

Boid::Boid(int id, float* _position, float directionXY, float directionZ, float speed, string color) {
	_id = id;
	for (int pos = 0; pos<3; pos++) {
		position[pos] = _position[pos];
	}
	_x = _position[0];
	_y = _position[1];
	_z = _position[2];
	_directionXY = directionXY;
	_directionZ = directionZ;
	_speed = speed;
	_color = color;
}


Boid::~Boid() {
	// TODO Auto-generated destructor stub
}

/**
* Get id of the boid
*/
int Boid::getId()
{
	return _id;
}

/**
* Set the color
*/
void Boid::setColor(string color)
{
	_color = color;
}

/**
* Get the color
*/
string Boid::getColor()
{
	return _color;
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

	if (_directionZ < -atan(1) * 4){ _directionZ += 2 * atan(1) * 4; } //atan(1)*4 = Pi
	if (_directionZ > atan(1) * 4) { _directionZ -= 2 * atan(1) * 4; }

	_x += dirX();
	_y += dirY();
	_z += dirZ();

	position[0] = _x;
	position[1] = _y;
	position[2] = _z;
	//cout << "no neighbors" << endl;
	//double dx = (double) (cos(_direction) * _speed); //direction x
	//double dy = (double) (sin(_direction) * _speed); //direction y
	//_x = _x + dx;
	//_y = _y + dy;

	return position;
}

/**
* This function calls the other funcitons (separation, cohesion, alignement to create flocking
*/
void Boid::flocking(vector <Boid*> boids){
	double sepX = 0, sepY = 0, sepZ = 0;	//Stores the average X/Y pos's
	double sepCount = 0;		//Stores the number of pos's
	double cohX = 0, cohY = 0, cohZ = 0;
	double cohCount = 0;
	double alignX = 0, alignY = 0, alignZ = 0;	//Stores the average X/Y direction
	double alignCount = 0;			//Stores the number of directions
	for (int i = 0; i < boids.size(); i++)
	{
		if ((distance(this, boids[i]) < (rayonSeparation)) && (boids[i]->getId() != _id))
		{
			sepX += boids[i]->getX();// + boids[i]->dirX();	//Get the average FUTURE positions of the nearby boids, X
			sepY += boids[i]->getY();// + boids[i]->dirY();	//Get the average FUTURE positions of the nearby boids, Y

			sepZ += boids[i]->getZ();// + boids[i]->dirZ();	//Get the average FUTURE positions of the nearby boids, Z
			sepCount++;
		}
		else if ((distance(this, boids[i]) < (rayonCohesion)) && (boids[i]->getId() != _id))
		{
			cohX += boids[i]->getX() + boids[i]->dirX(); //Add the boids[i] current X position
			cohY += boids[i]->getY() + boids[i]->dirY(); //Add the boids[i] current Y position
			cohZ += boids[i]->getZ() + boids[i]->dirZ(); //Add the boids[i] current Z position
			cohCount++;
			alignX += boids[i]->dirX();	//Add the boids[i] current movement X
			alignY += boids[i]->dirY();	//Add the boids[i] current movement Y
			alignZ += boids[i]->dirZ();	//Add the boids[i] current movement Z
			alignCount++;
		}
	}
	cohesion(boids, cohX, cohY, cohZ, cohCount);
	separation(boids, sepX, sepY, sepZ, sepCount);
	alignment(boids, alignX, alignY, alignZ, alignCount);
}

//bool Boid::areNeighbors(Boid *boid1, Boid *boid2)
//{
//	return ((
//		(boid1->getX() - boid2->getX())*(boid1->getX() - boid2->getX()) +
//		(boid1->getY() - boid2->getY())*(boid1->getY() - boid2->getY()))
//		<= 50 * 50);
//	//+(boid1->pos(Z) - boid2->pos(Z))*(boid1->pos(Z) - boid2->pos(Z)))
//}

/**
* Performs boucing if wall detected
*/
void Boid::wall_bounce()
{
	if ((getX() < 2 && _newDX <0) || (498 < getX() && 0 < _newDX))
	{
		_newDX = -_newDX;
	}

	if ((getY() < 2 && _newDY <0) || (398 < getY() && 0 < _newDY))
	{
		_newDY = -_newDY;
	}
	if ((getZ() < 2 && _newDZ < 0) || (398 < getZ() && 0 < _newDZ))
	{
		_newDZ = -_newDZ;
	}
}

/**
* Get Position x
*/
float Boid::getX()
{
	return _x;
}

/**
* Get Position y
*/
float Boid::getY()
{
	return _y;
}

/**
* Get Position z
*/
float Boid::getZ()
{
	return _z;
}

/**
* Distance between two boids
*/
float Boid::distance(Boid *boid1, Boid *boid2)
{
	float dis = sqrt(pow((boid1->getX() - boid2->getX()), 2) + pow((boid1->getY() - boid2->getY()), 2) + pow((boid1->getZ() - boid2->getZ()), 2));
	return dis;
}

/**
* Performs separation
*/
void Boid::separation(vector <Boid*> boids, double sepX, double sepY, double sepZ, double sepCount)
{
	//double sepX = 0, sepY = 0;	//Stores the average X/Y pos's
	//double sepCount = 0;		//Stores the number of pos's
	//for (int i = 0; i < boids.size(); i++)
	//{
	//	if ((distance(this, boids[i]) < (rayonSeparation)) && (boids[i]->getId() != _id))
	//	{
	//		sepX += boids[i]->getX();// + boids[i]->dirX();	//Get the average FUTURE positions of the nearby boids, X
	//		sepY += boids[i]->getY();// + boids[i]->dirY();	//Get the average FUTURE positions of the nearby boids, Y
	//		sepCount++;
	//	}
	//}
	if (sepCount > 0)	//Make sure there are some boids nearby before proceding
	{
		sepX = getX() - (sepX / sepCount);						//Difference between the two positions pos - (averagePos)
		sepY = getY() - (sepY / sepCount);						//Difference between the two positions pos - (averagePos)
		sepZ = getZ() - (sepZ / sepCount);
		sepX = (sepX / distance_to_pos(sepX, sepY, sepZ)) * _speed;		//Compute new movement based on the position / distance * velocity
		sepY = (sepY / distance_to_pos(sepX, sepY, sepZ)) * _speed;		//Compute new movement based on the position / distance * velocity
		sepZ = (sepZ / distance_to_pos(sepX, sepY, sepZ)) * _speed;		//Compute new movement based on the position / distance * velocity
		//double newDX, newDY;
		//modified
		sepX = sepX * _speed;
		sepY = sepY * _speed;
		sepZ = sepZ * _speed;

		_newDX += (sepX - dirX()) * _separation;				//Adjust the new movement, Add the difference between sepDirection and current Direction * separation weighting
		_newDY += (sepY - dirY()) * _separation;				//Adjust the new movement, Add the difference between sepDirection and current Direction * separation weighting
		_newDZ += (sepZ - dirZ()) * _separation;				//Adjust the new movement, Add the difference between sepDirection and current Direction * separation weighting

		//wall_bounce();
		//_x += _newDX;
		//_y += _newDY;
	}
}


/**
* Performs cohesion
*/
void Boid::cohesion(vector <Boid*> boids, double cohX, double cohY, double cohZ, double cohCount)
{

	//double cohX = 0, cohY = 0;
	//double cohCount = 0;
	//for (int i = 0; i < boids.size(); i++)
	//{
	//	if ( (distance(this, boids[i]) < (rayonCohesion)) && (boids[i]->getId() != _id))
	//	{
	//		cohX += boids[i]->getX() + boids[i]->dirX(); //Add the boids[i] current X position
	//		cohY += boids[i]->getY() + boids[i]->dirY(); //Add the boids[i] current Y position
	//		cohCount++;
	//	}
	//}

	if (cohCount > 0)
	{
		cohX = (cohX / cohCount) - getX();						//Difference in X position between averaged nearby X and current X (avg - curr, means we get the direction to turn towards)
		cohY = (cohY / cohCount) - getY();						//Difference in Y position between averaged nearby Y and current Y (avg - curr, means we get the direction to turn towards)
		cohZ = (cohZ / cohCount) - getZ();
		cohX = (cohX / distance_to_pos(cohX, cohY, cohZ)) * _speed;	//Compute the new X movement (Based on the average pos)
		cohY = (cohY / distance_to_pos(cohX, cohY, cohZ)) * _speed;	//Compute the new Y movement (Based on the average pos)
		cohZ = (cohZ / distance_to_pos(cohX, cohY, cohZ)) * _speed;
		_newDX += (cohX - dirX()) * _coheshion;					//Adjust the new X movement with, difference (average future pos - current movement) * weighting
		_newDY += (cohY - dirY()) * _coheshion;					//Adjust the new Y movement with, difference (average future pos - current movement) * weighting
		_newDZ += (cohZ - dirZ()) * _coheshion;
		//_x += _newDX;
		//_y += _newDY;
	}
}

/**
* Performs alignment
*/
void Boid::alignment(vector <Boid*> boids, double alignX, double alignY, double alignZ, double alignCount)
{
	//double alignX = 0, alignY = 0;	//Stores the average X/Y direction
	//double alignCount = 0;			//Stores the number of directions
	//for (int i = 0; i < boids.size(); i++)
	//{
	//	if ( (distance(this, boids[i]) < (rayonAlignement)) && (boids[i]->getId() != _id))
	//	{
	//		alignX += boids[i]->dirX();	//Add the boids[i] current movement X
	//		alignY += boids[i]->dirY();	//Add the boids[i] current movement Y
	//		alignCount++;
	//	}
	//}
	if (alignCount > 0)
	{
		alignX = alignX / alignCount;		//Average out the movement
		alignY = alignY / alignCount;		//Average out the movement
		alignZ = alignZ / alignCount;		//Average out the movement
		_newDX += alignX * _alignment;		//Add the averaged out movement * weighting to the new movement direction
		_newDY += alignY * _alignment;		//Add the averaged out movement * weighting to the new movement direction
		_newDZ += alignZ * _alignment;
	}
}

/**
* Distance between two points
*/
double Boid::distance_to_pos(double x, double y, double z)
{
	//return sqrt((x - this->getX())*(x - this->getX()) +
	//(boid1->getY() - this->getY())*(y - this->getY()));
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

/**
* Get dx
*/
double Boid::getDX()
{
	cout << "DX : " << _newDX << endl;
	return _newDX;
}

/**
* Get dy
*/
double Boid::getDY()
{
	cout << "DY : " << _newDY << endl;
	return _newDY;
}

/**
* Get dz
*/
double Boid::getDZ()
{
	cout << "DZ : " << _newDZ << endl;
	return _newDZ;
}

/**
* Returns the amount the boid will move each step in the x direction
*/
double Boid::dirX()
{
	return _speed*sin(_directionXY);
}

/**
*  Returns the amount the boid will move ech step in the y direction
*/
double Boid::dirY()
{
	return _speed*cos(_directionXY);
}

/**
*  Returns the amount the boid will move ech step in the y direction
*/
double Boid::dirZ()
{
	return _speed*sin(_directionZ);
}