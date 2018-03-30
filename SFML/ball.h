#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
	Vector2f position;

	RectangleShape ballShape;

	float xVelocity = 2.5f;
	float yVelocity = 2.5f;

public:
	Ball(float startX, float startY);

	FloatRect getPosition();

	RectangleShape getShape();

	float getXVelocity();
	float getYVelocity();
	void reboundSides();
	void reboundTop();
	void reboundBat(float batx);
	void hitBottom();
	void update();
	void getPositionb();
};