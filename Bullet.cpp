#include "Bullet.h"

Bullet::Bullet()
{
	posX_ = -100;
	posY_ = -100;
	radius_ = 10;
	speedX_ = 10;
	isShot_ = false;
}

void Bullet::Update()
{
	if (isShot_ == true) {
		posY_ -= speedX_;

	}
	if (posY_< -radius_) {
		isShot_ = false;
	}
}

void Bullet::Draw()
{
	Novice::DrawEllipse(posX_,posY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
}