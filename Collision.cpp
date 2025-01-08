#include "Collision.h"
#include <math.h>

void Collision(Enemy* enemy, Bullet* bullet)
{
	if (enemy == nullptr) {
		return;
	}
	if (bullet == nullptr) {
		return;
	}
	float distanceX = enemy->pos_.x - bullet->pos_.x;
	float distanceY = enemy->pos_.y - bullet->pos_.y;
	float distance = sqrtf(static_cast<float>(pow(distanceX, 2) + pow(distanceY, 2)));

	if (distance <= enemy->radius_ + bullet->radius_) {
		enemy->isActive_ = false;
	}
}
