#include "Player.h"
#include "Graphics.h"

namespace player_constants {
	const float WALK_SPEED = 0.2f;
}

Player::Player(){}

Player::Player(Graphics& graphics, float x, float y) :
	AnimatedSprite(graphics, "./sprites/Player.png", 0, 0, 178, 512, x, y, 800)
	{
	graphics.loadImage("sprites/Player.png");
	this->setupAnimations();
	//this->playAnimation("RunRight");
	}

void Player::setupAnimations() {
	this->addAnimation(5, 0, 0, "IdleRight", 175, 512, Vector2D(0, 0));
	/*this->addAnimation(1, 0, 0, "IdleLeft", 240, 300, Vector2D(0, 0));
	this->addAnimation(1, 0, 0, "IdleRight", 240, 300, Vector2D(0, 0));
	this->addAnimation(4, 0, 0, "RunDown", 240, 300, Vector2D(0, 0));
	this->addAnimation(4, 0, 630, "RunLeft", 180, 300, Vector2D(0, 0));
	this->addAnimation(4, 0, 940, "RunUp", 240, 310, Vector2D(0, 0));
	this->addAnimation(4, 0, 310, "RunRight", 180, 310, Vector2D(0, 0)); */
}
void Player::animationDone(std::string currentAnimation) {
}

void Player::moveLeft() {
	this->_dx = -player_constants::WALK_SPEED;
	this->playAnimation("RunLeft");
	this->_facing = LEFT;
}

void Player::moveRight() {
	this->_dx = player_constants::WALK_SPEED;
	this->playAnimation("RunRight");
	this->_facing = RIGHT;
}

void Player::moveDown() {
	this->_dy = player_constants::WALK_SPEED;
	this->playAnimation("RunDown");
	this->_facing = DOWN;
}

void Player::moveUp() {
	this->_dy = -player_constants::WALK_SPEED;
	this->playAnimation("RunUp");
	this->_facing = UP;
}

void Player::stopMoving() {
	this->_dx = 0.0f;
	this->_dy = 0.0f;
	this->playAnimation("IdleRight");
	//this->playAnimation(this->_facing == RIGHT ? "IdleRight" : "IdleLeft");
	if (this->_facing == DOWN) {
		this->playAnimation("IdleRight");
	}else if (this->_facing == UP) {
		this->playAnimation("IdleRight");
	} else if (this->_facing == RIGHT) {
		this->playAnimation("IdleRight");
	} else if (this->_facing == LEFT) {
		this->playAnimation("IdleRight");
	}
}

void Player::update(float elapsedTime) {
	//Move by dx
	this->_x += _dx * elapsedTime;
	this->_y += _dy * elapsedTime;
	AnimatedSprite::update(elapsedTime);
}

void Player::draw(Graphics& graphics) {
	AnimatedSprite::draw(graphics, this->_x, this->_y);
}