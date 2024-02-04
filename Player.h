#pragma once
class Player
{
private:
	int posX_;
	int posY_;
	int speed_;
	int r_;
	bool isShot_;
	bool isLive_;



public:

	Player(int posX,int posY,int speed,int r, bool isShot,bool isLive);
	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	bool GetShot() { return isShot_; };
	bool GetIsLive() { return isLive_; };
	
	void SetIsLive(bool isLive);
	int GetR() { return r_; };
	void OnShot(char* keys);
	void OfShot();
	void SetPosition(int posX, int posY);
	void Move(char* keys);
	void isDraw();
	~Player();
};




