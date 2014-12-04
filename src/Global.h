/*
* Global.h
*
*  Created on: 2014
*      Author: kristen
*/
#pragma once

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
//#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include <libpng/png.h>

#include <math.h>
#include <ctime>
#include <exception>
#include <iostream>
#include <list>
#include <random>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

// Size Screen
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 700
#define SCREEN_POSITION_X 50
#define SCREEN_POSITION_Y 50

// max position for a boid
#define MAX_X 500
#define MAX_Y 400
#define MAX_Z 400

// define a cube of X*X*X
#define CUBE_SIZE 1

// number of boids
#define SPAWN_COUNT 500

// Force of boid's rules 
#define SEPARATION 0.09
#define COHESION 0.28
#define ALIGNEMENT 0.1

//radius of boid
#define RADIUS_SEPARATION 40
#define RADIUS_COHESION 120

#define PI atan(1) * 4

extern float camX, camY, camZ;
extern float vecDirX, vecDirY, vecDirZ;
