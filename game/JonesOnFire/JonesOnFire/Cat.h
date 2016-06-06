#pragma once
#include "stdafx.h"

class Cat {
public:
	Image image;
	Texture texture;
	Sprite sprite;

	Cat(String F, float X, float Y, float W, float H) {
		image.loadFromFile("images/" + F);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 150, 150, 150));
	}
};
