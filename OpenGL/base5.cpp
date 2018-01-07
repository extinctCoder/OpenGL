#include "stdafx.h"
#include "base5.h"
base5* _base5;
extern "C"
void base5::dataModuleLoader(int **dataStrip, int arraySize) {
	this->base5_arraySize = arraySize;
	this->base5_dataStrip = dataStrip;
}
float base5::degreeToRadious(float degree) {
	return degree * _base5->pi / 180;
}
void base5::keyboardHandler(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		_base5->rotate_obj += 0.1;
		cout << "GLUT_KEY_LEFT" << endl;
		break;
	case GLUT_KEY_RIGHT:
		_base5->rotate_obj -= 0.1;
		cout << "GLUT_KEY_RIGHT" << endl;
		break;
	case GLUT_KEY_UP:
		cout << "GLUT_KEY_UP" << endl;
		break;
	case GLUT_KEY_DOWN:
		_base5->rotate_obj = 0;
		cout << "GLUT_KEY_DOWN" << endl;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
void base5::drawMethod(void) {
	glRotatef(rotate_obj, 1.0f, 1.0f, 1.0f);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINES);
	for (int i = 0; i < base5_arraySize; i++)
	{
		glVertex2f(base5_dataStrip[i][0], base5_dataStrip[i][1]);
	}
	/*for (int i = -50; i <= 50; i++)
	{
		for (int j = -50; j <= 50; j++)
		{
			glVertex3f(i, increment*(cos(degreeToRadious(i * 15)) + sin(degreeToRadious(j * 15))), j);
			glVertex3f(i + 1, increment*(cos(degreeToRadious((i + 1) * 15)) + sin(degreeToRadious((j + 1) * 15))), j + 1);
		}
	}*/
	increment += 0.01;
	glutPostRedisplay();
	glEnd();
}
void base5::displayMethod(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawMethod();
	glutSwapBuffers();
}
void base5::displayMethodCallback(void) {
	_base5->displayMethod();
}
void base5::initializeOpenGL(void) {
	_base5 = this;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("OpenGL : base 2");
	glutDisplayFunc(_base5->displayMethodCallback);
	glutSpecialFunc(_base5->keyboardHandler);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(35.0, 1.0, 1.0, 180.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0.0, 0.0, -100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0);
	glutMainLoop();
}