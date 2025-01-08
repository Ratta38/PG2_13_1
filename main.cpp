#include <Novice.h>
#include "Enemy.h"
#include "Player.h"
#include "Collision.h"
#define ENEMY_MAX 2 //敵の最大数

const char kWindowTitle[] = "GC1C_12_ミハラ_ユウタ_タイトル";

int Enemy::count = 1;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player({ 640.0f, 650.0f }, 32.0f);

	Enemy* enemy[ENEMY_MAX];
	enemy[0] = new Enemy({ 300.0f,320.0f }, 16.0f, 5.0f, true);
	enemy[1] = new Enemy({ 16.0f,420.0f }, 16.0f, 5.0f, true);

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

		player->Update(keys, preKeys);

		for (int i = 0;i < ENEMY_MAX;i++) {
			enemy[i]->Update();
			for (int j = 0;j < BULLET_MAX;j++) {
				Collision(enemy[i], player->bullet[j]);
				Collision(enemy[i], player->bullet[j]);
			}
		}
		
		if (keys[DIK_R] && !preKeys[DIK_R]) {
			Enemy::count = 1;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player->Draw();

		for (int i = 0;i < ENEMY_MAX;i++) {
			enemy[i]->Draw();
		}

		Novice::ScreenPrintf(0, 0, "enemy[0].isAlive : %d", enemy[0]->isActive_);
		Novice::ScreenPrintf(0, 20, "enemy[1].isAlive : %d", enemy[1]->isActive_);

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

	delete enemy[0];
	delete enemy[1];

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
