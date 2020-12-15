
#include "AnimatedSprite.h"
#include <string>

class Graphics;

class Player : public AnimatedSprite {
public:
	Player();
	Player(Graphics& graphics, float x, float y);
	void draw(Graphics& graphics);
	void update(float elapsedTime);

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void stopMoving();

	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();
private:
	float _dx;
	float _dy;
	Direction _facing;
};

