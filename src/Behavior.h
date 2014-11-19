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
	//computes new position
	float* move(Boid* theboid, vector <Boid*> *boids); 

	//apply rules of Boid's Reynold
	float* flocking(Boid* theBoid, vector <Boid*> *boids, float* futurePosition);
	
	// rule separation
	float* separation(Boid* theboid, float sepX, float sepY, float sepZ, float sepCoun0t, float* futurePosition);
	
	//rule cohesion
	float* cohesion(Boid* theboid, float cohX, float cohY, float cohZ, float cohCount, float* futurePosition);
	
	//rule alignement
	float* alignment(Boid* theboid, float alignX, float alignY, float alignZ, float alignCount, float* futurePosition);
	
	//rule alignement
	float* keyword(Boid* theboid, float keywordX, float keywordY, float keywordZ, float keywordCount, float* futurePosition);

	//apply one bounce on a wall
	float* wall_bounce(Boid* theboid, float* futurePosition);
};