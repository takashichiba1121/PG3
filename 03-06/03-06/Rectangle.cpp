#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(float sizeX, float sizeY)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;

	area = 0;
}

void Rectangle::Size()
{
	area = sizeX * sizeY;
}

void Rectangle::Draw()
{
	std::cout << "Rectangle="<<area<<"\n";
}
