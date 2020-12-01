#pragma once
namespace  globals{
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 800;

	const float SPRITE_SCALE = 0.5f;
}

struct Vector2D {
	int x, y;
	Vector2D() : x(0), y(0){}
	Vector2D(int a, int b) : x(a), y(b) {}\
		Vector2D zero() {
		return Vector2D(0, 0);
	}
};