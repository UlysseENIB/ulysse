/*
* Boid.cpp
*
*  Created on: 1 oct. 2014
*      Author: ifig
*/
#include "Boid.h"
#include "Behavior.h"

Boid::Boid(long int id, float* position, float directionXY, float directionZ, float speed, string color) {
	_id = id;
	for (int pos = 0; pos<3; pos++) {
		_position[pos] = position[pos];
	}
	_directionXY = directionXY;
	_directionZ = directionZ;
	_speed = speed;
	_color = color;
}


Boid::~Boid() {
	// TODO Auto-generated destructor stub
}
//
///**
//* Move boids (perform behaviours)
//*/
float* Boid::move(vector <Boid*> *boids)
{
	Behavior behavior;
	float* futurPosition = behavior.move(this, boids);
	return futurPosition;
}

/**
* Distance between two boids
*/
float Boid::getDistance(Boid *boid1, Boid *boid2)
{
	float x = boid1->getX() - boid2->getX();
	float y = boid1->getY() - boid2->getY();
	float z = boid1->getZ() - boid2->getZ();

	float distance = distance_to_pos(x, y, z);
	return distance;
}

/**
* Distance between two points
*/
float Boid::distance_to_pos(float x, float y, float z)
{
	float distance;
	(x==0 && y==0 && z==0) ? distance=0 : distance=sqrt(x*x + y*y + z*z);
	return distance;
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