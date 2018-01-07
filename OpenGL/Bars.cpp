#include "stdafx.h"
#include "Bars.h"
void Bars::drawShape(void) {
	glBegin(GL_LINES);
	for (int i = 0; i < arraySize; i++)
	{
		glVertex2f(dataStrip[i][0], 0);
		glVertex2f(dataStrip[i][0], dataStrip[i][1]);
	}
}