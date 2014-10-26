//
//  grid.cpp
//  boids
//
//  Created by guillaume Kermarrec on 08/10/2014.
//  Copyright (c) 2014 guillaume Kermarrec. All rights reserved.
//

#include "grid.h"
#include <math.h>
#include <thread>

using namespace std;

void Grid::createGrid(int nbCase, bool randomGeneration){
	setNbCase(nbCase);
	boidsParCases_vector = new std::vector<Boid*>();
	BoidsX = new std::vector< std::vector<Boid*> *>();
	BoidsXY = new std::vector< std::vector< std::vector<Boid*> *> *>();
	BoidsXYZ = new std::vector< std::vector< std::vector< std::vector<Boid*> *> *> *>();
	generateList(nbCase, nbCase, nbCase, randomGeneration);
}

/**
* Cr»ation d'une grille avec un nomber bnbLigne de ligne et nbColonne de colonne
* Les boids sont par la suite al»atoirement r»partis dans l'espace
*/
void Grid::generateList(int nbLigne, int nbColonne, int nbRang, bool randomGeneration){

	std::vector<Boid*> *_boidsParCases_vector;
	std::vector< std::vector<Boid*> *> *_BoidsX_vector;
	std::vector< std::vector< std::vector<Boid*> *> *> *_BoidsXY_vector;
	long int id = 0;
	float pi = (float) atan(1) * 4;
	for (int boidsNumberRang = 0; boidsNumberRang<nbRang; boidsNumberRang++) {
		_BoidsXY_vector = new std::vector< std::vector< std::vector<Boid*> *> *>();
		for (int boidsNumberColonne = 0; boidsNumberColonne<nbColonne; boidsNumberColonne++) {
			_BoidsX_vector = new std::vector< std::vector<Boid*> *>();
			for (int boidsNumberLigne = 0; boidsNumberLigne<nbLigne; boidsNumberLigne++) {
				_boidsParCases_vector = new std::vector<Boid*>();
				for (int boidsNumberCase = 0; boidsNumberCase <= rand() % 20; boidsNumberCase++) {
					if (randomGeneration){
						float _position[3] = { static_cast<float>(rand() % 500), static_cast<float>(rand() % 400), static_cast<float>(rand() % 400) };
						int col = rand() % 2;
						string couleur;
						if (col == 1)
							couleur = "black";
						else
							couleur = "red";

						float angleXY =  rand() % 360;
						angleXY = angleXY / 180 * pi;

						float angleZ = 0;
						int* _positionCase = determinerCase(_position);
						boids = new Boid(id, _position, _positionCase, angleXY, angleZ, 5, couleur);
						id++;
						_boidsParCases_vector->emplace(_boidsParCases_vector->end(), boids);
					}
				}
				_BoidsX_vector->emplace(_BoidsX_vector->end(), _boidsParCases_vector);
			}
			_BoidsXY_vector->emplace(_BoidsXY_vector->end(), _BoidsX_vector);
		}
		BoidsXYZ->emplace(BoidsXYZ->end(), _BoidsXY_vector);
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
	std::vector<Boid*> *_boidsParCases_vector = BoidsXYZ->at(_numCase[0])->at(_numCase[1])->at(_numCase[2]);
	_boidsParCases_vector->emplace(_boidsParCases_vector->begin(), boids);
}

void Grid::updateOnGrid(Boid *boids, float* position, int caseActuelle[3]){
		int* _numCase = determinerCase(position);
	
		std::vector<Boid*> *_boidsParCases_vectorDelete = BoidsXYZ->at(caseActuelle[0])->at(caseActuelle[1])->at(caseActuelle[2]);
	
			std::vector<Boid*> *_boidsParCases_vectorNew = BoidsXYZ->at(_numCase[0])->at(_numCase[1])->at(_numCase[2]);
	
	if (_numCase[0] == caseActuelle[0] && _numCase[1] == caseActuelle[1] && _numCase[2] == caseActuelle[2])
	{
		boids->setPosition(position);
	}
	else{
		//Update la donnÈe
		for (unsigned int numberBoids = 0; numberBoids<_boidsParCases_vectorDelete->size(); numberBoids++) {
			if (_boidsParCases_vectorDelete->at(numberBoids)->getId() == boids->getId()){
				_boidsParCases_vectorDelete->erase(_boidsParCases_vectorDelete->begin() + numberBoids);
				_boidsParCases_vectorNew->emplace(_boidsParCases_vectorNew->begin(), boids);
				break;
			}
		}
	}
}

void Grid::updateNumeroCase(Boid *boids, int numCase[3]){
	boids->setNumeroCase(numCase);
}

void Grid::updateOnGrid(){
	for (unsigned int i = 0; i <= BoidsXYZ->size() - 1; i++) {
		for (unsigned int j = 0; j<BoidsXYZ->at(i)->size() - 1; j++) {
			for (unsigned int k = 0; k<BoidsXYZ->at(i)->at(j)->size() - 1; k++) {
				for (long int l = BoidsXYZ->at(i)->at(j)->at(k)->size() - 1; l >= 0; l--) {
					try {
						updateOnGrid(BoidsXYZ->at(i)->at(j)->at(k)->at(l));
						BoidsXYZ->at(i)->at(j)->at(k)->erase(BoidsXYZ->at(i)->at(j)->at(k)->begin() + l);
					}
					catch (std::out_of_range err) {
						printf("ATTENTION -- no value here\n");
					}
				}
			}
		}
	}

}