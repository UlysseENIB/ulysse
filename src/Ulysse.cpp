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
#include "textureLoader.h"
#include "Camera.h"

void computePos(float deltaMove);

vector<Boid*> boids;

float angle = 0.0f;

// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f;

// XZ position of the camera
float x = 200.0f, a = 200.0f, z = 500.0f;


int xOrigin = -1;

Parser* parser = new Parser();
TextureLoader* textureLoader = new TextureLoader();
GLuint texId;

Camera* camera = new Camera();
//float camX, camY, camZ;

Camera g_camera;
bool g_key[256];
bool g_shift_down = false;
bool g_fps_mode = false;
int g_viewport_width = 0;
int g_viewport_height = 0;
bool g_mouse_left_down = false;
bool g_mouse_right_down = false;

// Movement settings
const float g_translation_speed = 10;
const float g_rotation_speed = PI/180*0.2;


//Rep�re du monde
void worldCoordinateSystem(int size)
{
	glBegin(GL_LINES);
	glVertex2i(0, 0);
	glVertex2i(0, size);
	glVertex2i(0, 0);
	glVertex2i(size, 0);
	glVertex2i(0, 0);
	glVertex3i(0, 0, size);
	glEnd();
}

void
display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//if (deltaMove)
	//	computePos(deltaMove);

	g_camera.Refresh();
	//gluLookAt(x, a, z,
	//	x + lx, a, z + lz,
	//	0.0f, 1.0f, 0.0f);

	//glColor3f(0,0,0);
	worldCoordinateSystem(500);


	//Draw boids
	std::vector< std::vector< std::vector< std::vector<Boid*> *> *> *> boidsXYZ = parser->grid.getAllGrid();
	for (unsigned int i = 0; i <= boidsXYZ.size() - 1; i++) {
		for (unsigned int j = 0; j <= boidsXYZ.at(i)->size() - 1; j++) {
			for (unsigned int k = 0; k <= boidsXYZ.at(i)->at(j)->size() - 1; k++) {
				long int size = boidsXYZ.at(i)->at(j)->at(k)->size();
				for (long int l = size - 1; l >= 0; l--) {
					//if (boidsXYZ.at(i)->at(j)->at(k)->at(l)->getColor() == "red") glColor3f(1.0f, 0.0f, 0.0f);
					//else glColor3f(0.0, 0.0, 0.0);
					float* _position = boidsXYZ.at(i)->at(j)->at(k)->at(l)->getPosition();
					glPushMatrix();
					//glTranslatef(_position[0], _position[1], _position[2]);
					//glutSolidSphere(1.0, 20.0, 20.0);

					glEnable(GL_TEXTURE_2D);
					glBindTexture(GL_TEXTURE_2D, boidsXYZ.at(i)->at(j)->at(k)->at(l)->getPicture()); //Bind texture

					glTranslatef(_position[0], _position[1], _position[2]);

					glScaled(4, 4, 4);
					glBegin(GL_QUADS);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-1.0f, -1.0f, 0.0f);

					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(1.0f, -1.0f, 0.0f);

					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(1.0f, 1.0f, 0.0f);

					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-1.0f, 1.0f, 0.0f);
					glEnd();

					glDisable(GL_TEXTURE_2D);
					glPopMatrix();
				}
			}
		}
	}
	glutSwapBuffers();
}

static void
reshape(int w, int h)
{
	if (h == 0)
		h = 1;

	g_viewport_width = w;
	g_viewport_height = h;

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, w / (GLdouble)h, 0.1, 1000.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutPostRedisplay();
}

void run(int value)
{
	srand(time(NULL));
	std::vector< std::vector< std::vector< std::vector<Boid*> *> *> *> boidsXYZ = parser->grid.getAllGrid();
	vector <Boid*>* boidNeighbor;

	for (unsigned int i = 0; i <= boidsXYZ.size() - 1; i++) {
		for (unsigned int j = 0; j <= boidsXYZ.at(i)->size() - 1; j++) {
			for (unsigned int k = 0; k <= boidsXYZ.at(i)->at(j)->size() - 1; k++) {
				int l = boidsXYZ.at(i)->at(j)->at(k)->size() - 1;
				if (l >= 0){
					int _positionActuelleCase[3] = { i, j, k };
					boidNeighbor = parser->grid.getNeighbors(_positionActuelleCase);
					for (l; l >= 0; l--) {
						parser->grid.updateOnGrid(boidsXYZ.at(i)->at(j)->at(k)->at(l), boidsXYZ.at(i)->at(j)->at(k)->at(l)->move(boidNeighbor), _positionActuelleCase);
						// find one enfant of one boid
						//Boid* test;
						//test = parser->grid.findBoidById(boidsXYZ.at(i)->at(j)->at(k)->at(l)->getIdEnfant()[0]);
					}
				}
			}
		}
	}
	glutPostRedisplay();
	glutTimerFunc(10, run, 1);
}

