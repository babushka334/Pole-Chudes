#pragma once
#pragma warning(disable : 4996)
#include "Letters.h"
#include <string>
#include <iostream>
class Word
{
public:
	string word;
	vector<Sprite> hide_letters;
	Image heroimage;
	Texture herotexture;
	Word(string word)
	{
		heroimage.loadFromFile("images/ вадратик.png");
		this->word = word;
		Sprite herosprite;
		herotexture.loadFromImage(heroimage);
		for (int i = 0; i < this->word.length(); i++)
		{
			herosprite.setTexture(herotexture);
			herosprite.setTextureRect(IntRect(0, 0, 133, 80));
			hide_letters.push_back(herosprite);
		}
	}
	void checkLetter(Letters &let)
	{
		bool flag = false;
		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] == let.letter)
			{
				hide_letters[i] = let.image;
				hide_letters[i].setColor(Color::Green);
				hide_letters[i].setPosition(580 + 133 * i, 400);
				flag = true;
			}
		}
		if (flag)
		{
			let.boo = 2;
			let.image.setColor(Color::Green);
		}
		else
		{
			let.boo = 0;
			let.image.setColor(Color::Red);
		}

	}
	int UnicLettters()
	{
		int k = 0;
		for (int i = 0; i < word.length(); i++)
			for (int j = i + 1; j < word.length(); j++)
				if (word[i] == word[j])
					k++;
		return word.length() - k;
	}
};