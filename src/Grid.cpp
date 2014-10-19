//
//  grid.cpp
//  boids
//
//  Created by guillaume Kermarrec on 08/10/2014.
//  Copyright (c) 2014 guillaume Kermarrec. All rights reserved.
//

#include "grid.h"
#include <math.h>

void Grid::createGrid(int nbCase, bool randomGeneration){
	BoidsX.reserve(nbCase); BoidsXY.reserve(nbCase); BoidsXYZ.reserve(nbCase);
	generateList(nbCase, nbCase, nbCase, randomGeneration);
}

/**
* Cr»ation d'une grille avec un nomber bnbLigne de ligne et nbColonne de colonne
* Les boids sont par la suite al»atoirement r»partis dans l'espace
*/
void Grid::generateList(int nbLigne, int nbColonne, int nbRang, bool randomGeneration){

	std::vector<Boid*> _boidsParCases_vector;
	std::vector< std::vector<Boid*> > _BoidsX_vector;
	std::vector< std::vector< std::vector<Boid*> > > _BoidsXY_vector;
	long int id = 0;
	double pi = atan(1) * 4;
	for (int boidsNumberRang = 0; boidsNumberRang<nbRang; boidsNumberRang++) {

		for (int boidsNumberColonne = 0; boidsNumberColonne<nbColonne; boidsNumberColonne++) {

			for (int boidsNumberLigne = 0; boidsNumberLigne<nbLigne; boidsNumberLigne++) {

				for (int boidsNumberCase = 0; boidsNumberCase <= rand() % 20; boidsNumberCase++) {
					//float _position[3] = { static_cast<float>(rand() % 100), static_cast<float>(rand() % 100), static_cast<float>(rand() % 100) };
					//random positionning
					float x = rand() % 500;
					float y = rand() % 400;
					//float z = rand() % 400;
					float z = 0;
					// ajout al»atoire des boids
					if (randomGeneration){
						float col = rand() % 2;
						string couleur;
						if (col == 1)
							couleur = "black";
						else
							couleur = "red";

						float angleXY = rand() % (360);
						angleXY = angleXY / 180 * pi;
						//float angleZ = rand() % (360) / 180 * pi;
						float angleZ = 0;

						boids = new Boid(id, x, y, z, angleXY, angleZ, 5, couleur);
						id++;
						_boidsParCases_vector.push_back(boids);
					}

				}
				_BoidsX_vector.push_back(_boidsParCases_vector);
				_boidsParCases_vector.clear();
			}
			_BoidsXY_vector.push_back(_BoidsX_vector);
			_BoidsX_vector.clear();
		}
		BoidsXYZ.push_back(_BoidsXY_vector);
		_BoidsXY_vector.clear();
	}
	if (randomGeneration) updateOnGrid();
}

int* Grid::determinerCase(float* position){
	int *positionInt = new int[3];
	positionInt[0] = (int)(position[0] / (float)tailleCube);
	positionInt[1] = (int)(position[1] / (float)tailleCube);
	positionInt[2] = (int)(position[2] / (float)tailleCube);
	return positionInt;
}

void Grid::addToGrid(Boid *boids){
	updateOnGrid(boids);
}

void Grid::eraseData(int* positionToErase){
	if (BoidsX.size() != 0)BoidsX.erase(BoidsX.begin() + positionToErase[2]);
	if (BoidsXY.size() != 0)BoidsXY.erase(BoidsXY.begin() + positionToErase[1]);
	if (BoidsXYZ.size() != 0)BoidsXYZ.erase(BoidsXYZ.begin() + positionToErase[0]);
}

void Grid::eraseElement(long int id, int* positionToErase){
	BoidsXY = BoidsXYZ.at(positionToErase[0]);
	BoidsX = BoidsXY.at(positionToErase[1]);
	boidsParCases_vector = BoidsX.at(positionToErase[2]);

	std::vector<Boid*> _boidsParCases_vector = BoidsXYZ.at(positionToErase[0]).at(positionToErase[1]).at(positionToErase[2]);
	for (int numberBoids = 0; numberBoids<boidsParCases_vector.size() - 1; numberBoids++) {
		if (_boidsParCases_vector.at(numberBoids)->getId() == id){
			_boidsParCases_vector.erase(_boidsParCases_vector.begin() + numberBoids);
			break;
		}
	}
	eraseData(positionToErase);
	BoidsX.insert(BoidsX.begin() + positionToErase[2], _boidsParCases_vector);
	BoidsXY.insert(BoidsXY.begin() + positionToErase[1], BoidsX);
	BoidsXYZ.insert(BoidsXYZ.begin() + positionToErase[0], BoidsXY);
}

void Grid::updateOnGrid(Boid *boids, float position[3]){
	initializeVector();
	eraseElement(boids->getId(), boids->getNumeroCase());
	boids->setPosition(position);
	updateOnGrid(boids);
}

void Grid::updateOnGrid(Boid *boids){
	// Permet de connaitre la case sur laquelle il se situe
	float* tmp_boidsPosition = boids->getPosition();
	int* tmp_case_position = determinerCase(tmp_boidsPosition);
	int caseValue[3] = { tmp_case_position[0], tmp_case_position[1], tmp_case_position[2] };

	updateNumeroCase(boids, caseValue);

	printf("position -> %f - %f - %f -- going to -> %i - %i - %i\n", boids->getPosition()[0], boids->getPosition()[1], boids->getPosition()[2], caseValue[0], caseValue[1], caseValue[2]);
	BoidsXY = BoidsXYZ.at(caseValue[0]);
	BoidsX = BoidsXY.at(caseValue[1]);
	boidsParCases_vector = BoidsX.at(caseValue[2]);

	boidsParCases_vector.push_back(boids);

	eraseData(caseValue);

	BoidsX.insert(BoidsX.begin() + caseValue[2], boidsParCases_vector);
	BoidsXY.insert(BoidsXY.begin() + caseValue[1], BoidsX);
	BoidsXYZ.insert(BoidsXYZ.begin() + caseValue[0], BoidsXY);
}

void Grid::initializeVector(){
	boidsParCases_vector.clear();
	BoidsX.clear();
	BoidsXY.clear();
}

void Grid::updateNumeroCase(Boid *boids, int numCase[3]){
	boids->setNumeroCase(numCase);
}

void Grid::updateOnGrid(){
	for (int i = 0; i <= BoidsXYZ.size() - 1; i++) {
		for (int j = 0; j<BoidsXYZ.at(i).size() - 1; j++) {
			for (int k = 0; k<BoidsXYZ.at(i).at(j).size() - 1; k++) {
				long int size = BoidsXYZ.at(i).at(j).at(k).size();
				for (long int l = size - 1; l >= 0; l--) {
					try {
						updateOnGrid(BoidsXYZ.at(i).at(j).at(k).at(l));
						printf("delete value in %i %i %i %li -- id-> %i\n", i, j, k, l, BoidsXYZ.at(i).at(j).at(k).at(l)->getId());
						BoidsXYZ.at(i).at(j).at(k).erase(BoidsXYZ.at(i).at(j).at(k).begin() + l);
					}
					catch (std::out_of_range err) {
						printf("ATTENTION -- no value here\n");
					}
				}
			}
		}
	}

}