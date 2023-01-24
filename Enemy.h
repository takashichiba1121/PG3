#pragma once
class Enemy
{
public:
	Enemy(int x,int y,int sizeX,int sizeY);

	void Update();

	void Draw();

	void ProximityUpdate();

	void AttackUpdate();

	void LeaveUpdate();

private:
	int x;
	int y;
	int sizeX;
	int sizeY;

	enum class Phase
	{
		Proximity,
		Attack,
		Leave,
	};

	Phase phase_=Phase::Proximity;

	static void (Enemy::* spFuncTable[])();

#pragma region íeópïœêî
	int bulletX;
	int bulletY;

	bool isBullet=false;

#pragma endregion
};

