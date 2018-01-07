#include "stdafx.h"
class base5
{
public:
	int base5_arraySize;
	int **base5_dataStrip;
	float rotate_obj, increment = 0, pi = 3.1416;
	float degreeToRadious(float degree);
	void dataModuleLoader(int **dataStrip, int arraySize);
	static void keyboardHandler(int key, int x, int y);
	void drawMethod(void);
	void displayMethod(void);
	static void displayMethodCallback(void);
	void initializeOpenGL(void);
};

