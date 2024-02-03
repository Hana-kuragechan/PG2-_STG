#include "Enemy.h"
Enemy::Enemy(int posX, int posY, int speedX, bool isAlive)
{
	posX_ = posX;
	posY_ = posY;
	speedX_ = speedX;
	isAlive_ = isAlive;
	radius_ = 30;
	respawnTimer = 60;
}

void Enemy::Update()
{
	if (isAlive_ == true) {
		posX_ += speedX_;
		if (posX_ >= 1280 - radius_) {
			speedX_ *= -1;
		}
		if (posX_ <= radius_) {
			speedX_ *= -1;
		}
	}
	if (isAlive_ == false) {
		respawnTimer--;
		if (respawnTimer <= 0) {
			isAlive_ = true;
			respawnTimer = 60;
		}
	}
}

void Enemy::Draw()
{
	if (isAlive_ == true) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}
}
