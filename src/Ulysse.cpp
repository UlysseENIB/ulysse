//============================================================================
// Name        : Ulysse.cpp
// Author      : ifig
// Version     :
// Copyright   : copyright Ulysse team
// Description : Ulysse code in C++
//============================================================================

#include "Boid.h"
#include "Grid.h"
#include "Global.h"

vector<Boid*> boids;

Grid grid;

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

	std::vector< std::vector< std::vector< std::vector<Boid*> *> *> *> BoidsXYZ = grid.getAllGrid();
	for (unsigned int i = 0; i <= BoidsXYZ.size() - 1; i++) {
		for (unsigned int j = 0; j <= BoidsXYZ.at(i)->size() - 1; j++) {
			for (unsigned int k = 0; k <= BoidsXYZ.at(i)->at(j)->size() - 1; k++) {
				long int size = BoidsXYZ.at(i)->at(j)->at(k)->size();
				for (long int l = size - 1; l >= 0; l--) {
					if (BoidsXYZ.at(i)->at(j)->at(k)->at(l)->getColor() == "red") glColor3f(1.0f, 0.0f, 0.0f);
					else glColor3f(0.0, 0.0, 0.0);
					float* _position = BoidsXYZ.at(i)->at(j)->at(k)->at(l)->getPosition();
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
	std::vector< std::vector< std::vector< std::vector<Boid*> *> *> *> BoidsXYZ = grid.getAllGrid();
	for (unsigned int i = 0; i <= BoidsXYZ.size() - 1; i++) {
		for (unsigned int j = 0; j <= BoidsXYZ.at(i)->size() - 1; j++) {
			for (unsigned int k = 0; k <= BoidsXYZ.at(i)->at(j)->size() - 1; k++) {
				for (long int l = BoidsXYZ.at(i)->at(j)->at(k)->size() - 1; l >= 0; l--) {
					int _positionActuelleCase[3] = { i, j, k };
					// Do Try and catch because with a lot of boids got some out_of_range_memory
					try{						
						grid.updateOnGrid(BoidsXYZ.at(i)->at(j)->at(k)->at(l), BoidsXYZ.at(i)->at(j)->at(k)->at(l)->move(grid.getNeighbors(_positionActuelleCase)), _positionActuelleCase);
					}
					catch (exception e){
						// DO NOTHING
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
	
	// Creation d'une grille. Cube de 10 de cote. Ajouter randomGeneration=true pour g�n�rer automatiquement une grille
	grid.createGrid(CUBE_SIZE);
	Boid *boids;
	for (int i = 0; i < SPAWN_COUNT; i++)
	{
		//random positionning
		float x = static_cast<float>(rand() % 500);
		float y = static_cast<float>(rand() % 500);
		//float z = static_cast<float>(rand() % 500);
		float z = 0;
		//        cout << "x : " << x;
		//        cout << " y : " << y;
		//        cout << " z : " << z << endl;

		//Boid(int id, float x, float y, float direction, float speed, string color)
		double pi = atan(1) * 4;
		float angleXY = rand() % (360);
		angleXY = angleXY / 180 * pi;
		//float angleZ = rand() % (360) / 180 * pi;
		float angleZ = 0;
		float speed = (rand() % 10 + 1);
		float col = rand() % 2;
		string couleur;
		if (col == 1) couleur = "black";
		else couleur = "red";

		float _position[3] = { x, y, z };
		int* _positionCase = grid.determinerCase(_position);
		boids = new Boid(i, _position, _positionCase, angleXY, angleZ, 5, couleur);
		grid.addToGrid(boids);
	}
	run(1);

	cout << "initialize finished" << endl;

	glutMainLoop(); // go into a loop until event occurs
	return 0;
}