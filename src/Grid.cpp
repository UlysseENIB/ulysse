//
//  grid.cpp
//  boids
//
//  Created by guillaume Kermarrec on 08/10/2014.
//  Copyright (c) 2014 guillaume Kermarrec. All rights reserved.
//

#include "Grid.h"

void Grid::createGrid(int nbCase, bool randomGeneration){
	setNbCase(nbCase);
	boidsParCases_vector = new std::vector<Boid*>();
	boidsX = new std::vector< std::vector<Boid*> *>();
	boidsXY = new std::vector< std::vector< std::vector<Boid*> *> *>();
	boidsXYZ = new std::vector< std::vector< std::vector< std::vector<Boid*> *> *> *>();
	boidsNeighbors = new std::vector<Boid*>();
	generateList(nbCase, nbCase, nbCase, randomGeneration);
}

/**
* Cr�ation d'une grille avec un nomber nbLigne de ligne et nbColonne de colonne
* Les boids sont par la suite al�atoirement r�partis dans l'espace
*/
void Grid::generateList(int nbLigne, int nbColonne, int nbRang, bool randomGeneration){

	std::vector<Boid*> *_boidsParCases_vector;
	std::vector< std::vector<Boid*> *> *_boidsX_vector;
	std::vector< std::vector< std::vector<Boid*> *> *> *_boidsXY_vector;
	long int id = 0;
	for (int boidsNumberRang = 0; boidsNumberRang<nbRang; boidsNumberRang++) {
		_boidsXY_vector = new std::vector< std::vector< std::vector<Boid*> *> *>();
		for (int boidsNumberColonne = 0; boidsNumberColonne<nbColonne; boidsNumberColonne++) {
			_boidsX_vector = new std::vector< std::vector<Boid*> *>();
			for (int boidsNumberLigne = 0; boidsNumberLigne<nbLigne; boidsNumberLigne++) {
				_boidsParCases_vector = new std::vector<Boid*>();
				//if (randomGeneration){
				//	//
				//	// TO CHANGE : MISS POSITION Z
				//	//
				//	for (int boidsNumberCase = 0; boidsNumberCase <= rand() % 20; boidsNumberCase++) {
				//	
				//		float _position[3] = { static_cast<float>(rand() % 500), static_cast<float>(rand() % 400), static_cast<float>(rand() % 400) };
				//		int col = rand() % 2;
				//		string couleur;
				//		if (col == 1)
				//			couleur = "black";
				//		else
				//			couleur = "red";

				//		float angleXY =  rand() % 360;
				//		angleXY = angleXY / 180 * PI;

				//		float angleZ = 0;
				//		boids = new Boid(id, _position, angleXY, angleZ, 5, couleur);
				//		id++;
				//		_boidsParCases_vector->emplace(_boidsParCases_vector->end(), boids);
				//	}
				//}
				_boidsX_vector->emplace(_boidsX_vector->end(), _boidsParCases_vector);
			}
			_boidsXY_vector->emplace(_boidsXY_vector->end(), _boidsX_vector);
		}
		boidsXYZ->emplace(boidsXYZ->end(), _boidsXY_vector);
	}
	if (randomGeneration) updateOnGrid();
}

int* Grid::determinerCase(float* position){
	positionInt[0] = (int)(position[0] / tailleCube * nbCaseGrid);
	positionInt[1] = (int)(position[1] / tailleCube * nbCaseGrid);
	positionInt[2] = (int)(position[2] / tailleCube * nbCaseGrid);
	return positionInt;
}

void Grid::addToGrid(Boid *boids){
	updateOnGrid(boids);
}

void Grid::updateOnGrid(Boid *boids){

	int* _numCase = determinerCase(boids->getPosition());
	std::vector<Boid*> *_boidsParCases_vector = boidsXYZ->at(_numCase[0])->at(_numCase[1])->at(_numCase[2]);
	_boidsParCases_vector->emplace(_boidsParCases_vector->begin(), boids);
}

void Grid::updateOnGrid(Boid *boids, float* position, int caseActuelle[3]){
	int* _numCase = determinerCase(position);
	
	std::vector<Boid*> *_boidsParCases_vectorDelete = boidsXYZ->at(caseActuelle[0])->at(caseActuelle[1])->at(caseActuelle[2]);
	std::vector<Boid*> *_boidsParCases_vectorNew = boidsXYZ->at(_numCase[0])->at(_numCase[1])->at(_numCase[2]);
	
	if (_numCase[0] == caseActuelle[0] && _numCase[1] == caseActuelle[1] && _numCase[2] == caseActuelle[2])
	{
		boids->setPosition(position);
	}
	else{
		//Update la donn�e
		for (unsigned int numberBoids = 0; numberBoids<_boidsParCases_vectorDelete->size(); numberBoids++) {
			if (_boidsParCases_vectorDelete->at(numberBoids)->getId() == boids->getId()){
				_boidsParCases_vectorDelete->erase(_boidsParCases_vectorDelete->begin() + numberBoids);
				_boidsParCases_vectorNew->emplace(_boidsParCases_vectorNew->begin(), boids);
				break;
			}
		}
	}
}

std::vector<Boid*> *Grid::getNeighbors(int numCase[3]){
	boidsNeighbors->clear();
	for (int i = -1; i <= 1; i++) {
		if (!(i == -1 && numCase[0] <= 0) && !(i == 1 && numCase[0] >= nbCaseGrid - 1)){
			for (int j = -1; j <= 1; j++) {
				if (!(j == -1 && numCase[1] <= 0) && !(j == 1 && numCase[1] >= nbCaseGrid - 1)){
					for (int k = -1; k <= 1; k++) {
						if (!(k == -1 && numCase[2] <= 0) && !(k == 1 && numCase[2] >= nbCaseGrid - 1))
							boidsNeighbors->insert(boidsNeighbors->end(), boidsXYZ->at(numCase[0] + i)->at(numCase[1] + j)->at(numCase[2] + k)->begin(), boidsXYZ->at(numCase[0] + i)->at(numCase[1] + j)->at(numCase[2] + k)->end());
					}
				}
			}
		}
	}
	return boidsNeighbors;
}

Boid* Grid::findBoidById(long int id){
	for (unsigned int i = 0; i <= boidsXYZ->size() - 1; i++) {
		for (unsigned int j = 0; j <= boidsXYZ->at(i)->size() - 1; j++) {
			for (unsigned int k = 0; k <= boidsXYZ->at(i)->at(j)->size() - 1; k++) {
				for (long int l = boidsXYZ->at(i)->at(j)->at(k)->size() - 1; l >= 0; l--) {
					if (boidsXYZ->at(i)->at(j)->at(k)->at(l)->getId() == id){
						return boidsXYZ->at(i)->at(j)->at(k)->at(l);
					}
				}
			}
		}
	}
	return NULL;
}

void Grid::updateOnGrid(){
	for (unsigned int i = 0; i <= boidsXYZ->size() - 1; i++) {
		for (unsigned int j = 0; j<= boidsXYZ->at(i)->size() - 1; j++) {
			for (unsigned int k = 0; k<= boidsXYZ->at(i)->at(j)->size() - 1; k++) {
				for (long int l = boidsXYZ->at(i)->at(j)->at(k)->size() - 1; l >= 0; l--) {
					try {
						updateOnGrid(boidsXYZ->at(i)->at(j)->at(k)->at(l));
						boidsXYZ->at(i)->at(j)->at(k)->erase(boidsXYZ->at(i)->at(j)->at(k)->begin() + l);
					}
					catch (std::out_of_range err) {
						printf("ATTENTION -- no value here\n");
					}
				}
			}
		}
	}
}
