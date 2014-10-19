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

public:
	Boid(int id, float x, float y, float z, float directionXY, float directionZ, float speed, string color);
	Boid(int id, float* _position, float directionXY, float directionZ, float speed, string color);
	virtual ~Boid();

	//bool areNeighbors(Boid *boid1, Boid *boid2);

	int numeroCase[3];
	float position[3];

	float getX();
	float getY();
	float getZ();

	float* move(vector <Boid*> boids); //computes new position

	float distance(Boid *boid1, Boid *boid2); //distance between 2 boid

	double distance_to_pos(double x, double y, double z); //distance between two points

	void flocking(vector <Boid*> boids);
	void separation(vector <Boid*> boids, double sepX, double sepY, double sepZ, double sepCount);
	void cohesion(vector <Boid*> boids, double cohX, double cohY, double cohZ, double cohCount);
	void alignment(vector <Boid*> boids, double alignX, double alignY, double alignZ, double alignCount);

	double dirX();
	double dirY();
	double dirZ();

	double getDX();
	double getDY();
	double getDZ();

	int getId();

	double getDir(); //returns the direction of the boid
	double getVel(); //returns the speed

	void wall_bounce();

	void setColor(string color);
	string getColor();

	int* getNumeroCase(){ return numeroCase; }
	void setNumeroCase(int _numeroCase[3]){
		for (int numCase = 0; numCase<sizeof(numeroCase) / sizeof(int); numCase++){
			numeroCase[numCase] = _numeroCase[numCase];
		}
	}

	float* getPosition(){ return position; }
	void setPosition(float newPosition[3]){
		for (int pos = 0; pos<sizeof(position); pos++){
			position[pos] = newPosition[pos];
		}
	}

private:
	float _x, _y, _z;
	float _directionXY, _directionZ;
	int _id;
	float _speed;
	string _color;
	double _newDX, _newDY, _newDZ;
};

#endif /* BOID_H_ */
