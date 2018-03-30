#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bat
{
private:
	Vector2f position;

	RectangleShape batShape;

	float batSpeed = 5.0f;

public:
	Bat(float startX, float startY);

	FloatRect getPosition();

	RectangleShape getShape();

	float getX();

	void moveLeft();

	void moveRight();

	void update();

	void getPositionc();

};