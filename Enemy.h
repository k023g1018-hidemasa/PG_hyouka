#pragma once

class Enemy
{
private:
	int posX_;
	int posY_;
	int speed_;
	int r_;
	bool isLive_;
	int time_;
	int resCount_;


public:
	Enemy(int posX, int posY, int speed, bool isLive,int r	,int time,int resCount);
	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	bool GetLive() { return isLive_;};
	int GetR() { return r_; };
	void SetPosition(int posX, int posY);
	void SetLive(bool isLive);
	int GetRescount() { return resCount_; };
	void SetResCount(int resCount);
	void Move( );
	void Respawn();
	void isDraw();
	~Enemy();
};


