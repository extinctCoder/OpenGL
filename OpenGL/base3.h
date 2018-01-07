#include "stdafx.h"
class base3{
	
public:
	static base3* currentInstance;
	float radius[3] = {
		0.0f,
		60.0f,
		120.0f
	};
	struct Point {
		GLint x_axis;
		GLint y_axis;
	};
	Point pCenter = { 320, 240 };
	float dRadius = 1;
	void drawMethod(Point circleCenter, GLfloat circleRadious);
	static void drawCallback()
	{
		currentInstance->displayMethod();
	}
	void setupDrawCallback()
	{
		currentInstance = this;
		::glutDisplayFunc(base3::drawCallback);
	}
	void initializeOpenGL(void);
	void displayMethod(void);
	void openGlTimer(int value);
};