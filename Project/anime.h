#ifndef ANIME_H
#define ANIME_H

#include "sprite.h"
#include "global.h"

#include <map>
#include <string>
#include <vector>

class Graphics;
	
class Anime : public Sprite {
public:
	Anime();
	Anime(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float desX, float desY, float delay);

	void playAnimation(std::string animation);
	void update(float elaspedTime);
	void draw(Graphics &graphics, float desX, float desY);
protected:
	void addAnimation(int frames, int sourceX, int sourceY, std::string name, int width, int height);
	virtual void setUpAnimation() = 0;

	std::string currAnimation;
	double delay;	
private:
	std::map<std::string, std::vector<SDL_Rect>> animationSheets;

	double timeElasped;
	int frameIndex;
};

// Class to solve animation problems / Gets Rectangles......


#endif // !ANIME_H


#pragma once
