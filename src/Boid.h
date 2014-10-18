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
#ifndef BOI_H_
#define BOI_H_

class Boid {

public:
	Boid(int id, float x, float y, float direction, float speed, string color);
	virtual ~Boid();

	//bool areNeighbors(Boid *boid1, Boid *boid2);

	void setPosition(float, float);
	float getX();
	float getY();

	void move(vector <Boid*> boids); //computes new position

	float distance(Boid *boid1, Boid *boid2); //distance between 2 boid

	double distance_to_pos(double x, double y); //distance between two points

	void flocking(vector <Boid*> boids);
	void separation(vector <Boid*> boids, double sepX, double sepY, double sepCount);
	void cohesion(vector <Boid*> boids, double cohX, double cohY, double cohCount);
	void alignment(vector <Boid*> boids, double alignX, double alignY, double alignCount);


	double dirX();
	double dirY();

	double getDX();
	double getDY();

	int getId();

	double getDir(); //returns the direction of the boid
	double getVel(); //returns the speed

	void wall_bounce();

	void setColor(string color);
	string getColor();

private:
	float _x, _y;
	float _direction;
	int _id;
	float _speed;
	string _color;
	double _newDX, _newDY;
};

#endif /* BOI_H_ */
