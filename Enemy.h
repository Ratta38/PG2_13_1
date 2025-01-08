#pragma once
#include <Vector2.h>

extern const int kWindowWidth;
extern const int kWindowHeight;

class Enemy
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos">座標</param>
	/// <param name="radius">半径</param>
	/// <param name="speed">スピード</param>
	/// <param name="isActive">生存フラグ</param>
	Enemy(Vector2 pos, float radius, float speed, bool isActive);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Enemy();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();
public:
	static bool isActive_;
	Vector2 pos_;
	float radius_;
	float speed_;
};

