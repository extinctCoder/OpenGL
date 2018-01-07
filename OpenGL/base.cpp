#include "stdafx.h"
//#include "base.h"
//
//
//
//void render()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(0, 0, -10, 0, 0, 0, 0, 1, 0);
//
//	/*
//
//	NOW HERE YOU CAN DRAW WHAT YOU WANT! :)
//
//	*/
//
//	glColor3f(0.0, 1.0, 0.5);
//	glBegin(GL_LINE_LOOP);
//	glVertex3i(25, 70, 0);
//	glVertex3i(275, 70, 0);
//	glVertex3i(150, 200, 0);
//	glEnd();
//	
//
//
//	glutSwapBuffers();
//}
//
//void reshape(int w, int h)
//{
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glViewport(0, 0, w, h);
//	gluPerspective(20, w*1.0f / h, 0.1f, 100);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//void selectObject(int x, int y)
//{
//	GLuint buff[64] = { 0 };
//	GLint hits, view[4];
//	glSelectBuffer(64, buff);
//	glGetIntegerv(GL_VIEWPORT, view);
//	glRenderMode(GL_SELECT);
//	glInitNames();
//	glPushName(0);
//	glMatrixMode(GL_PROJECTION);
//	glPushMatrix();
//	glLoadIdentity();
//	gluPickMatrix(x, y, 1.0, 1.0, view);
//	gluPerspective(20, view[2] * 1.0f / view[3], 0.1f, 100);
//	glMatrixMode(GL_MODELVIEW);
//	glutSwapBuffers();
//	render();
//	glMatrixMode(GL_PROJECTION);
//	glPopMatrix();
//	hits = glRenderMode(GL_RENDER);
//	std::cout << "Hits: " << hits << "\n" << "ID: " << buff[3] << "\n";
//
//	glMatrixMode(GL_MODELVIEW);
//}
//
//void mouseHandler(int button, int state, int x, int y)
//{
//	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
//	{
//		selectObject(x, y);
//	}
//}
//
//void init(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(1000, 600);
//	glutCreateWindow("OpenGL");
//	glutDisplayFunc(render);
//	glutReshapeFunc(reshape);
//	glutMouseFunc(mouseHandler);
//	glEnable(GL_DEPTH_TEST);
//	glutMainLoop();
//}