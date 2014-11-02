/*
* DataBaseResource.h
*
*  Created on: 2014
*      Author: kristen
*
* class DataBaseResource
* 
* This class is use to stock one list of keywords and 
* each keyword contain one list boid with this keyword
*
*
*/
#pragma once
#include "Boid.h"
#include "Global.h"


/*
* struct KeywordStruct
* 
* This structure associate one keyword to one list of Boids
*
*/
struct KeywordStruct
{
	KeywordStruct::KeywordStruct(string value, Boid* boid){
		_listBoids = new std::vector<Boid*>();
		_value = value;
		_listBoids->push_back(boid);
	}
	// the value of the keyword
	string _value;
	// list of boids associate to the keyword "string value"
	std::vector<Boid*> *_listBoids{};
};

class DataBaseResource
{
public:
	DataBaseResource();

	// add one boid in the list of keywords
	void addBoidInListKeyword(string keyword, Boid* boid);
	// get the list of boids associate to one keyword (type : struct KeywordStruct)
	std::vector<Boid*>* getBoidByKeyword(string keyword);

private:
	// the list of keywords (type : struct KeywordStruct)
	std::vector<KeywordStruct*> *_listByKeyword{};

	// find the structure by the keyword
	KeywordStruct* findByKeyword(string keyword);
};
