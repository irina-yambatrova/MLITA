
#include <SFML/Graphics.hpp> 
using namespace sf;

void menu(RenderWindow & window)
{
	Texture menuTexture1, menuTexture2, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("images/1.png");
	menuTexture2.loadFromFile("images/2.png");
	menuBackground.loadFromFile("images/menu.jpg");
	Sprite menu1(menuTexture1), menu2(menuTexture2), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(780, 529);
	menu2.setPosition(80, 529);
	menuBg.setPosition(0, 0);
	//////////////////////////////лемч///////////////////
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(140, 200, 240));
		if (IntRect(780, 529, 300, 60).contains(Mouse::getPosition(window))) 
		{
			menu1.setColor(Color::Black); 
			menuNum = 1; 
		} 
		if (IntRect(80, 529, 300, 60).contains(Mouse::getPosition(window))) 
		{ 
			menu2.setColor(Color::Black); 
			menuNum = 2; 
		}
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) 
			{
				isMenu = false;
			}	
			if (menuNum == 2) 
			{	 
				window.close(); 
				isMenu = false; 
			}
		}
		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.display();
	}	////////////////////////////////////////////////////
}

bool startGame()
{
	RenderWindow window(sf::VideoMode(800, 400), "Jones on Fire");
	menu(window);
	return 0;
}