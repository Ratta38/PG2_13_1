#pragma once
#include <Vector2.h>
#include "Bullet.h"
#define BULLET_MAX 20
class Player
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos">座標</param>
	/// <param name="radius">半径</param>
	Player(Vector2 pos, float radius);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="keys">入力キー</param>
	/// <param name="preKeys">前フレームに入力したキー</param>
	void Update(const char* keys, const char* preKeys);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();
public:
	Vector2 pos_;
	float radius_;
	float speed_;
	Bullet* bullet[BULLET_MAX];
};

