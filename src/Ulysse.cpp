//============================================================================
// Name        : Ulysse.cpp
// Author      : ifig
// Version     :
// Copyright   : copyright Ulysse team
// Description : Ulysse code in C++
//============================================================================

#include "Boid.h"
#include "Grid.h"
#include "Parser.h"
#include "Global.h"


vector<Boid*> boids;

Grid grid;
Parser parser;

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // sets background color to white
	glColor3f(0.0f, 0.0f, 0.0f); // setsthe drawing colour
	glPointSize(5.0); // sets a point to be 4x4 pixels
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, MAX_X, 0.0, MAX_Y); // the display area in world coordinates.
	//gluPerspective(50.0, (float) 1200 / 700, 1, 1024);
	//gluLookAt(0, 0, 400, 0, 0, 0, 0.0, 1.0, 0.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT); // clears the screen
	glBegin(GL_POINTS);

	std::vector< std::vector< std::vector< std::vector<Boid*> *> *> *> boidsXYZ = grid.getAllGrid();
	for (unsigned int i = 0; i <= boidsXYZ.size() - 1; i++) {
		for (unsigned int j = 0; j <= boidsXYZ.at(i)->size() - 1; j++) {
			for (unsigned int k = 0; k <= boidsXYZ.at(i)->at(j)->size() - 1; k++) {
				long int size = boidsXYZ.at(i)->at(j)->at(k)->size();
				for (long int l = size - 1; l >= 0; l--) {
					if (boidsXYZ.at(i)->at(j)->at(k)->at(l)->getColor() == "red") glColor3f(1.0f, 0.0f, 0.0f);
					else glColor3f(0.0, 0.0, 0.0);
					float* _position = boidsXYZ.at(i)->at(j)->at(k)->at(l)->getPosition();
					glVertex3i(_position[0], _position[1], _position[2]);
				}
			}
		}
	}
	glEnd();
	glFlush(); // sends all output to display;
	glutSwapBuffers();
}

void run(int value)
{
	srand(time(NULL));
	std::vector< std::vector< std::vector< std::vector<Boid*> *> *> *> boidsXYZ = grid.getAllGrid();
	vector <Boid*>* boidNeighbor;
	for (unsigned int i = 0; i <= boidsXYZ.size() - 1; i++) {
		for (unsigned int j = 0; j <= boidsXYZ.at(i)->size() - 1; j++) {
			for (unsigned int k = 0; k <= boidsXYZ.at(i)->at(j)->size() - 1; k++) {
				int l = boidsXYZ.at(i)->at(j)->at(k)->size() - 1;
				if (l >= 0){
					int _positionActuelleCase[3] = { i, j, k };
					boidNeighbor = grid.getNeighbors(_positionActuelleCase);
					for (l; l >= 0; l--) {
						grid.updateOnGrid(boidsXYZ.at(i)->at(j)->at(k)->at(l), boidsXYZ.at(i)->at(j)->at(k)->at(l)->move(boidNeighbor), _positionActuelleCase);
					}
				}
			}
		}
	}
	glutPostRedisplay();
	glutTimerFunc(10, run, 1);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv); // to initialize the toolkit;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // sets the display mode
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT); // sets the window size
	glutInitWindowPosition(SCREEN_POSITION_X, SCREEN_POSITION_Y); // sets the starting position for the window
	glutCreateWindow("Ulysse"); // creates the window and sets the title
	//glutFullScreen();           // making the window full screen
	myInit(); // additional initializations as necessary
	glClear(GL_COLOR_BUFFER_BIT); // clears the screen

	glutDisplayFunc(display);

	// Creation d'une grille. Cube de 10 de cote. Ajouter randomGeneration=true pour g»n»rer automatiquement une grille
	grid.createGrid(CUBE_SIZE);

	// Parse file xml
	(argv[1] != NULL) ? parser.parse(argv[1]) : parser.parse("res\\data\\Ulysse.xml");
	//parse("res\\data\\Ulysse.xml");
	
	Boid *boids;
	for (int i = 0; i < SPAWN_COUNT; i++)
	{
		//random positionning
		float x = static_cast<float>(rand() % MAX_X);
		float y = static_cast<float>(rand() % MAX_Y);
		//float z = static_cast<float>(rand() % MAX_Z);
		float z = 0;

		float angleXY = rand() % (360);
		angleXY = angleXY / 180 * PI;
		//float angleZ = rand() % (360) / 180 * pi;
		float angleZ = 0;
		float speed = (rand() % 10 + 1);
		float col = rand() % 2;
		string couleur;
		if (col == 1) couleur = "black";
		else couleur = "red";

		float _position[3] = { x, y, z };
		boids = new Boid(i, _position, angleXY, angleZ, 5, couleur);
		grid.addToGrid(boids);
	}
	run(1);

	cout << "initialize finished" << endl;

	glutMainLoop(); // go into a loop until event occurs
	return 0;
}