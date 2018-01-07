#include "stdafx.h"
#include "base2.h"

float rotate_obj, increment = 0;

float degreeToRadious(float degree) {
	return degree * PI / 180;
}
static void keyboardHandler(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		rotate_obj += 0.1;
		cout << "GLUT_KEY_LEFT" << endl;
		break;
	case GLUT_KEY_RIGHT:
		rotate_obj -= 0.1;
		cout << "GLUT_KEY_RIGHT" << endl;
		break;
	case GLUT_KEY_UP:
		cout << "GLUT_KEY_UP" << endl;
		break;
	case GLUT_KEY_DOWN:
		rotate_obj = 0;
		cout << "GLUT_KEY_DOWN" << endl;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
void drawMethod(void) {
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
void displayMethod(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawMethod();
	glutSwapBuffers();
}
void initializeOpenGL(void) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("OpenGL : base 2");
	glutDisplayFunc(displayMethod);
	glutSpecialFunc(keyboardHandler);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(35.0, 1.0, 1.0, 180.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0.0, 0.0, -100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0);
	glutMainLoop();
}