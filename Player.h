#pragma once
#include<Novice.h>
class Player
{
public:

	Player(int posX, int posY, int speedX, int speedY);
	~Player();

	void Update(char* keys);
	void Draw();

	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	int GetSpeedX() { return speedX_; };
	int GetSpeedYX() { return speedX_; };
	int GetRadius() { return radius_; };

	void SetSpeedX(int speedX) { speedX_ = speedX; }
	void SetSpeedY(int speedY) { speedY_ = speedY; };


private:
	int posX_;
	int posY_;
	int speedX_;
	int speedY_;
	int radius_;
};

