//
//  grid.h
//  boids
//
//  Created by guillaume Kermarrec on 08/10/2014.
//  Copyright (c) 2014 guillaume Kermarrec. All rights reserved.
//

#pragma once


#include "Boid.h"
#include "Global.h"

class Grid {

private:
	int tailleCube = max(max(MAX_X,MAX_Y),MAX_Z)+10;// max size position To change in function of the size of the screen
	int nbCaseGrid;
	Boid *boids;

	std::vector<Boid*> *boidsParCases_vector{};
	std::vector< std::vector<Boid*> *> *boidsX{};
	std::vector< std::vector< std::vector<Boid*> *> *> *boidsXY{};

	int *positionInt = new int[3];
	std::vector<Boid*> *boidsNeighbors{};

	void generateList(int nbLigne, int nbColonne, int nbRang, bool randomGeneration = false);

	// Permet de mettre a jour la position dans la grille d'un seul boids.
	void updateOnGrid(Boid *boids);

public:
	std::vector< std::vector< std::vector< std::vector<Boid*> *> *> *> *boidsXYZ{};
	std::vector< std::vector< std::vector< std::vector<Boid*> *> *> *> getAllGrid(){ return *boidsXYZ; }

	std::vector<Boid*> *getNeighbors(int numCase[3]);
	Boid* findBoidById(long int id);

	int* determinerCase(float* position);

	// Permet de mettre a jour la position d'un seul boids. Necessite la future position du boids
	void updateOnGrid(Boid *boids, float* position, int positionActuelleCase[3]);

	//  La fonction updateOnGrid permet de mettre a jour la grille dans sa totalite.
	void updateOnGrid();

	//  Pour creer unr grille appeler la fonction createGrid.
	void createGrid(int nbCase, bool randomGeneration = false);
	void setNbCase(int nbCase){ nbCaseGrid = nbCase; }

	// Permet d'ajouter un nouvelle objet boids dans la grille. Il sera place en fonction de ses coordonnees
	void addToGrid(Boid *boids);
};