#include "Enemy.h"
#include "Novice.h"

const int kWindowWidth = 1280;
const int kWindowHeight = 720;

Enemy::Enemy(Vector2 pos, float radius, float speed, bool isActive)
{
	pos_ = pos;
	radius_ = radius;
	speed_ = speed;
	isActive_ = isActive;
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	pos_.x += speed_;
	if (pos_.x >= kWindowWidth - radius_ || pos_.x <= radius_) {
		speed_ *= -1;
	}

	if (count == 0) {
		isActive_ = false;
	} else {
		isActive_ = true;
	}
}

void Enemy::Draw()
{
	if (isActive_) {
		Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)radius_, (int)radius_, 0.0f, RED, kFillModeSolid);
	}
}
