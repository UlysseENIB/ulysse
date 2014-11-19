/*
* Boid.h
*
*  Created on: 1 oct. 2014
*      Author: ifig
*/
#pragma once

//#include "Behavior.h"
#include "Global.h"

class Boid {

private:
	long int _id;
	string _name;
	string _url;
	string _description;
	GLuint _picture;
	string _lieu;
	float _gps[2];			// MAYBE
	string _epoque;			// MAYBE
	std::vector<string> _keyword;
	int _idParent;
	std::vector<int> _idEnfant;

	float _position[3];
	float _speed;
	float _directionXY, _directionZ;
	// to delete --
	string _color;
	// --
public:
	Boid(long int id, string name, string url, string description, GLuint picture);
	virtual ~Boid();

	float* move(vector <Boid*> *boids); //computes new position

	float getDistance(Boid *boid1, Boid *boid2); //distance between 2 boid
	float distance_to_pos(float x, float y, float z); //distance between two points

	float dirX();
	float dirY();
	float dirZ();
	
	int getId(){ return _id; }
	string getName(){ return _name; }
	string getUrl(){ return _url; }
	string getDescription(){ return _description; }
	GLuint getPicture(){ return _picture; }
	string getLieu(){ return _lieu; }
	void setLieu(string lieu){ _lieu = lieu; }
	float* getGPS(){ return _gps; }
	void setGPS(float latitude, float longitude){
		_gps[0] = latitude;
		_gps[1] = longitude;
	}
	string getEpoque(){ return _epoque; }
	void setEpoque(string epoque){ _epoque = epoque; }

	vector<string> getKeyword(){ return _keyword; }
	void addKeyword(string keyword){ _keyword.push_back(keyword); }

	int getIdParent(){ return _idParent; }
	void setIdParent(int idParent){ _idParent = idParent; }

	vector<int> getIdEnfant(){ return _idEnfant; }
	void addIdEnfant(int idEnfant){ _idEnfant.push_back(idEnfant); }



	float getDirectionXY(){ return _directionXY; }
	void setDirectionXY(float direction){ _directionXY = direction; }
	float getDirectionZ(){ return _directionZ; }
	void setDirectionZ(float direction){ _directionZ = direction; }
	float getSpeed(){ return _speed; }
	void setSpeed(float speed){ _speed = speed; }

	// to delete--
	void setColor(string color){ _color = color; };
	string getColor(){ return _color;}
	//--

	float getX(){ return _position[0]; }
	float getY(){ return _position[1]; }
	float getZ(){ return _position[2]; }

	float* getPosition(){ return _position; }
	void setPosition(float newPosition[3]){
		for (int pos = 0; pos<3; pos++){
			_position[pos] = newPosition[pos];
		}
	}

};