/*
void processNormalKeys(unsigned char key, int x, int y)
{
	switch (key) {
	//case 'z': a += 10.0f; break;
	//case 's': a -= 10.0f; break;

	case 'z':
		cout << "z pressed" << endl;
        g_camera.Move(g_translation_speed);
        break;
	case 's':
        g_camera.Move(-g_translation_speed);
        break;
	case 'q':
        g_camera.Strafe(g_translation_speed);
        break;
	case 'd':
        g_camera.Strafe(-g_translation_speed);
        break;
	}
}
*/


void computePos(float deltaMove) {

	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}
/*
void mouseMove(int x, int y) {

	// this will only be true when the left button is down
	if (xOrigin >= 0) {

		// update deltaAngle
		deltaAngle = (x - xOrigin) * 0.001f;

		// update camera's direction
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}
}

void mouseButton(int button, int state, int x, int y) {

	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {

		// when the button is released
		if (state == GLUT_UP) {
			angle += deltaAngle;
			cout << "angle : " << angle << endl;
			xOrigin = -1;
		}
		else  {// state = GLUT_DOWN
			xOrigin = x;
		}
	}
}*/

GLuint init(const char *filename)
{
	struct file_buffer_t *file;

	/* Initialize OpenGL */
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glShadeModel(GL_SMOOTH);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	/* Load PNG file */
	file = textureLoader->readFile(filename);
	if (!file)
		exit(EXIT_FAILURE);

	/* Load PNG texture from memory */
	GLuint texId = textureLoader->loadPNGTexture(file);
	if (!texId)
	{
		textureLoader->freeFileBuffer(file);
		exit(EXIT_FAILURE);
	}

	textureLoader->freeFileBuffer(file);
	return texId;
}


void Keyboard(unsigned char key, int x, int y)
{
    if(key == 27) {
        exit(0);
    }

    if(key == ' ') {
        g_fps_mode = !g_fps_mode;

        if(g_fps_mode) {
            glutSetCursor(GLUT_CURSOR_NONE);
            glutWarpPointer(g_viewport_width/2, g_viewport_height/2);
        }
        else {
            glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
        }
    }

    switch(key)
    {
		case 'z':
			g_camera.Move(g_translation_speed);
			break;
		case 's':
			g_camera.Move(-g_translation_speed);
			break;
		case 'q':
			g_camera.Strafe(g_translation_speed);
			break;
		case 'd':
			g_camera.Strafe(-g_translation_speed);
			break;
    }
    g_key[key] = true;
}

void KeyboardUp(unsigned char key, int x, int y)
{
    g_key[key] = false;
}


void mouseButton(int button, int state, int x, int y)
{
	/*
    if(state == GLUT_DOWN) {
        if(button == GLUT_LEFT_BUTTON) {
            g_mouse_left_down = true;
        }
        else if(button == GLUT_RIGHT_BUTTON) {
            g_mouse_right_down = true;
        }
    }
    else if(state == GLUT_UP) {
        if(button == GLUT_LEFT_BUTTON) {
            g_mouse_left_down = false;
        }
        else if(button == GLUT_RIGHT_BUTTON) {
            g_mouse_right_down = false;
        }
    }*/
}


void mouseMove(int x, int y)
{
    // This variable is hack to stop glutWarpPointer from triggering an event callback to Mouse(...)
    // This avoids it being called recursively and hanging up the event loop
    static bool just_warped = false;

    if(just_warped) {
        just_warped = false;
        return;
    }

    if(g_fps_mode) {

        int dx = x - g_viewport_width/2;
        int dy = y - g_viewport_height/2;
        if(dx) {
            g_camera.RotateYaw(g_rotation_speed*dx);
        }

        if(dy) {
            g_camera.RotatePitch(g_rotation_speed*dy);
        }

        glutWarpPointer(g_viewport_width/2, g_viewport_height/2);

        just_warped = true;
    }
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv); // to initialize the toolkit;
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // sets the display mode

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT); // sets the window size
	glutInitWindowPosition(SCREEN_POSITION_X, SCREEN_POSITION_Y); // sets the starting position for the window
	glutCreateWindow("Ulysse"); // creates the window and sets the title
	//glutFullScreen();           // making the window full screen
	glClearColor(1.0, 1.0, 1.0, 0.0); // sets background color to white

	//glutIgnoreKeyRepeat(1);
	//glutSpecialFunc(pressKey);
	//glutSpecialUpFunc(releaseKey);
	glutKeyboardFunc(Keyboard);

	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	// Creation d'une grille. Cube de 10 de cote. Ajouter randomGeneration=true pour generer automatiquement une grille
	//grid.createGrid(CUBE_SIZE);

	// Parse file xml
	(argv[1] != NULL) ? parser->parse(argv[1]) : parser->parse("./res/data/Ulysse.xml");

	run(1);

	cout << "initialize finished" << endl;

	glutMainLoop(); // go into a loop until event occurs
	return 0;
}
