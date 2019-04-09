#ifndef ANIMATION_H
#define ANIMATION_H

#include <map>
#include <string>
#include "global.h"
#include <vector>
#include "sprite.h"
class Graphics;

class Animation : public Sprite {
public:
	Animation();
	Animation(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate);

	void playAnimation(std::string currAnimation, bool once = false);
	void update(float elaspedTime);
	void draw(Graphics &graphics, int x, int y);

protected:
	double timeToUpdate;
	bool currAnimationOnce;
	std::string currAnimation;
	
	void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);
	void resetAnimation();
	void stopAnimation();
	void setVisible(bool visible);

	virtual void setUpAnimation() = 0;
	virtual void animationDone(std::string currAnimation) = 0;
private:
	std::map<std::string, std::vector<SDL_Rect>> animation;
	std::map<std::string, Vector2> offSets;

	int frameIndex;
	double timeElasped;
	bool visible;
};


#endif // !ANIMATION_H

#pragma once
