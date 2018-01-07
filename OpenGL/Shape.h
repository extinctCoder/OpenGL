#pragma once
class Shape
{
public:
	int arraySize;
	float **dataStrip;
	float rotate_obj, increment = 0, pi = 3.1416;
	float degreeToRadious(float degree);
	void dataModuleLoader(float **dataStrip, int arraySize);
	static void keyboardHandler(int key, int x, int y);
	void drawMethod(void);
	void displayMethod(void);
	static void displayMethodCallback(void);
	void initializeOpenGL(void);
	void virtual drawShape(void);
};

