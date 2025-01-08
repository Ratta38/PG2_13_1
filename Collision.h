#pragma once
#include "Player.h"
#include "Enemy.h"

/// <summary>
/// 当たり判定
/// </summary>
/// <param name="enemy">敵クラス</param>
/// <param name="bullet">弾クラス</param>
void Collision(Enemy* enemy, Bullet* bullet);

