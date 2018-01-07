#include "stdafx.h"
#include "base3.h"

void base3::drawMethod(Point circleCenter, GLfloat circleRadious) {
	GLfloat circleStep = 1 / circleRadious, x_axis, y_axis;
	for (GLfloat i = 0; i < 360; i++)
	{
		x_axis = circleCenter.x_axis + (circleRadious*cos(i));
		y_axis = circleCenter.y_axis + (circleRadious*sin(i));
		glVertex2f(x_axis, y_axis);
	}
}
void base3::displayMethod(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for (int i = 0; i < 3; i++)
	{
		drawMethod(pCenter, radius[i]);
		radius[i];
		radius[i] += dRadius;
		if (radius[i] > 180) {
			radius[i] = 0;
		}
	}
	glEnd();
	glFlush();
}

void base3::openGlTimer(int value) {
	//glutTimerFunc(value, (this->openGlTimer), 0);
}
extern "C"
void base3::initializeOpenGL(void) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(640, 480);
	glutCreateWindow("base3 : test");
	//setupDrawCallback();
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	gluOrtho2D(0.0, 640, 0, 480);
	this->openGlTimer(33);
	glutMainLoop();
}
