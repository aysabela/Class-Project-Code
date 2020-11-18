////// Rectangle.cpp
#include "Rectangle.h"


Rectangle::Rectangle(double w, double h)
{
	width = w;
	height = h;
}

Rectangle::Rectangle(double w)
{
	width = w;
}
Rectangle::~Rectangle()
{

}
void Rectangle::setWidth(double w)
{
	width = w;
}

void Rectangle::setHeight(double h)
{
	height = h;
}
double Rectangle::getWidth() const
{
	return width;
}

double Rectangle::getHeight() const
{
	return height;
}

void Rectangle::setSerialNumber(int s)
{
	serialNumber = s;
}
int Rectangle::getSerialNumber() const
{
	return serialNumber;
}