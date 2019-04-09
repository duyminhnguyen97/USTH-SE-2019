#ifndef GLOBAL_H
#define GLOBAL_H
#pragma once

namespace global {
	const int screenWidth = 800;
	const int screenHeight = 640;

	const int spriteScale = 2;
}

enum direction {
	Left,
	Right,
	Up,
	Down
};

struct Vector2 {
	int x, y;
	Vector2() :
		x(0),y(0)
	{
	}
	Vector2(int x, int y) :
		x(x),y(y)
	{
	}
	Vector2 zero() {
		return Vector2(0, 0);
	}
};


#endif
