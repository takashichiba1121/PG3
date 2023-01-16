#pragma once
class Enemy
{
public:
	Enemy(int x,int y,int sizeX,int sizeY);

	void OnCollision();

	void CheckCollision(int x, int y, int sizeX, int sizeY);

	void Draw();

	static bool isDead;

private:
	int x;
	int y;
	int sizeX;
	int sizeY;
};

