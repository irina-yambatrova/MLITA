#include "stdafx.h"
#include "Player.h"
#include "Cat.h"
#include "View.h"

using namespace sf;


int main()
{
	RenderWindow window(sf::VideoMode(980, 600), "Jones On Fire");
	view.reset(sf::FloatRect(0, 0, 980, 600));//размер "вида" камеры при создании объекта вида камеры. (потом можем менять как хотим) Что то типа инициализации.
	Music musiccat;//
	musiccat.openFromFile("menu.ogg");
	musiccat.setVolume(100);
	musiccat.play();

	//menu(window);

	Music musicMain;//
	musicMain.openFromFile("main.ogg");
	musicMain.setVolume(100);
	musicMain.play();


	Texture t;
	t.loadFromFile("images/man1.png");
	float CurrentFrame = 0;
	Player p(t);

	Cat cat1("cat2.png", 0, 60, 60, 60);
	cat1.sprite.setPosition(480, 210);
	Cat cat2("cat2.png", 60, 60, 60, 60);
	cat2.sprite.setPosition(666, 220);
	Cat cat3("cat2.png", 0, 60, 60, 60);
	cat3.sprite.setPosition(555, 240);

	int dir;
	float currentFrameCats = 0;
	Image map_image;
	map_image.loadFromFile("images/map2.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;

	s_map.setTexture(map);
	Texture maptexture;
	maptexture.loadFromFile("images/map2.png");

	Sprite mapsprite;
	mapsprite.setTexture(maptexture);
	mapsprite.setTextureRect(IntRect(0, 0, 980, 600));
	mapsprite.setPosition(0, 0);

	float coordinatePlayerX, coordinatePlayerY = 0;
	coordinatePlayerX = p.getplayercoordinateX();
	coordinatePlayerY = p.getplayercoordinateY();

	Clock clock; 
	RectangleShape rectangle(Vector2f(32, 32));

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds(); 
		clock.restart();
		time = time / 800; 

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if ((Keyboard::isKeyPressed(Keyboard::Left) )) 
		{
			p.dx = -0.1;
			std::cout << p.getplayercoordinateX() << ", " << p.getplayercoordinateY() << std::endl;
			getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());//передаем координаты игрока в функцию управления камерой
		}
		
		if ((Keyboard::isKeyPressed(Keyboard::Right) )) 
		{
			p.dx =  +0.1; 
			//getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());//передаем координаты игрока в функцию управления камерой
		}
		if ((Keyboard::isKeyPressed(Keyboard::Up))) 
		{
			if (p.onGround)
			{
				p.dy = -0.45;
				p.onGround = false;
			}; 
		}

		currentFrameCats += time * 0.005;
		if (currentFrameCats > 2)
		{
			currentFrameCats = 0;
		}
			cat1.sprite.setTextureRect(IntRect(0, 60 * int(currentFrameCats), 60, 60));
			cat2.sprite.setTextureRect(IntRect(60,60 * int(currentFrameCats), 60, 60));
			cat3.sprite.setTextureRect(IntRect(0, 60 * int(currentFrameCats), 60, 60));

		
		p.update(time);
		window.setView(view);//"оживляем" камеру в окне sfml
		window.clear();
		window.setView(view);//"оживляем" камеру в окне sfml
		window.draw(mapsprite);

		window.draw(p.sprite);
		window.draw(cat1.sprite);
		window.draw(cat2.sprite);
		window.draw(cat3.sprite);
		window.display();
	}
	return 0;
}