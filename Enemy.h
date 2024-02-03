#pragma once
#include<Novice.h>
class Enemy
{
public:

	Enemy(int posX, int posY, int speedX, bool isAlive);
	~Enemy();

	void Update();
	void Draw();

	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	int GetSpeedX() { return speedX_; };
	int GetRadius() { return radius_; };

	void SetSpeedX(int speedX) { speedX_ = speedX; }


private:
	int posX_;
	int posY_;
	int speedX_;
	int radius_;
	bool isAlive_;
	int respawnTimer;
};

