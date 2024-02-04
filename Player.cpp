#include "Player.h"
#include<Novice.h>
//int playerGh = Novice::LoadTexture("./img/player.png");


Player::Player(int posX, int posY, int speed, int r, bool isShot, bool isLive)
{
	    posX_ = posX;
		posY_ = posY;
		speed_ = speed;
		r_ = r;
		isShot_ = isShot;
		isLive_ = isLive;
}

void Player::SetIsLive(bool isLive)
{
	isLive_ = isLive;
}
void Player::OnShot(char* keys)
{
	if (keys[DIK_SPACE]) {
		isShot_ = true;
	};
	

}
void Player::OfShot()
{
	isShot_ = false;

}
void Player::SetPosition(int posX, int posY)
{
	posX_ = posX;
	posY_ = posY;
}
void Player::Move(char* keys)
{
	if (keys[DIK_W]) {
		posY_ -= speed_;
	}
	if (keys[DIK_S]) {
		posY_ += speed_;
	}
	if (keys[DIK_D]) {
		posX_ += speed_;
	}
	if (keys[DIK_A]) {
		posX_ -= speed_;
	}
}

void Player::isDraw()
{
	Novice::DrawEllipse(posX_, posY_, r_, r_, 0.0f, WHITE, kFillModeSolid);
	//Novice::DrawSprite(int(posX_), int(posY_), playerGh, 1, 1, 0.0f, WHITE);
}
