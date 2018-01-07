#include "stdafx.h"
#include "Handler.h"
float **tempArray;
void dataLoader(int classID, int arraySize) {
	float count = 0;
	tempArray = new float *[arraySize];
	for (int i = 0; i < arraySize; i++) {
		tempArray[i] = new float[2];
	}
	switch (classID)
	{
	case 1:
		count = -35.00;
		for (int x = 0; x < arraySize; x += 1) {
			tempArray[x][0] = count;
			tempArray[x][1] = sin(count);
			count += 0.001;
		}
		break;
	case 2:
		count = -35.00;
		for (int x = 0; x < arraySize; x += 1) {
			tempArray[x][0] = count;
			tempArray[x][1] = cos(count);
			count += 0.001;
		}
		break;
	case 3:
		count = -35.00;
		for (int x = 0; x < arraySize; x += 1) {
			tempArray[x][0] = count;
			tempArray[x][1] = tan(count);
			count += 0.001;
		}
		break;
	case 4:
		count = -35.00;
		for (int x = 0; x < arraySize; x += 1) {
			tempArray[x][0] = count;
			tempArray[x][1] = exp(count);
			count += 0.001;
		}
	case 5:
		count = -35.00;
		for (int x = 0; x < arraySize; x += 1) {
			tempArray[x][0] = count;
			tempArray[x][1] = count * count;
			count += 0.001;
		}
		break;
	case 6:
		count = -35.00;
		for (int x = 0; x < arraySize; x += 1) {
			tempArray[x][0] = count;
			tempArray[x][1] = exp(-count);
			count += 0.001;
		}
		break;
	case 7:
		count = -35.00;
		for (int x = 0; x < arraySize; x += 1) {
			tempArray[x][0] = rand() % 25 + 1;
			tempArray[x][1] = rand() % 25 + 1;
			count += 0.001;
		}
		break;
	default:
		break;
	}
}
void inputData(int arraySize) {
	tempArray = new float *[arraySize];
	for (int i = 0; i < arraySize; i++) {
		tempArray[i] = new float[2];
	}
	for (int i = 0; i < arraySize; i++)
	{
		cout << "data : [" << i << ",0]" << ":" << "[" << i << ",1] : ";
		cin >> tempArray[i][0] >> tempArray[i][1];
	}
	cout << "data successfully inserted." << endl;
}
void viewLoadedData(int arraySize) {
	cout << "loaded data is," << endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout << "[" << tempArray[i][0] << "," << tempArray[i][1] << "]" << endl;
	}
}
void optionPanel(void) {
	cout << "Chose an option," << endl;
	cout << "1.Curves" << endl;
	cout << "2.Bars" << endl;
	cout << "3.Spectrums" << endl;
	int choice_type;
	int choice_data;
	int tempArraySize;
	cout << "choice : ";
	cin >> choice_type;
	if (choice_type >= 1 && choice_type <= 3) {
		cout << "please chose a data type," << endl;
		cout << "1.sin(x)" << endl;
		cout << "2.cos(x)" << endl;
		cout << "3.tan(x)" << endl;
		cout << "4.exp(x)" << endl;
		cout << "5.x^2(x)" << endl;
		cout << "6.exp(-x)" << endl;
		cout << "7.random(x)" << endl;
		cout << "8.customInput" << endl;
		cout << "choice : ";
		cin >> choice_data;
		if (choice_data >= 1 && choice_data <= 8) {
			if (choice_data == 8) {
				cout << "please the maximum number of data to be shown : ";
				cin >> tempArraySize;
				inputData(tempArraySize);
				viewLoadedData(tempArraySize);
			}
			else
			{
				tempArraySize = 70000;
				dataLoader(choice_data, tempArraySize);
			}
			if (choice_type == 1) {
				Curves c;
				c.dataModuleLoader(tempArray, tempArraySize);
				c.initializeOpenGL();
			}
			else if (choice_type == 2) {
				Bars b;
				b.dataModuleLoader(tempArray, tempArraySize);
				b.initializeOpenGL();
			}
			else{

				Pies p;
				p.dataModuleLoader(tempArray, tempArraySize);
				p.initializeOpenGL();
			}
		}
		else {
			cout << "wrong input. please try again";
		}
	}
	else {
		cout << "wrong input. please try again";
	}
}
void uiHandler(void) {
	cout << "welcome to basic pi chart" << endl;
	while (true)
	{
		optionPanel();
		cout << "press ctrl + c to exit the application." << endl;
	}
	cout << "thank you ... :)" << endl;
}