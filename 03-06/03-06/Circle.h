#pragma once
#include "IShape.h"
class Circle : public IShape
{
public:
	Circle(float r);

	void Size() override;

	void Draw() override;

private:
	float r;

	float area;
};

