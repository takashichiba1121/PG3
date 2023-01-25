#pragma once
#include "IShape.h"
class Rectangle : public IShape
{
public:
	Rectangle(float sizeX,float sizeY);

	void Size() override;

	void Draw() override;
private:
	float sizeX;
	float sizeY;

	float area;
};

