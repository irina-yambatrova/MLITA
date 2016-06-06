#pragma once
const int ground = 420;


class Player
{
private: float x, y;
public:
	float w, h, dx, dy, speed;
	int dir, playerScore;//новая переменная, хранящая очки игрока
	bool onGround;
	Sprite sprite;
	FloatRect rect;
	float currentFrame;

	Player(Texture &image) {
		dx = dy = 0.01;
		playerScore = 0;
		rect = FloatRect(0, 0, 40, 60);
		sprite.setTexture(image);
		currentFrame = 0;
	}

	void update(float time)
	{
		rect.left += dx * time;
		if (!onGround) dy = dy + 0.0005 * time;
		rect.top += dy * time;
		onGround = false;
		if (rect.top > ground)
		{
			rect.top = ground;
			dy = 0;
			onGround = true;
		}
		currentFrame += 000.1 * time;
		if (currentFrame > 2) currentFrame -= 2;
		if (dx > 0)
		{
			sprite.setTextureRect(IntRect(100, 100 * int(currentFrame), 100, 100));
		}
		if (dx < 0)
		{
			sprite.setTextureRect(IntRect(0, 100 * int(currentFrame), 100, 100));
		}
		sprite.setPosition(rect.left, rect.top);
	}
	float getplayercoordinateX()
	{
		return x;
	}
	float getplayercoordinateY()
	{
		return y;
	}

};