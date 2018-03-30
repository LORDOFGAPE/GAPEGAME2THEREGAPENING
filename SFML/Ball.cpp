#include "stdafx.h"
#include "Ball.h"
#include <iostream>

Ball::Ball(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	ballShape.setSize(sf::Vector2f(20, 20));
	ballShape.setPosition(position);
}

FloatRect Ball::getPosition()
{
	return ballShape.getGlobalBounds();
}

float Ball::getYVelocity()
{
	return yVelocity;
}

float Ball::getXVelocity()
{
	return xVelocity;
}

RectangleShape Ball::getShape()
{
	return ballShape;
}

void Ball::reboundSides()
{
	xVelocity = -xVelocity;
}

void Ball::reboundTop()
{
	position.y -= (yVelocity);
	yVelocity = -yVelocity;
}

void Ball::hitBottom()
{
	position.y = 1;
	position.x = 500;
}

void Ball::getPositionb()
{
	std::cout << position.x;
}

void Ball::reboundBat(float batx)
{
	int max = 165;
	float midpoint = 82.5;
	float realPosition = position.x - batx + 25;
	xVelocity = yVelocity * ((realPosition - midpoint) / 50);;
	position.y -= (yVelocity);
	yVelocity = -yVelocity;

}

void Ball::update()
{
	position.y += yVelocity;
	position.x += xVelocity;

	ballShape.setPosition(position);
}