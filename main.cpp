//Include OpenGL header files, so that we can use OpenGL

#include <iostream>
#include <stdlib.h> //Needed for "exit" function

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <glut.h>
#endif


#include "point.h"
#include "Vector3.h"
#include "Terrain.h"

using namespace std;

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * FIELDS
 *!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/


//Loads a terrain from a heightmap.  The heights of the terrain range from
//-height / 2 to height / 2.
Terrain* loadTerrain() {
	//Image* image = loadBMP(filename);
	Terrain* t = new Terrain(128, 128);
	for(int y = 0; y < 128; y++) {
		for(int x = 0; x < 128; x++) {
			//unsigned char color =
			//	(unsigned char)image->pixels[3 * (y * image->width + x)];
			//float h = height * ((color / 255.0f) - 0.5f);
			float h = 10.0f;
			t->SetHeight(x, y, h);
		}
	}
	
	//delete image;
	t->ComputeNormals();
	return t;
}


Terrain* _terrain;
void cleanup() {
	delete _terrain;
}


//Called when a key is pressed
void handleKeypress(unsigned char key, //The key that was pressed
					int x, int y) {    //The current mouse coordinates
	switch (key) {
		case 27: //Escape key
			cleanup();
			exit(0); //Exit the program
	}
}


//Initializes 3D rendering
void Initialize() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);

}



//Called when the window is resized
void handleResize(int w, int h) {
	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);
	
	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
	
	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,                  //The camera angle
				   (double)w / (double)h, //The width-to-height ratio
				   1.0,                   //The near z clipping coordinate. If something is closer than 1 it won't be drawed
				   200.0);                //The far z clipping coordinate. If something is further than 200 it won't be drawed
}


//Draws the 3D scene
void drawScene() {
	//Clear information from last draw
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glRotatef(30.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(-60, 0.0f, 1.0f, 0.0f);
	
	GLfloat ambientColor[] = {0.4f, 0.4f, 0.4f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	
	GLfloat lightColor0[] = {0.6f, 0.6f, 0.6f, 1.0f};
	GLfloat lightPos0[] = {-0.5f, 0.8f, 0.1f, 0.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	
	float scale = 5.0f / max(128- 1, 128 - 1);
	glScalef(scale, scale, scale);
	glTranslatef(-(float)(128 - 1) / 2,
				 0.0f,
				 -(float)(128 - 1) / 2);
	
	_terrain->Draw();
	
	glutSwapBuffers();

}

void Update(int value)
{
	glutPostRedisplay();
	glutTimerFunc(25, Update, 0);
}


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * START of the engine
 *!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
void main(int argc, char** argv) {
	//Initialize GLUT. Don't put code before this, otherwise the programm wil start slower
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1280, 720);			//Set the window size
	
	//Create the window
	glutCreateWindow("Hangine - editor");
	Initialize();							//Initialize rendering
	_terrain = loadTerrain();

	//Set handler functions for drawing, keypresses, and window resizes
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
		
	glutTimerFunc(25, Update, 0);
	glutMainLoop();							//Start the main loop.  glutMainLoop doesn't return.
}









