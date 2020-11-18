////// main.cpp
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <random>

using namespace std;
#include "Rectangle.h"

const int SIZE = 21;
int Rectangle::squares = 0;
int Rectangle::horizontalRectangles = 0;
int Rectangle::verticalRectangles = 0;
void display(Rectangle *[]);

int main()
{
	
	random_device rd;
	default_random_engine generator(rd());
	uniform_int_distribution<int> distribution(1, 7);
	int dice_roll1 = distribution(generator);
	int dice_roll2 = distribution(generator);

	Rectangle * arrRect[SIZE];

	for (int i = 0; i < SIZE; i++) {
		arrRect[i] = nullptr;
	}

	for (int i = 0; i < SIZE; i++)
	{
		uniform_int_distribution<int> distribution(1, 7);
		int dice_roll1 = distribution(generator);
		int dice_roll2 = distribution(generator);
		arrRect[i] = new Rectangle(dice_roll1, dice_roll2);
		arrRect[i]->setSerialNumber(i);
	}


	display(arrRect);
	system("pause");

	for (int i = 0; i < SIZE; i++) {
		if (arrRect[i] != nullptr) {
			delete arrRect[i];
		}
	}
}

void display(Rectangle * arr[])
{
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;

	cout << "Squares" << endl;
	cout << "=================" << endl;
	cout << "Label   " << "Width   " << "Height  " << endl << endl;

	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i]->getWidth() == arr[i]->getHeight()) {
			count1 += 1;
			Rectangle::squares += 1;
			if (arr[i]->getSerialNumber() < 10) {
				cout << "R000" << arr[i]->getSerialNumber() << "     " << arr[i]->getWidth() << "     " << arr[i]->getHeight() << endl;  /// Display the serial number of the Rectangle object
			}
			else {
				cout << "R00" << arr[i]->getSerialNumber() << "     " << arr[i]->getWidth() << "     " << arr[i]->getHeight() << endl;
			}
		}
	}

	cout << "=================" << endl;
	cout << "Total           " << count1 << endl << endl;
	cout << "Horizontal Rectangles" << endl;
	cout << "=================" << endl;
	cout << "Label   " << "Width   " << "Height  " << endl << endl;

	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i]->getWidth() > arr[i]->getHeight()) {
			count2 += 1;
			Rectangle::horizontalRectangles += 1;
			if (arr[i]->getSerialNumber() < 10) {
				cout << "R000" << arr[i]->getSerialNumber() << "     " << arr[i]->getWidth() << "     " << arr[i]->getHeight() << endl;  /// Display the serial number of the Rectangle object
			}
			else {
				cout << "R00" << arr[i]->getSerialNumber() << "     " << arr[i]->getWidth() << "     " << arr[i]->getHeight() << endl;
			}
		}
	}

	cout << "=================" << endl;
	cout << "Total           " << count2 << endl << endl;
	cout << "Vertical Rectangles" << endl;
	cout << "=================" << endl;
	cout << "Label   " << "Width   " << "Height  " << endl << endl;

	for (int i = 0; i < SIZE; i++)
	{	
		if (arr[i]->getWidth() < arr[i]->getHeight()) {
			count3 += 1;
			Rectangle::verticalRectangles += 1;
			if (arr[i]->getSerialNumber() < 10) {
				cout << "R000" << arr[i]->getSerialNumber() << "     " << arr[i]->getWidth() << "     " << arr[i]->getHeight() << endl;  /// Display the serial number of the Rectangle object
			}
			else {
				cout << "R00" << arr[i]->getSerialNumber() << "     " << arr[i]->getWidth() << "     " << arr[i]->getHeight() << endl;
			}
		}
	}

	cout << "=================" << endl;
	cout << "Total           " << count3 << endl << endl;

}