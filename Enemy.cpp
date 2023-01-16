#include "Enemy.h"
#include "DxLib.h"

bool Enemy::isDead=false;

Enemy::Enemy(int x, int y, int sizeX, int sizeY)
{
	this->x = x;
	this->y = y;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}

void Enemy::OnCollision()
{
	isDead = true;
}

void Enemy::CheckCollision(int x, int y, int sizeX, int sizeY)
{
	if (x<this->x + this->sizeX && x + sizeX > this->x&&
		y <this->y + this->sizeY && y + sizeY >this->y)
	{
		OnCollision();
	}

}

void Enemy::Draw()
{
	DrawBox(x,y,x+sizeX,y+sizeY,GetColor(255,255,255),true);
}
