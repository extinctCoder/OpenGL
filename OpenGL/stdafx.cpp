#include "stdafx.h"

void initializeOpenGL(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(getWindowSize().right, getWindowSize().bottom);
	glutCreateWindow("CHARTS");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 300.0, 0, 300.0);
	glutDisplayFunc(openGLDisplay);
	glutMainLoop();
}
void openGLDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
		glVertex3i(25, 70, 0);
		glVertex3i(275, 70, 0);
		glVertex3i(150, 200, 0);
	glEnd();
	glFlush();
}
RECT getWindowSize(void) {
	HWND window = GetDesktopWindow();
	RECT screenSize;
	GetWindowRect(window, &screenSize);
	return screenSize;
}