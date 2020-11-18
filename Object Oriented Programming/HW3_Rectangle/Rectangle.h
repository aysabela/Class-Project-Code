#pragma once
/*
ALYSSA YSABELA FLORES :) 

1. This prevents double (or more) inclusion with the header files. For example, if header file a is defined in header file b and c.cpp includes both,
a problem could arise where c.cpp would have two copies of what is inside header a, which would then cause compilation errors.

2. The size of the array must be const to ensure that the array's size variable cannot be changed at any time. This is important because we wouldn't want the array
to magically change size while we're working on it. It also helps for readability so people understand what the size might indicate and easy to reuse for another array.
Another problem to be mentioned that is a weakness of an array that a vector accomplishes is range-checking. Arrays can go out of bounds and this can cause a multitude of random
problems which are very dangerous. 

3. It is preferable for the array to hold pointers instead of objects because simply put, we are saving memory. Once the objects get plentiful this will make a huge difference
in memory.

*/

#ifndef RECTANGLE_H
#define RECTANGLE_H
////// Rectangle.h
#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

class Rectangle
{
private:
	int serialNumber;
	double width;
	double height;
	

public:
	static int verticalRectangles;
	static int horizontalRectangles;
	static int squares;
	Rectangle(double, double);
	Rectangle(double);
	~Rectangle();
	void setWidth(double);
	void setHeight(double);
	void setSerialNumber(int);
	double getWidth() const;
	double getHeight() const;
	int getSerialNumber() const;
};

#endif 




