/*
* Behavior.h
*
*  Created on: 2014
*      Author: kristen
*/
#pragma once
#include "Boid.h"
#include "Global.h"

class Behavior
{
public:

	float* move(Boid* theboid, vector <Boid*> *boids); //computes new position*void flocking(vector <Boid*> *boids);
	float* flocking(Boid* theBoid, vector <Boid*> *boids, float* futurePosition);
	float* separation(Boid* theboid, float sepX, float sepY, float sepZ, float sepCoun0t, float* futurePosition);
	float* cohesion(Boid* theboid, float cohX, float cohY, float cohZ, float cohCount, float* futurePosition);
	float* alignment(Boid* theboid, float alignX, float alignY, float alignZ, float alignCount, float* futurePosition);
	float* wall_bounce(Boid* theboid, float* futurePosition);
};

