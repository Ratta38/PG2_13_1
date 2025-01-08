#pragma once
#include <Vector2.h>
class Bullet
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos">座標</param>
	/// <param name="radius">半径</param>
	/// <param name="speed">スピード</param>
	Bullet(Vector2 pos, float radius, float speed);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Bullet();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();
public:
	Vector2 pos_;
	float radius_;
	float speed_;
};

