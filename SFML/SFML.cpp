// SFML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "bat.h"
#include "ball.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

using namespace sf;

int main()
{
	int windowWidth = 1024;
	int windowHeight = 768;

	RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");
	window.setFramerateLimit(120);


	int score = 0;
	int lives = 3;

	Bat bat(windowWidth / 2, windowHeight - 20);

	Ball ball(windowWidth / 2, 1);

	Clock clock;

	Text hud;

	Font font;

	font.loadFromFile("DS-DIGIT.ttf");

	hud.setFont(font);

	hud.setCharacterSize(75);

	hud.setFillColor(sf::Color::White);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			bat.moveLeft();
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			bat.moveRight();
		}
		else if (Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		//ball

		if (ball.getPosition().top > windowHeight)
		{
			ball.hitBottom();
			lives--;
			if (lives < 1)
			{
				score = 0;
				lives = 3;
			}
		}
		if (ball.getPosition().top < 0)
		{
			ball.reboundTop();
			score++;
		}
		if (ball.getPosition().left<0 || ball.getPosition().left + 10>windowWidth)
		{
			ball.reboundSides();
		}
		if (ball.getPosition().intersects(bat.getPosition()))
		{
			ball.reboundBat(bat.getX());
		}

		//update ball and bat
		ball.update();
		bat.update();
		std::stringstream ss;
		ss << "   xVelocity" << ball.getXVelocity() << "  yVelocity:" << ball.getYVelocity();

		hud.setString(ss.str());

		//draw
		bat.getPositionc();
		std::cout << std::endl;
		ball.getPositionb();
		std::cout << std::endl;
		sf::Time time = clock.getElapsedTime();
		clock.restart().asSeconds();
		window.clear(Color(26, 128, 182, 255));
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.draw(hud);


		window.display();
	}
	return 0;
}
