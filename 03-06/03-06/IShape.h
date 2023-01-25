#pragma once
class IShape
{
public:
	virtual ~IShape();

	virtual void Size()=0;

	virtual void Draw()=0;
};

