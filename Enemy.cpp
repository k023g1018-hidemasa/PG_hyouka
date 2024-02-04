#include "Enemy.h"
#include<Novice.h>



Enemy::Enemy(int posX, int posY, int speed, bool isLive, int r, int time, int resCount)
{
	posX_ = posX;
	posY_ = posY;
	speed_ = speed;
	isLive_ = isLive;
	r_ = r;
	time_ = time;
	resCount_ = resCount;
}

void Enemy::SetPosition(int posX, int posY)
{
	posX_ = posX;
	posY_ = posY;
}

void Enemy::SetLive(bool isLive)
{
	isLive_ = isLive;
}


void Enemy::SetResCount(int resCount)
{
	resCount_ = resCount;
}

void Enemy::Move( )
{
	posX_ += speed_;
	if (posX_ >= 1280 - r_|| posX_ <= 0 + r_) {
		speed_ *= -1;
	}
}

void Enemy::Respawn()
{
	if (isLive_ == false) {
		time_++;
		if (time_ >= 60) {
			isLive_ = true;
			resCount_++;
			time_ = 0;
		}
	}
	
}

void Enemy::isDraw()
{
	Novice::DrawEllipse(posX_, posY_, r_, r_, 0.0f, WHITE, kFillModeSolid);
}

