#include "stdafx.h"
class base4 {
private:
	float rotate_obj, increment = 0, pi = 3.1416;
public:
	float degreeToRadious(float degree);
	static void keyboardHandler(int key, int x, int y);
	void drawMethod(void);
	void displayMethod(void);
	static void displayMethodCallback(void);
	void initializeOpenGL(void);
};