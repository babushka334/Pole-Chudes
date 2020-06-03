#include "Task.h"
void changeLevel(string& word, string& question, int& level)
{
	if (level == 3) { word = "пиво"; question = "В XIII веке в некоторых регионах Норвегии\nЭТО использовалось для крещения детей.\nПо имеющимся данным, причиной тому являлась\nнехватка чистой воды на указанных территориях.\nПозднее, папа римский Григорий IX издал указ,\nсогласно которому все церемонии крещения\nс использованием ЭТОГО признавались\nнедействительными. Назовите ЭТО"; }
	if (level == 2) { word = "багаж"; question = "Польская журналистка и писательница\nЯнина Ипохорская говорила: \n«Взгляд одной женщины на другую напоминает\nконтроль...»"; }
	if (level == 1) { word = "война"; question = "Какого слова нет в языке народов Арктики?"; }
}

bool StartGame(int& level, RenderWindow &window)
{
	system("chcp 1251");
	setlocale(LC_ALL, "rus");
	;
	string word = "";
	string question = "";
	
	changeLevel(word, question, level);

	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	Text text("", font, 30);
	text.setColor(Color::White);
	text.setStyle(Text::Bold);

	Font font2;
	font2.loadFromFile("19458.ttf");
	Text text2("", font2, 60);
	text2.setColor(Color::Cyan);
	text2.setStyle(Text::Bold);

	Word password(word);
	for (int i = 0; i < password.hide_letters.size(); i++)
		password.hide_letters[i].setPosition(580 + 133 * i, 400);


	bool flag = true;
	vector<Letters> letters_vect;
	int menuNum;
	for (int j = 0; j < 8; j++)
		for (int i = 0; i < 4; i++)
		{
			if (flag)
				if (letters_vect.size() == 6)
				{
					flag = false;
					continue;
				}
			Letters herosprite('а' + letters_vect.size(), 133 * i, 80 * j, 133, 80);

			letters_vect.push_back(herosprite);
		}
	Letters herosprite3('а' + letters_vect.size(), 0, 80 * 8, 133, 80);
	letters_vect.push_back(herosprite3);
	for (int j = 0, k = 0; j < 8; j++)
		for (int i = 0; i < 4; i++)
		{
			letters_vect[k].image.setPosition(133 * i, 80 * j);
			k++;
		}
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		for (int i = 0; i < letters_vect.size(); i++)
		{
			if (letters_vect[i].boo == 1)
				letters_vect[i].image.setColor(Color::Yellow);
			else
				if (letters_vect[i].boo)
					letters_vect[i].image.setColor(Color::Green);
				else
					letters_vect[i].image.setColor(Color::Red);
		}

		for (int j = 0, k = 0; j < 8; j++)
			for (int i = 0; i < 4; i++)
			{
				if (IntRect(133 * i, 80 * j, 133, 80).contains(Mouse::getPosition(window)))
				{
					letters_vect[k].image.setColor(Color::Blue);

					menuNum = k;
				}
				k++;
			}
		if (IntRect(0, 80 * 8, 133, 80).contains(Mouse::getPosition(window)))
		{
			letters_vect[32].image.setColor(Color::Blue);
			menuNum = 32;
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			password.checkLetter(letters_vect[menuNum]);
			
		}
		bool check = false;
		int k = 0;
		for (int i = 0; i < letters_vect.size(); i++)
		{
			if (letters_vect[i].boo == 2)
				k++;
		}
		

		window.clear();
		text.setString(question);
		text.setPosition(550, 130);
		text2.setString("GOOD JOB! PRESS F TO NEXT LEVEL");
		text2.setPosition(50, 640);
		window.draw(text);
		for (int i = 0; i < password.hide_letters.size(); i++)
			window.draw(password.hide_letters[i]);
		
		for (int i = 0; i < letters_vect.size(); i++)
		{
			window.draw(letters_vect[i].image);
		}
		if (k == password.UnicLettters())
		{
			window.draw(text2);
			if (Keyboard::isKeyPressed(Keyboard::F)) {return true;}
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {return false;}
		}
		window.display();
	}

	return 0;
}
void GameRunning(int& level, RenderWindow &window)
{
	if (StartGame(level, window))
	{
		level++;
		GameRunning(level, window);
	}
}

int main()
{
	RenderWindow window(sf::VideoMode(1280, 720), "Pole Chudes"/*,Style::Fullscreen*/);
	int level = 1;
	GameRunning(level, window);
	return 0;
}
