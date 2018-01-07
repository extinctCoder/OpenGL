#include "stdafx.h"
#include "base4.h"
base4* _base4;

extern "C"
float base4::degreeToRadious(float degree) {
	return degree * _base4->pi / 180;
}
void base4::keyboardHandler(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		_base4->rotate_obj += 0.1;
		cout << "GLUT_KEY_LEFT" << endl;
		break;
	case GLUT_KEY_RIGHT:
		_base4->rotate_obj -= 0.1;
		cout << "GLUT_KEY_RIGHT" << endl;
		break;
	case GLUT_KEY_UP:
		cout << "GLUT_KEY_UP" << endl;
		break;
	case GLUT_KEY_DOWN:
		_base4->rotate_obj = 0;
		cout << "GLUT_KEY_DOWN" << endl;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
void base4::drawMethod(void) {
	glRotatef(rotate_obj, 1.0f, 1.0f, 1.0f);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINES);
	for (int i = -50; i <= 50; i++)
	{
		for (int j = -50; j <= 50; j++)
		{
			glVertex3f(i, increment*(cos(degreeToRadious(i * 15)) + sin(degreeToRadious(j * 15))), j);
			glVertex3f(i + 1, increment*(cos(degreeToRadious((i + 1) * 15)) + sin(degreeToRadious((j + 1) * 15))), j + 1);
		}
	}
	increment += 0.01;
	glutPostRedisplay();
	glEnd();
}
void base4::displayMethod(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawMethod();
	glutSwapBuffers();
}
void base4::displayMethodCallback(void) {
	_base4->displayMethod();
}
void base4::initializeOpenGL(void) {
	_base4 = this;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("OpenGL : base 2");
	glutDisplayFunc(_base4->displayMethodCallback);
	glutSpecialFunc(_base4->keyboardHandler);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(35.0, 1.0, 1.0, 180.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0.0, 0.0, -100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0);
	glutMainLoop();
}