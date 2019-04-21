#ifndef GLOBAL_H
#define GLOBAL_H
#pragma once

namespace global {
	const int screenWidth = 1280;
	const int screenHeight = 960;

	const int spriteScale = 2;
}

namespace sides {
	enum Sides {
		Top,
		Bot,
		Left,
		Right,
		None
	};

	inline Sides getOpposite(Sides side) {
		side == Top ? Bot :
		side == Bot ? Top :
		side == Left ? Right :
		side == Right ? Left :
		None;
	}
}

enum direction {
	Left,
	Right,
	Up,
	Down
};

#endif

