#pragma once
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <chrono>
#include <SFML/Graphics.hpp>

class CPointInTriangle : public sf::Drawable
{
public:
	CPointInTriangle(std::ifstream & fin);
	bool CheckPoint();
	void Visualisation();
	void draw(sf::RenderTarget & render, sf::RenderStates states)const override;
private:
	void ReadInputFile(std::ifstream & fin);
	sf::Vector2i m_point;
	std::vector<sf::Vector2i> m_trianglePoints;
	int ModulVector(sf::Vector2i & a, sf::Vector2i & b, sf::Vector2i & c);
	sf::ConvexShape convex;
	sf::CircleShape circle;
	sf::Text text;
};

