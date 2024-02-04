#include "Player.h"
Player::Player(int posX, int posY, int speedX, int speedY,bool isAlive)
{
	posX_ = posX;
	posY_ = posY;
	speedX_ = speedX;
	speedY_ = speedY;
	isAlive_ = isAlive;
	radius_ = 30;
	bullet_ = new Bullet;
}

Player::~Player()
{
	delete bullet_;
}

void Player::Draw()
{
	if (isAlive_ == true) {
		bullet_->Draw();
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	}
	
}

void Player::Update(char* keys)
{
	if (isAlive_ == true) {
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

		if (keys[DIK_SPACE] && bullet_->GetIsShot() == false) {
			bullet_->SetIsShot(true);
			bullet_->SetPosX(posX_);
			bullet_->SetPosY(posY_);
		}
		if (bullet_->GetIsShot() == true) {
			bullet_->Update();
		}
	}
}