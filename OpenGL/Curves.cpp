#include "stdafx.h"
#include "Curves.h"
void Curves::drawShape(void) {
	glBegin(GL_POINTS);
	for (int i = 0; i < arraySize; i++)
	{
		glVertex2f(dataStrip[i][0], dataStrip[i][1]);
	}
}
