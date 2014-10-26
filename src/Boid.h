/*
* Boid.h
*
*  Created on: 1 oct. 2014
*      Author: ifig
*/
#include "math.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#ifndef BOID_H_
#define BOID_H_

class Boid {

private:
	int _numeroCase[3];
	float _position[3];
	float _directionXY, _directionZ;
	long int _id;
	float _speed;
	string _color;
	float _newDX, _newDY, _newDZ;

public:
	Boid(long int id, float* _position, int* _case, float directionXY, float directionZ, float speed, string color);
	virtual ~Boid();

	float* move(vector <Boid*> boids); //computes new position

	float distance(Boid *boid1, Boid *boid2); //distance between 2 boid

	float distance_to_pos(float x, float y, float z); //distance between two points

	void flocking(vector <Boid*> boids);
	void separation(vector <Boid*> boids, float sepX, float sepY, float sepZ, float sepCount);
	void cohesion(vector <Boid*> boids, float cohX, float cohY, float cohZ, float cohCount);
	void alignment(vector <Boid*> boids, float alignX, float alignY, float alignZ, float alignCount);
	void wall_bounce();

	float dirX();
	float dirY();
	float dirZ();

	float getX(){ return _position[0]; }
	float getY(){ return _position[1]; }
	float getZ(){ return _position[2]; }

	float getDX(){ return _newDX; }
	float getDY(){ return _newDY; }
	float getDZ(){ return _newDZ; }

	int getId(){ return _id; }

	float getDir(); //returns the direction of the boid
	float getVel(); //returns the speed

	void setColor(string color){ _color = color; };
	string getColor(){ return _color;}

	int* getNumeroCase(){ return _numeroCase; }
	void setNumeroCase(int numeroCase[3]){
		for (int numCase = 0; numCase<sizeof(_numeroCase) / sizeof(int); numCase++){
			_numeroCase[numCase] = numeroCase[numCase];
		}
	}

	float* getPosition(){ return _position; }
	void setPosition(float newPosition[3]){
		for (int pos = 0; pos<sizeof(_position)-1; pos++){
			_position[pos] = newPosition[pos];
		}
	}

};

#endif /* BOID_H_ */