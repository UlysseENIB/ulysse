/*
* DataBaseResource.cpp
*
*  Created on: 2014
*      Author: kristen
*/
#include "DataBaseResources.h"


DataBaseResource::DataBaseResource()
{
	_listByKeyword = new std::vector<KeywordStruct*>();
	_listById = new std::vector<EnfantStruct*>();
}

// add one boid in the list of keywords
void DataBaseResource::addBoidInListKeyword(string keyword, Boid* boid){
	KeywordStruct* findInList = findByKeyword(keyword);
	if (findInList == NULL){
		KeywordStruct* newKeyWord = new KeywordStruct(keyword, boid);
		_listByKeyword->push_back(newKeyWord);
	}
	else{
		findInList->_listBoids->push_back(boid);
	}
}

void DataBaseResource::addBoidInListIdEnfant(int id, Boid* boid){
	EnfantStruct* findInList = findByIdEnfant(id);
	if (findInList == NULL){
		EnfantStruct* newId = new EnfantStruct(id, boid);
		_listById->push_back(newId);
	}
	else{
		findInList->_listBoids->push_back(boid);
	}
}

// get the list of boids associate to one keyword (type : struct KeywordStruct)
std::vector<Boid*>* DataBaseResource::getBoidByKeyword(string keyword){
	KeywordStruct* findInList = findByKeyword(keyword);
	if (findInList == NULL){
		return NULL;
	}
	else{
		return findInList->_listBoids;
	}
}

std::vector<Boid*>* DataBaseResource::getBoidByIdEnfant(int id){
	EnfantStruct* findInList = findByIdEnfant(id);
	if (findInList == NULL){
		return NULL;
	}
	else{
		return findInList->_listBoids;
	}
}

// find the structure by the keyword
KeywordStruct* DataBaseResource::findByKeyword(string keyword){
	for (int i = _listByKeyword->size() - 1; i >= 0; i--){
		if (_listByKeyword->at(i)->_value == keyword){
			return _listByKeyword->at(i);
		}
	}
	return NULL;
}

EnfantStruct* DataBaseResource::findByIdEnfant(int id){
	for (int i = _listById->size() - 1; i >= 0; i--){
		if (_listById->at(i)->_value == id){
			return _listById->at(i);
		}
	}
	return NULL;
}