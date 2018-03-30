#include "stdafx.h"
#include "tile.h"

Tile::Tile(float startX, float startY, bool hit)
{
	position.x = startX;
	position.y = startY;
	hit = false;
	tileShape.setSize(Vector2f(60, 20));
	tileShape.setPosition(position);
}
Tile::Tile()
{
	position.x = 0;
	position.y = 0;
	hit = false;
}
FloatRect Tile::getPosition()
{
	return tileShape.getGlobalBounds();
}

RectangleShape Tile::getShape()
{
	return tileShape;
}

void Tile::dead()
{
	position.x = 100000;
	tileShape.setPosition(position);
}