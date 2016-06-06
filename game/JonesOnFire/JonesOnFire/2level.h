class Fire
{
public:
	float x, y, w, h, speed;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	Fire(String F, float X, float Y, float W, float H)
	{
		File = "fire1.png";
		image.loadFromFile("images/" + File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = 559; y = 418;
		sprite.setTextureRect(IntRect(0, 100, 100, 100));
		sprite.setPosition(x, y);
	}
}; 
Fire f("fire1.png", 0, 100, 100, 100);
f.sprite.setTextureRect(IntRect(0, 90 * int(currentFrameCats), 100, 90));
if (currentFrameCats > 2)
{
	currentFrameCats = 0;
}
