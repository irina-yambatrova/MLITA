#pragma once
#include "stdafx.h"

using namespace sf;

sf::View view;//объявили sfml объект "вид", который и является камерой

void getplayercoordinateforview(float x, float y) 
{
	float tempX = x; float tempY = y;//считываем коорд игрока и проверяем их, чтобы убрать края

	
	if (x <= 490) tempX = 490;//убираем из вида левую сторону	

	view.setCenter(tempX, tempY); //следим за игроком, передавая его координаты. 

}
