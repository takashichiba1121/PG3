#include "Circle.h"
#include <iostream>

Circle::Circle(float r)
{
	this->r = r;

	area = 0;
}

void Circle::Size()
{
	area = r * r * 3.141592;
}

void Circle::Draw()
{
	std::cout<<"Circle=" <<area<<"\n";
}
