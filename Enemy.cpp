#include "Enemy.h"
#include "DxLib.h"

void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::ProximityUpdate,
	&Enemy::AttackUpdate,
	&Enemy::LeaveUpdate
};

Enemy::Enemy(int x, int y, int sizeX, int sizeY)
{
	this->x = x;
	this->y = y;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}

void Enemy::Update()
{
	(this->*spFuncTable[static_cast<size_t>(phase_)])();

	if (isBullet == true&&bulletX<=400)
	{
		bulletY++;
	}
}

void Enemy::Draw()
{
	DrawBox(x,y,x+sizeX,y+sizeY,GetColor(255,255,255),true);
	
	if (isBullet == true)
	{
		DrawBox(bulletX, bulletY, bulletX + 10, bulletY + 10, GetColor(255, 0, 0), true);
	}

	DrawFormatString(0,0,GetColor(255,255,255),"%d",phase_);
}

void Enemy::ProximityUpdate()
{
	y++;
	if (y>=200)
	{
		phase_ = Phase::Attack;
	}
}

void Enemy::AttackUpdate()
{
	bulletX = x;
	bulletY = y;
	isBullet = true;

	phase_ = Phase::Leave;
}

void Enemy::LeaveUpdate()
{
	x++;
	y++;
}
