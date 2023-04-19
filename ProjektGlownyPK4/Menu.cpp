#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <ranges>
#include "Menu.h"

using namespace std;
using namespace sf;

	Menu::Menu() {
		screen = 0;
		ex = true;
	}
	bool Menu::quit() {
		return ex;
	}
	vector<string> read_leaders() {

		vector<string> leaders;
		namespace x = filesystem;

		ifstream file_o("nicknames.txt");
		string line;
		while(getline(file_o, line))
		{
			if (line.size() > 0) {
				leaders.push_back(line);
			}
		}
		if (leaders.size() < 8)
		{
			int hlp = 8 - leaders.size();
			for (int i = 0; i < hlp; i++)
			{
				leaders.push_back("--");
			}
		}
		file_o.close();

		ranges::sort(leaders);

		return leaders;
	}
	void Menu::show_Menu() {
		RenderWindow window(VideoMode(1800, 980, 32), "Pokemon, New Edition!");//, Style::Fullscreen);

		sf::Texture texture_startscreen;
		Texture texture_options;
		texture_startscreen.loadFromFile("screenstart.jpg");
		texture_options.loadFromFile("options.png");

		texture_startscreen.setSmooth(true);
		sf::Sprite sprite_menu;
		sf::Sprite sprite_options;
		sprite_menu.setTexture(texture_startscreen);
		sprite_options.setTexture(texture_options);
		sprite_options.setPosition(Vector2f(1000.f, 550.f));
		sprite_options.setScale(1.f, 1.2f);
		sprite_menu.setScale((float)window.getSize().x / (float)texture_startscreen.getSize().x, (float)window.getSize().y / (float)texture_startscreen.getSize().y);

		Event event;

		Font MyFont;
		MyFont.loadFromFile("pokemons.ttf");

		Text Back;
		Back.setFont(MyFont);
		Back.setString("Back");
		Back.setCharacterSize(50);
		Back.setFillColor(Color::White);
		Back.setPosition(Vector2f(120.f, 875.f));

		Text Play;
		Play.setFont(MyFont);
		Play.setString("Play!");
		Play.setCharacterSize(60);
		Play.setPosition(Vector2f(1105.f, 630.f));

		Text Exit;
		Exit.setFont(MyFont);
		Exit.setString("Exit");
		Exit.setCharacterSize(60);
		Exit.setPosition(Vector2f(1430.f, 630.f));

		Text Leaderboard;
		Leaderboard.setFont(MyFont);
		Leaderboard.setString("Leaderboard :");
		Leaderboard.setCharacterSize(50);
		Leaderboard.setFillColor(Color::White);
		Leaderboard.setPosition(Vector2f(700.f, 0.f));

		Text Leaderboard_;
		Leaderboard_.setFont(MyFont);
		Leaderboard_.setString("Leaderboard");
		Leaderboard_.setCharacterSize(50);
		Leaderboard_.setFillColor(Color::Yellow);
		Leaderboard_.setPosition(Vector2f(1088.f, 765.f));

		vector<string> leaders = read_leaders();

		Text Player1;
		Player1.setFont(MyFont);
		Player1.setString(leaders[0]);
		Player1.setCharacterSize(50);
		Player1.setFillColor(Color::White);
		Player1.setPosition(Vector2f(50.f, 100.f));

		Text _1_;
		_1_.setFont(MyFont);
		_1_.setString("1.");
		_1_.setCharacterSize(50);
		_1_.setFillColor(Color::White);
		_1_.setPosition(Vector2f(0.f, 100.f));

		Text _2_;
		_2_.setFont(MyFont);
		_2_.setString("2.");
		_2_.setCharacterSize(50);
		_2_.setFillColor(Color::White);
		_2_.setPosition(Vector2f(0.f, 200.f));

		Text _3_;
		_3_.setFont(MyFont);
		_3_.setString("3.");
		_3_.setCharacterSize(50);
		_3_.setFillColor(Color::White);
		_3_.setPosition(Vector2f(0.f, 300.f));

		Text _4_;
		_4_.setFont(MyFont);
		_4_.setString("4.");
		_4_.setCharacterSize(50);
		_4_.setFillColor(Color::White);
		_4_.setPosition(Vector2f(0.f, 400.f));

		Text _5_;
		_5_.setFont(MyFont);
		_5_.setString("5.");
		_5_.setCharacterSize(50);
		_5_.setFillColor(Color::White);
		_5_.setPosition(Vector2f(0.f, 500.f));

		Text _6_;
		_6_.setFont(MyFont);
		_6_.setString("6.");
		_6_.setCharacterSize(50);
		_6_.setFillColor(Color::White);
		_6_.setPosition(Vector2f(0.f, 600.f));

		Text _7_;
		_7_.setFont(MyFont);
		_7_.setString("7.");
		_7_.setCharacterSize(50);
		_7_.setFillColor(Color::White);
		_7_.setPosition(Vector2f(0.f, 700.f));

		Text _8_;
		_8_.setFont(MyFont);
		_8_.setString("8.");
		_8_.setCharacterSize(50);
		_8_.setFillColor(Color::White);
		_8_.setPosition(Vector2f(0.f, 800.f));

		Text Player2;
		Player2.setFont(MyFont);
		Player2.setString(leaders[1]);
		Player2.setCharacterSize(50);
		Player2.setFillColor(Color::White);
		Player2.setPosition(Vector2f(50.f, 200.f));

		Text Player3;
		Player3.setFont(MyFont);
		Player3.setString(leaders[2]);
		Player3.setCharacterSize(50);
		Player3.setFillColor(Color::White);
		Player3.setPosition(Vector2f(50.f, 300.f));

		Text Player4;
		Player4.setFont(MyFont);
		Player4.setString(leaders[3]);
		Player4.setCharacterSize(50);
		Player4.setFillColor(Color::White);
		Player4.setPosition(Vector2f(50.f, 400.f));

		Text Player5;
		Player5.setFont(MyFont);
		Player5.setString(leaders[4]);
		Player5.setCharacterSize(50);
		Player5.setFillColor(Color::White);
		Player5.setPosition(Vector2f(50.f, 500.f));

		Text Player6;
		Player6.setFont(MyFont);
		Player6.setString(leaders[5]);
		Player6.setCharacterSize(50);
		Player6.setFillColor(Color::White);
		Player6.setPosition(Vector2f(50.f, 600.f));

		Text Player7;
		Player7.setFont(MyFont);
		Player7.setString(leaders[6]);
		Player7.setCharacterSize(50);
		Player7.setFillColor(Color::White);
		Player7.setPosition(Vector2f(50.f, 700.f));

		Text Player8;
		Player8.setFont(MyFont);
		Player8.setString(leaders[7]);
		Player8.setCharacterSize(50);
		Player8.setFillColor(Color::White);
		Player8.setPosition(Vector2f(50.f, 800.f));

		Text HowTo;
		HowTo.setFont(MyFont);
		HowTo.setString("?");
		HowTo.setCharacterSize(60);
		HowTo.setFillColor(Color::Yellow);
		HowTo.setPosition(Vector2f(1534.f, 764.f));

		Texture howto;
		howto.loadFromFile("HowTo.png");

		sf::Sprite sprite_howto;
		sprite_howto.setTexture(howto);
		sprite_howto.setScale((float)window.getSize().x / (float)howto.getSize().x, (float)window.getSize().y / (float)howto.getSize().y);


		while (window.isOpen())
		{
			while (window.pollEvent(event))
			{
				//if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				//	window.close();

				if (event.type == Event::MouseButtonPressed) {
					if (event.mouseButton.button == Mouse::Left)
					{
						cout << "X:" << event.mouseButton.x << endl;
						cout << "Y:" << event.mouseButton.y << endl;
						if (screen == 0) {
							if ((event.mouseButton.x >= 1424 && event.mouseButton.x <= 1563) &&
								(event.mouseButton.y >= 636 && event.mouseButton.y <= 711))
							{
								ex = false;
								window.close();
								quit();
							}
							else if ((event.mouseButton.x >= 1102 && event.mouseButton.x <= 1239) &&
								(event.mouseButton.y >= 636 && event.mouseButton.y <= 711))
							{
								screen = 1;
							}
							else if ((event.mouseButton.x >= 1086 && event.mouseButton.x <= 1381) &&
								(event.mouseButton.y >= 770 && event.mouseButton.y <= 847))
							{
								screen = 3;
							}
							else if ((event.mouseButton.x >= 1527 && event.mouseButton.x <= 1579) &&
								(event.mouseButton.y >= 766 && event.mouseButton.y <= 831))
							{
								screen = 2;
							}
						}
						else if (screen == 2)
						{
							if ((event.mouseButton.x >= 114 && event.mouseButton.x <= 234) &&
								(event.mouseButton.y >= 876 && event.mouseButton.y <= 935))
							{
								screen = 0;
							}
						}
						else if (screen == 3)
						{
							if ((event.mouseButton.x >= 114 && event.mouseButton.x <= 234) &&
								(event.mouseButton.y >= 876 && event.mouseButton.y <= 935))
							{
								screen = 0;
							}

						}
					}
				}
			}
			window.clear(Color::Black);

			Vector2i mousePositionwindow = Mouse::getPosition(window);

			if ((mousePositionwindow.x >= 1102 && mousePositionwindow.x < 1239) &&
				(mousePositionwindow.y > 636 && mousePositionwindow.y < 711))
			{
				Play.setFillColor(Color::Red);
			}
			else
				Play.setFillColor(Color::Yellow);

			if ((mousePositionwindow.x >= 1424 && mousePositionwindow.x < 1563) &&
				(mousePositionwindow.y > 636 && mousePositionwindow.y < 711))
			{
				Exit.setFillColor(Color::Red);
			}
			else
				Exit.setFillColor(Color::Yellow);

			if ((mousePositionwindow.x >= 1086 && mousePositionwindow.x <= 1381) &&
				(mousePositionwindow.y >= 770 && mousePositionwindow.y <= 847))
			{
				Leaderboard_.setFillColor(Color::Red);
			}
			else
				Leaderboard_.setFillColor(Color::Yellow);

			if ((mousePositionwindow.x >= 1527 && mousePositionwindow.x <= 1579) &&
				(mousePositionwindow.y >= 766 && mousePositionwindow.y <= 831))
			{
				HowTo.setFillColor(Color::Red);
			}
			else
				HowTo.setFillColor(Color::Yellow);


			if ((mousePositionwindow.x >= 114 && mousePositionwindow.x <= 234) &&
				(mousePositionwindow.y >= 876 && mousePositionwindow.y <= 935))
			{
				Back.setFillColor(Color::Red);
			}
			else
				Back.setFillColor(Color::White);

			//poczatkowe menu
			if (screen == 0) {
				window.draw(sprite_menu);
				window.draw(sprite_options);
				window.draw(Play);
				window.draw(Exit);
				window.draw(Leaderboard_);
				window.draw(HowTo);
				window.display();
			}
			//play
			else if (screen == 1) {
				window.close();
			}
			//jak grac
			else if (screen == 2) {
				window.draw(sprite_howto);
				window.draw(Back);
				window.display();
			}
			else if (screen == 3) {
				window.draw(Leaderboard);
				window.draw(Back);
				window.draw(Player1);
				window.draw(Player2);
				window.draw(Player3);
				window.draw(Player4);
				window.draw(Player5);
				window.draw(Player6);
				window.draw(Player7);
				window.draw(Player8);
				window.draw(_1_);
				window.draw(_2_);
				window.draw(_3_);
				window.draw(_4_);
				window.draw(_5_);
				window.draw(_6_);
				window.draw(_7_);
				window.draw(_8_);
				window.display();
			}
		}

	}

