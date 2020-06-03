#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;


class Letters
{
public:
	Sprite image;
	char letter;
	Image heroimage;
	Texture herotexture;
	int boo;
	Letters(char let,int  x0, int  y0, int x1, int y1)
	{
		
		heroimage.loadFromFile("images/Алфавит.png");
		//heroimage.createMaskFromColor(Color(255, 255, 255));

		
		herotexture.loadFromImage(heroimage);
		boo = 1;
		letter = let;
		image.setTexture(herotexture);
		image.setTextureRect(IntRect(x0, y0, x1, y1));
		
	}
};
