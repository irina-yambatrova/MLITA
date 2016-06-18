// RGR.cpp: определяет точку входа для консольного приложения.
//

#include <SFML/Graphics.hpp>

#include "stdafx.h"
#include "Application.h"

using namespace sf;
using namespace std;

int main()
{
	sf::Font font;
	if (!font.loadFromFile("myFont.otf"))
	{
		return EXIT_FAILURE;
	}
	auto window = make_unique<sf::RenderWindow>(VideoMode(800, 600), "RGR");
	
	CApplication app(move(window));
	app.Run();
	return 0;
}

