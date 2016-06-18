
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "11_1.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
int ModulVector(int ax, int ay, int bx, int by, int cx, int cy)
{
	return abs((by - ay)*(cx - ax) - (bx - ax)*(cy - ay));
}

bool CheckPoint(int ax, int ay, int bx, int by, int cx, int cy, int px, int py)
{
	int modulVectorOfTriandle = ModulVector(ax, ay, bx, by, cx, cy),
		modulVectorOfFirstTriangleWithPoint = ModulVector(ax, ay, bx, by, px, py),
		modulVectorOfSecondTriangleWithPoint = ModulVector(bx, by, cx, cy, px, py),
		modulVectorOfThirdTriangleWithPoint = ModulVector(ax, ay, cx, cy,  px, py);

	if (modulVectorOfFirstTriangleWithPoint + modulVectorOfSecondTriangleWithPoint + modulVectorOfThirdTriangleWithPoint - modulVectorOfTriandle > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Triangle(float ax, float ay, float bx, float by, float cx, float cy, float px, float py)
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Triangle and Point");
	sf::ConvexShape convex;

	sf::CircleShape circle(2);

	circle.setFillColor(sf::Color::Black);
	circle.setPosition(px + 300, py + 300);

	convex.setFillColor(sf::Color::Cyan);
	convex.setPointCount(3);

	convex.setPoint(0, sf::Vector2f(ax + 300, ay + 300));
	convex.setPoint(1, sf::Vector2f(bx + 300, by + 300));
	convex.setPoint(2, sf::Vector2f(cx + 300, cy + 300));

	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	Text text("", font, 35);
	text.setColor(Color::Magenta);
	text.setPosition(10, 400);

	if (CheckPoint(ax, ay, bx, by, cx, cy, px, py))
	{
		text.setString("Point in triangle ");
	}
	else
	{
		text.setString("Point not in triangle");
	}
	sf::Vertex line1[] =
	{
		sf::Vertex(sf::Vector2f(300, 0),sf::Color::Black),
		sf::Vertex(sf::Vector2f(300, 600),sf::Color::Black)
	};

	sf::Vertex line2[] =
	{
		sf::Vertex(sf::Vector2f(0, 300),sf::Color::Black),
		sf::Vertex(sf::Vector2f(600, 300),sf::Color::Black)
	};


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		window.draw(line1, 2, sf::Lines);
		window.draw(line2, 2, sf::Lines);

		window.draw(convex);
		window.draw(circle);
		window.draw(text);
		window.display();
	}
}

