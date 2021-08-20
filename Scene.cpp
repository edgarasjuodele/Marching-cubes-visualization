#include <GL/freeglut.h>
#include <stdbool.h>
#include <time.h>
#include </C/project/OpenGL Template/OpenGL Template/Cube.h>
#include </C/project/OpenGL Template/OpenGL Template/ScanShape.h>

static float size = 4.0f;
int currpart = 0;
float currlocx = 0;
float currlocy = 0;
float currlocz = 0;
float angle = 0;
bool maincube = true;
bool mainshape = true;
bool movingcube = true;
int refmill = 100;

Cube* cubes;
Cube* main;
ScanShape* shape;

void drawScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslated(0, 0, -40.0);
	glRotatef(40.0f, 1, 0, 0);
	glRotatef(-30.0f, 0, 1, 0);
	glTranslatef(size, size, 0);

	shape->Render(currpart, mainshape, angle);

	if (movingcube) {
		glPushMatrix();
		main->setColour(0.7f, 0.7f, 0.0f, 0.05f);
		glTranslatef(-currlocx, -currlocy, -currlocz);
		main->Render();
		glPopMatrix();
	}


	if (maincube) {
		for (int i = 0; i <= 2; i++) {
			for (int j = 0; j <= 2; j++) {
				for (int k = 0; k <= 2; k++) {
					cubes->Render();
					glTranslatef(-size, 0, 0);
				}
				glTranslatef(size * 3, -size, 0);
			}
			glTranslatef(0, size * 3, -size);
		}
	}
	glutSwapBuffers();
}

void updateScene(void) {
	currlocx = currlocx + 0.2f;
	if (fabs(currlocx - size) < 0.005f) {
		currpart = currpart + 1;
	}
	if (currlocx >= (size * 2)) {
		currpart = currpart + 2;
		refmill = 50;
		currlocy += 4;
		currlocx = currlocx - currlocx;
		if (currlocy >= (size * 3)) {
			currlocz += 4;
			currlocy = currlocy - currlocy;
		}
		if (currlocz >= (size * 3)) {
			currlocz = currlocz - currlocz;
			maincube = false;
			movingcube = false;
			mainshape = false;
		}
	}
	if (!movingcube) {
		angle = angle + 0.5f;
	}
	glutPostRedisplay();
}

void timer(int value) {
	updateScene();
	glutPostRedisplay();
	glutTimerFunc(refmill, timer, 0);
}

void resize(int w, int h) {
	if (h == 0){
		h = 1;
	}
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 1.0f, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void setup(void) {
	float hs  = 0.5f * size;
	shape = new ScanShape(-hs, hs, -hs, hs, -hs, hs);
	cubes = new Cube(-hs, hs, -hs, hs, -hs, hs);
	main = new Cube(-hs, hs, -hs, hs, -hs, hs);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	glEnable(GLUT_MULTISAMPLE);

	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void keyInput(unsigned char key, int x, int y) {

}

void keySpecial(int key, int x, int y) {
	if (key == GLUT_KEY_PAGE_DOWN) {
		currpart = 1;
		glutTimerFunc(0, timer, 0);
	}
	else if (key == GLUT_KEY_PAGE_UP) {
		mainshape = !mainshape;
	}
}

void keyUp(unsigned char key, int x, int y) {

}

void keyUpSpecial(int key, int x, int y) {

}

void close(void) {

}