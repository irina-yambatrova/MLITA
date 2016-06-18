#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "11_1.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
CPointInTriangle::CPointInTriangle(std::ifstream & fin)
	:circle(sf::CircleShape(2))
{
	ReadInputFile(fin);
	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	text = Text("", font, 35);
	text.setColor(Color::Magenta);
	text.setPosition(10, 400);
} 
int CPointInTriangle::ModulVector(sf::Vector2i & a, sf::Vector2i & b, sf::Vector2i & c)
{
	return abs((b.y - a.y)*(c.x - a.x) - (b.x - a.x)*(c.y - a.y));
}

bool CPointInTriangle::CheckPoint()
{
	int modulVectorOfTriandle = ModulVector(m_trianglePoints[0], m_trianglePoints[1], m_trianglePoints[2]);
	int	modulVectorOfFirstTriangleWithPoint = ModulVector(m_trianglePoints[0], m_trianglePoints[1], m_point);
	int	modulVectorOfSecondTriangleWithPoint = ModulVector(m_trianglePoints[1], m_trianglePoints[2], m_point);
	int	modulVectorOfThirdTriangleWithPoint = ModulVector(m_trianglePoints[0], m_trianglePoints[2], m_point);

	if (modulVectorOfFirstTriangleWithPoint + modulVectorOfSecondTriangleWithPoint + modulVectorOfThirdTriangleWithPoint - modulVectorOfTriandle > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void CPointInTriangle::Visualisation()
{	
	circle.setFillColor(sf::Color::Black);
	circle.setPosition((float)m_point.x + 300, (float)m_point.y + 300);

	convex.setFillColor(sf::Color::Cyan);
	convex.setPointCount(3);

	convex.setPoint(0, sf::Vector2f((float)m_trianglePoints[0].x + 300, (float)m_trianglePoints[0].y + 300));
	convex.setPoint(1, sf::Vector2f((float)m_trianglePoints[1].x + 300, (float)m_trianglePoints[1].y + 300));
	convex.setPoint(2, sf::Vector2f((float)m_trianglePoints[2].x + 300, (float)m_trianglePoints[2].y + 300));


	if (CheckPoint())
	{
		text.setString("Point in triangle ");
	}
	else
	{
		text.setString("Point not in triangle");
	}
}

void CPointInTriangle::draw(sf::RenderTarget & render, sf::RenderStates states) const
{
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
	render.draw(line1, 2, sf::Lines, states);
	render.draw(line2, 2, sf::Lines, states);
	render.draw(convex, states);
	render.draw(circle, states);
	//render.draw(text, states);
}

void CPointInTriangle::ReadInputFile(std::ifstream & fin)
{
	int x, y;
	for (int i = 0; i < 3; i++)
	{
		fin >> x >> y;
		m_trianglePoints.push_back({ x, y });
	}
	fin >> x >> y;
	m_point = {x, y};
	
}
