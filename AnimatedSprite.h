#pragma once

#include <string>
#include "Sprite.h"
#include <map>
#include "Globals.h"
#include <Vector>;

class Graphics;

class AnimatedSprite: public Sprite
{
public:
	class AnimatedSprite();
	class AnimatedSprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate);

	void playAnimation(std::string animation, bool once = false);

	void update(int elapsedTime);
	
	void draw(Graphics& graphics, int x, int y);

	virtual void setupAnimations();
protected:
	double _timeToUpdate;
	bool _currentAnimationOnce;
	std::string _currentAnimation;

	void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2D offset);

	void resetAnimations();

	void stopAnimation();

	void setVisible(bool visible);

	virtual void animationDone(std::string currentAnimation);

private:
	std::map<std::string, std::vector<SDL_Rect>> _animations;
	std::map<std::string, Vector2D> _offsets;

	int _frameIndex;
	double _timeElapsed;
	bool _visible;
};

