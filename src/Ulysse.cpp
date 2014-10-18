//============================================================================
// Name        : 0.cpp
// Author      : ifig
// Version     :
// Copyright   : copyright Ulysse team
// Description : Ulysse code in C++
//============================================================================

#include "Boid.h"
#include <iostream>
//#include <GL/GL.h>	//to remove on Windows
//#include <GL/GLU.h>	//to remove on Windows
#include <GL/glut.h>
#include "stdio.h"
#include "math.h"
#include <random>
#include <ctime>
#include "Includes.h"

#include <iostream>
#include <vector>

using namespace std;

vector<Boid*> boids;


void myInit (void)
{
	 glClearColor(1.0,1.0,1.0,0.0); // sets background color to white
	 glColor3f(0.0f,0.0f,0.0f); // setsthe drawing colour
	 glPointSize(2.0); // sets a point to be 4x4 pixels
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluOrtho2D(0.0, 500.0, 0.0, 400.0); // the display area in world coordinates.
}


void display()
{
	 glClear(GL_COLOR_BUFFER_BIT); // clears the screen
	 glBegin(GL_POINTS);
	 for (int i = 0; i < boids.size(); i++)
	 {
		 if (boids[i]->getColor()=="red")
		 {
			 glColor3f(1.0f,0.0f,0.0f);
		 }
		 else
			 glColor3f(0.0,0.0,0.0);
		 glVertex2i (boids[i]->getX(), boids[i]->getY());
	 }
	 glEnd();
	 glFlush(); // sends all output to display;
	 glutSwapBuffers();
}

void run(int value)
{
	srand(time(NULL));

	/*vector<Boid*> boidsTmp = boids;

	while (boidsTmp.size() != 0){
		int i = rand() % boidsTmp.size();
		boids[i]->move(boids);
		boidsTmp.erase(boidsTmp.begin() + i);
	}*/
	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->move(boids);
	}
    glutPostRedisplay();
    glutTimerFunc(10, run, 1);
}


int main (int argc, char **argv)
{
	glutInit (&argc, argv); // to initialize the toolkit;
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // sets the display mode
	glutInitWindowSize (1200, 700); // sets the window size
	glutInitWindowPosition (20, 50); // sets the starting position for the window
	glutCreateWindow ("Ulysse"); // creates the window and sets the title
    //glutFullScreen();           // making the window full screen
	myInit(); // additional initializations as necessary
	glClear(GL_COLOR_BUFFER_BIT); // clears the screen

	glutDisplayFunc(display);

	//Initalise Boids
	int spawn_count = 500; //number of boids

	for (int i = 0; i < spawn_count; i++)
	{
		//random positionning
		float x = rand()%500;
		float y = rand()%400;
		cout << "x : " << x;
		cout << " y : " << y << endl;

		//Boid(int id, float x, float y, float direction, float speed, string color)
		double pi = atan(1)*4;
		float angle = rand()%(360);
		angle = angle/180 *pi;
		float speed = (rand()%10+1);
		float col = rand()%2;
		string couleur;
		if (col==1)
			couleur = "black";
		else
			couleur = "red";
		boids.push_back(new Boid(i, x, y, angle, 5, couleur));
	}
	run(1);

	cout << "initialize finished" << endl;

	glutMainLoop(); // go into a loop until event occurs
	return 0;
}
