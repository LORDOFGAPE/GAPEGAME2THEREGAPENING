#include "stdafx.h"
#include <iostream>
#include "Bat.h"

Bat::Bat(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	batShape.setSize(sf::Vector2f(125, 7));
	batShape.setPosition(position);
}

FloatRect Bat::getPosition()
{
	return batShape.getGlobalBounds();
}

RectangleShape Bat::getShape()
{
	return batShape;
}

float Bat::getX()
{
	return position.x;
}

void Bat::moveLeft()
{
	position.x -= batSpeed;
}

void Bat::moveRight()
{
	position.x += batSpeed;
}

void Bat::update()
{
	batShape.setPosition(position);
}

void Bat::getPositionc()
{
	std::cout << position.x ;
}