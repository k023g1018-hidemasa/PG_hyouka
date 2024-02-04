#include <Novice.h>
#include"Player.h"
#include"Enemy.h"

const char kWindowTitle[] = "";


 typedef struct Vector2{
	 float X;
	 float Y;

 }Vec2;
 typedef struct bullet {
	 Vector2 pos;
	 float speed;
	 bool live;
	 int r;
 }bu;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	int title = Novice::LoadTexture("./img/Title.png");
	int gameBack = Novice::LoadTexture("./img/Game.png");
	//int playerGh = Novice::LoadTexture("./img/player.png");
	int bulletGh = Novice::LoadTexture("./img/bullet.png");
	int gameover = Novice::LoadTexture("./img/GAMEOVER.png");
	int gameclear = Novice::LoadTexture("./img/GAMECLEAR.png");





	Player* player = new Player(300,500,5,16,false,true);
	Enemy* enemy = new Enemy(100, 200, 2, true, 16, 0, 0);

		bu bullet{};
		bullet.r = 16;
		bullet.speed = 5;

		float playerDistance = 0;
	float bulletDistance = 0;
	enum Scene {
		TITLE,
		GAME,
		CLEAR,
	GAMEOVER,
	};
	int scene = TITLE;
		int burretEnemyRand = (bullet.r +enemy->GetR() ) * (bullet.r + enemy->GetR());
		int playerEnemyRand = (player->GetR() + enemy->GetR()) * (player->GetR() + enemy->GetR());

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		




		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (scene)
		{
		case TITLE:
			player->SetIsLive(true);
			enemy->SetLive(true);
			enemy->SetResCount(0);
			player->SetPosition(300, 500);
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				scene = GAME;
			}
			break;
		case GAME:
		player->OnShot(keys);
		enemy->Move();
		player->Move(keys);
		if (player->GetShot() == false) {
			bullet.pos.X =float(player->GetPosX());
			bullet.pos.Y = float (player->GetPosY());
		}
		if (player->GetShot() == true) {

			bullet.pos.Y -= bullet.speed;//弾の移動
		}


		bulletDistance = (bullet.pos.X- enemy->GetPosX()) * (bullet.pos.X - enemy->GetPosX()) + (bullet.pos.Y - enemy->GetPosY())* (bullet.pos.Y - enemy->GetPosY());//弾と敵の距離
		if (enemy->GetLive() == true ) {//敵と弾が存在しているとき
			if (burretEnemyRand >= bulletDistance) {//(本当は以下)敵が消える
				//player->GetShot() = false;
				player->OfShot();
				enemy->SetLive(false);//コレで変更kanou
				
			}
		}

		playerDistance = (player->GetPosX() - enemy->GetPosX()) * (player->GetPosX() - enemy->GetPosX()) + float((player->GetPosY()) - enemy->GetPosY()) * (player->GetPosY() - enemy->GetPosY());//弾と敵の距離
		if (player->GetIsLive() == true) {
			if (playerEnemyRand >= playerDistance) {
				//player->GetShot() = false;
				player->SetIsLive(false);
				

			}
		}





				enemy->Respawn();
		if (bullet.pos.Y <= 0 + bullet.r) {
			player->OfShot();
		}
		if (enemy->GetRescount() == 3) {
			scene = CLEAR;
		}
		if (player->GetIsLive()==false) {
			scene = GAMEOVER;
		}
		break;
		case CLEAR:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				scene = TITLE;
			}
		break;
		case GAMEOVER:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				scene = TITLE;
			}
			break;

		}





		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		
		switch (scene)
		{
		case TITLE:
			
			Novice::DrawSprite(0, 0,title, 1, 1, 0.0f, WHITE);

			break;
		case GAME:
			Novice::DrawSprite(0, 0, gameBack, 1, 1, 0.0f, WHITE);

		if (enemy->GetLive() == true) {
		enemy->isDraw();

		}
		if (player->GetIsLive() == true) {
		player->isDraw();
		}
		if (player->GetShot() == true) {
		//Novice::DrawEllipse(int(bullet.pos.X), int(bullet.pos.Y), bullet.r, bullet.r, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawSprite(int(bullet.pos.X), int(bullet.pos.Y), bulletGh, 1, 1, 0.0f, WHITE);
		}
		Novice::ScreenPrintf(10, 10, "%d", player->GetShot());
			break;
		case CLEAR:

			Novice::DrawSprite(0, 0, gameclear, 1, 1, 0.0f, WHITE);

			break;
		case GAMEOVER:

			Novice::DrawSprite(0, 0, gameover, 1, 1, 0.0f, WHITE);

			break;
		}
		
		
		
	


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
