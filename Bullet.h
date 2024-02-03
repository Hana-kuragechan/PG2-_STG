#pragma once
#include<Novice.h>

class Bullet
{
public:
	Bullet();

	void Update();
	void Draw();

	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	int GetSpeedX() { return speedX_; };
	int GetRadius() { return radius_; };
	bool GetIsShot() { return isShot_; };

	void SetSpeedX(int speedX) { speedX_ = speedX; }
	void SetPosX(int posX) { posX_ = posX; }
	void SetPosY(int posY) { posY_ = posY; }
	void SetIsShot(bool isShot) { isShot_ = isShot; }

private:
	int posX_;
	int posY_;
	int radius_;
	int speedX_;
	bool isShot_;
};

