#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Tile
{
private:
	Vector2f position;
	RectangleShape tileShape;
	bool hit;
public:
	Tile(float startX, float startY, bool hit);

	FloatRect getPosition();

	RectangleShape getShape();
	void dead();
};