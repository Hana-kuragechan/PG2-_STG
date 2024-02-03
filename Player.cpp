#include "Player.h"
Player::Player(int posX, int posY, int speedX, int speedY)
{
	posX_ = posX;
	posY_ = posY;
	speedX_ = speedX;
	speedY_ = speedY;
	radius_ = 30;
}

void Player::Draw()
{
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
}

void Player::Update(char* keys)
{
	if (keys[DIK_W]) {
		posY_ -= speedY_;
		if (posY_ <= radius_) {
			posY_ = radius_;
		}
	}
	if (keys[DIK_A]) {
		posX_ -= speedX_;
		if (posX_ <= radius_) {
			posX_ = radius_;
		}
	}
	if (keys[DIK_S]) {
		posY_ += speedY_;
		if (posY_ >= 720 - radius_) {
			posY_ = 720 - radius_;
		}
	}
	if (keys[DIK_D]) {
		posX_ += speedX_;
		if (posX_ >= 1280 - radius_) {
			posX_ = 1280 - radius_;
		}
	}
}