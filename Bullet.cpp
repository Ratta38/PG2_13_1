#include "Bullet.h"
#include "Novice.h"

Bullet::Bullet(Vector2 pos, float radius, float speed)
{
	pos_ = pos;
	radius_ = radius;
	speed_ = speed;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	pos_.y -= speed_;
}

void Bullet::Draw()
{
	Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)radius_, (int)radius_, 0.0f, WHITE, kFillModeSolid);
}
