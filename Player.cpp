#include "Player.h"
#include "Novice.h"
#define PLAYER_SPEED 5.0f

Player::Player(Vector2 pos, float radius)
{
	pos_ = pos;
	radius_ = radius;
	speed_ = PLAYER_SPEED;
	for (int i = 0;i < BULLET_MAX;i++) {
		bullet[i] = nullptr;
	}
}

Player::~Player()
{
	for (int i = 0;i < BULLET_MAX;i++) {
		if (bullet[i] != nullptr) {
			delete bullet[i];
		}
	}
}

void Player::Update(const char* keys, const char* preKeys)
{
	if (keys == nullptr) {
		return;
	}
	if (preKeys == nullptr) {
		return;
	}

	if (keys[DIK_W]) {
		pos_.y -= speed_;
	}
	if (keys[DIK_S]) {
		pos_.y += speed_;
	}
	if (keys[DIK_A]) {
		pos_.x -= speed_;
	}
	if (keys[DIK_D]) {
		pos_.x += speed_;
	}

	if ((keys[DIK_W] && keys[DIK_A]) || (keys[DIK_W] && keys[DIK_D]) || (keys[DIK_S] && keys[DIK_A]) || (keys[DIK_S] && keys[DIK_D])) {
		speed_ = PLAYER_SPEED * 0.7f;
	} else {
		speed_ = PLAYER_SPEED;
	}

	for (int i = 0;i < BULLET_MAX;i++) {
		if (bullet[i] == nullptr) {
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				bullet[i] = new Bullet(pos_, 16.0f, 8.0f);
				break;
			}
		}
	}

	for (int i = 0;i < BULLET_MAX;i++) {
		if (bullet[i] != nullptr) {
			bullet[i]->Update();

			if (bullet[i]->pos_.y <= bullet[i]->radius_) {
				delete bullet[i];
				bullet[i] = nullptr;
			}
		}
	}
}

void Player::Draw()
{
	Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)radius_, (int)radius_, 0.0f, GREEN, kFillModeSolid);

	for (int i = 0;i < BULLET_MAX;i++) {
		if (bullet[i] != nullptr) {
			bullet[i]->Draw();
		}
	}
}
