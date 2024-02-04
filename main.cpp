#include <Novice.h>
#include"Player.h"
#include"Enemy.h"
const char kWindowTitle[] = "GC_1B_08_タムラ_ハナコ_STG";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	Player* player = new Player(300, 300, 5, 5,true);
	Enemy* enemy = new Enemy(500, 100, 5, true);
	
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

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
		player->Update(keys);
		enemy->Update();
		
		
		float distX = float(player->bullet_->GetPosX() - enemy->GetPosX());
		float distY = float(player->bullet_->GetPosY() - enemy->GetPosY());
		float dist = (distX * distX) + (distY * distY);
		int radius = player->bullet_->GetRadius() + enemy->GetRadius();

		if (dist <= radius * radius) {
			enemy->SetIsAlive(false);
		}

		float distanceX = float(player->GetPosX() - enemy->GetPosX());
		float distanceY = float(player->GetPosY() - enemy->GetPosY());
		float distance = (distanceX * distanceX) + (distanceY * distanceY);
		int radius_ = player->GetRadius() + enemy->GetRadius();

		if (distance <= radius_ * radius_) {
			player->SetIsAlive(false);
			
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		player->Draw();
		enemy->Draw();
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
	delete player;
	delete enemy;
	return 0;
}
