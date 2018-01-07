#include "stdafx.h"
#include "Shape.h"
Shape* _shape;
void Shape::dataModuleLoader(float **dataStrip, int arraySize) {
	this->arraySize = arraySize;
	this->dataStrip = dataStrip;
}
float Shape::degreeToRadious(float degree) {
	return degree * _shape->pi / 180;
}
void Shape::keyboardHandler(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		_shape->rotate_obj += 0.1;
		cout << "GLUT_KEY_LEFT" << endl;
		break;
	case GLUT_KEY_RIGHT:
		_shape->rotate_obj -= 0.1;
		cout << "GLUT_KEY_RIGHT" << endl;
		break;
	case GLUT_KEY_UP:
		_shape->rotate_obj = 0;
		cout << "GLUT_KEY_UP" << endl;
		break;
	case GLUT_KEY_DOWN:
		_shape->rotate_obj = 0;
		cout << "GLUT_KEY_DOWN" << endl;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
void Shape::drawMethod(void) {
	glRotatef(rotate_obj, 1.0f, 1.0f, 1.0f);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
		glVertex2f(-350, 0);
		glVertex2f(350, 0);
		glVertex2f(0, 350);
		glVertex2f(0, -350);
	glEnd();
	glColor3f(0.20, 3.0, 0.10);
	this->drawShape();
	increment += 0.01;
	glutPostRedisplay();
	glEnd();
}
void Shape::displayMethod(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawMethod();
	glutSwapBuffers();
}
void Shape::displayMethodCallback(void) {
	_shape->displayMethod();
}
void Shape::initializeOpenGL(void) {
	_shape = this;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("");
	glutDisplayFunc(_shape->displayMethodCallback);
	glutSpecialFunc(_shape->keyboardHandler);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(35.0, 1.0, 1.0, 180.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0.0, 0.0, -100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0);
	glutMainLoop();
}
void Shape::drawShape(void) {
}
