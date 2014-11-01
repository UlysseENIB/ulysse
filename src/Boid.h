/*
* Boid.h
*
*  Created on: 1 oct. 2014
*      Author: ifig
*/
#ifndef BOID_H_
#define BOID_H_

//#include "Behavior.h"
#include "Global.h"

class Boid {

private:
	long int _id;
	int _numeroCase[3];
	float _position[3];
	float _speed;
	float _directionXY, _directionZ;
	// to delete --
	string _color;
	// --
public:
	Boid(long int id, float* position, int* nCase, float directionXY, float directionZ, float speed, string color);
	virtual ~Boid();

	float* move(vector <Boid*> *boids); //computes new position

	float getDistance(Boid *boid1, Boid *boid2); //distance between 2 boid
	float distance_to_pos(float x, float y, float z); //distance between two points

	float dirX();
	float dirY();
	float dirZ();

	float getX(){ return _position[0]; }
	float getY(){ return _position[1]; }
	float getZ(){ return _position[2]; }

	
	float getDirectionXY(){ return _directionXY; }
	void setDirectionXY(float direction){ _directionXY = direction; }
	float getDirectionZ(){ return _directionZ; }
	void setDirectionZ(float direction){ _directionZ = direction; }
	float getSpeed(){ return _speed; }
	int getId(){ return _id; }

	//float getDir(); //returns the direction of the boid
	//float getVel(); //returns the speed

	// to delete--
	void setColor(string color){ _color = color; };
	string getColor(){ return _color;}
	//--
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