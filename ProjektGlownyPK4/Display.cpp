#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include <sstream>
#include <string>
#include <thread>
#include <mutex>
#include "Display.h"

using namespace std;
using namespace sf;


void Display::end() {
	RenderWindow window(VideoMode(1800, 980, 32), "Pokemon, New Edition!");//, Style::Fullscreen);
	Event event; 

	Font MyFont;
	MyFont.loadFromFile("pokemons.ttf");

	Text the_end;
	the_end.setFont(MyFont);
	the_end.setCharacterSize(56);
	the_end.setFillColor(Color::Red);
	the_end.setString("THE END");
	the_end.setPosition(Vector2f(700.f, 340.f));


	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left)
				{
					window.close();
				}
			}
		}
		window.clear(Color::Black);
		window.draw(the_end);
		window.display();
	}
}

void Display::end_win() {
	RenderWindow window(VideoMode(1800, 980, 32), "Pokemon, New Edition!");//, Style::Fullscreen);
	Event event;

	Font MyFont;
	MyFont.loadFromFile("pokemons.ttf");

	Text the_end;
	the_end.setFont(MyFont);
	the_end.setCharacterSize(56);
	the_end.setFillColor(Color::Red);
	the_end.setString("You are a winner !!");
	the_end.setPosition(Vector2f(500.f, 340.f));


	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left)
				{
					window.close();
				}
			}
		}
		window.clear(Color::Black);
		window.draw(the_end);
		window.display();
	}
}

void Display::tours(vector<string> winners, vector<string> enemy_names, string first_round_enemy_name, int round) {
	RenderWindow window(VideoMode(1800, 980, 32), "Pokemon, New Edition!");//, Style::Fullscreen);
	Event event;

	if (round == 0)
		first_enemy = first_round_enemy_name;
	Font MyFont;
	MyFont.loadFromFile("pokemons.ttf");

	if (winners.size() > 6)
	{
		for (auto x : winners) {
			winners1.push_back(x);
		}
	}

	else if (winners.size() > 3)
	{
		for (auto x : winners) {
			winners2.push_back(x);
		}
	}

	else if (winners.size() > 1)
	{
		for (auto x : winners) {
			winners3.push_back(x);
		}
	}
	Text winners_1;
	Text winners_2;
	Text winners_3;
	Text winners_4;
	Text winners_5;
	Text winners_6;
	Text winners_7;
	Text winners_8;
	Text winners__1;
	Text winners__2;
	Text winners__3;
	Text winners__4;
	Text winners___1;
	Text winners___2;
	if (round > 0)
	{
		//for (auto x : winners)
		//	winners1.push_back(x);

		winners_1.setFont(MyFont);
		winners_1.setCharacterSize(15);
		winners_1.setFillColor(Color::White);
		winners_1.setString(winners1[0]);
		winners_1.setPosition(Vector2f(71.f, 700.f));

		winners_2.setFont(MyFont);
		winners_2.setCharacterSize(15);
		winners_2.setFillColor(Color::White);
		winners_2.setString(winners1[1]);
		winners_2.setPosition(Vector2f(246.f, 700.f));

		winners_3.setFont(MyFont);
		winners_3.setCharacterSize(15);
		winners_3.setFillColor(Color::White);
		winners_3.setString(winners1[2]);
		winners_3.setPosition(Vector2f(417.f, 700.f));

		winners_4.setFont(MyFont);
		winners_4.setCharacterSize(15);
		winners_4.setFillColor(Color::White);
		winners_4.setString(winners1[3]);
		winners_4.setPosition(Vector2f(623.f, 700.f));

		winners_5.setFont(MyFont);
		winners_5.setCharacterSize(15);
		winners_5.setFillColor(Color::White);
		winners_5.setString(winners1[4]);
		winners_5.setPosition(Vector2f(827.f, 700.f));

		winners_6.setFont(MyFont);
		winners_6.setCharacterSize(15);
		winners_6.setFillColor(Color::White);
		winners_6.setString(winners1[5]);
		winners_6.setPosition(Vector2f(1075.f, 700.f));

		winners_7.setFont(MyFont);
		winners_7.setCharacterSize(15);
		winners_7.setFillColor(Color::White);
		winners_7.setString(winners1[6]);
		winners_7.setPosition(Vector2f(1282.f, 700.f));

		winners_8.setFont(MyFont);
		winners_8.setCharacterSize(15);
		winners_8.setFillColor(Color::White);
		winners_8.setString(winners1[7]);
		winners_8.setPosition(Vector2f(1536.f, 700.f));

	}
	if (round > 1)
	{
		//for (auto x : winners)
		//	winners2.push_back(x);

		winners__1.setFont(MyFont);
		winners__1.setCharacterSize(20);
		winners__1.setFillColor(Color::White);
		winners__1.setString(winners2[0]);
		winners__1.setPosition(Vector2f(146.f, 560.f));

		winners__2.setFont(MyFont);
		winners__2.setCharacterSize(20);
		winners__2.setFillColor(Color::White);
		winners__2.setString(winners2[1]);
		winners__2.setPosition(Vector2f(520.f, 560.f));

		winners__3.setFont(MyFont);
		winners__3.setCharacterSize(20);
		winners__3.setFillColor(Color::White);
		winners__3.setString(winners2[2]);
		winners__3.setPosition(Vector2f(969.f, 560.f));

		winners__4.setFont(MyFont);
		winners__4.setCharacterSize(20);
		winners__4.setFillColor(Color::White);
		winners__4.setString(winners2[3]);
		winners__4.setPosition(Vector2f(1406.f, 560.f));

	}
	if (round > 2)
	{
		//for (auto x : winners)
		//	winners1.push_back(x);

		winners___1.setFont(MyFont);
		winners___1.setCharacterSize(25);
		winners___1.setFillColor(Color::White);
		winners___1.setString(winners3[0]);
		winners___1.setPosition(Vector2f(340.f, 385.f));

		winners___2.setFont(MyFont);
		winners___2.setCharacterSize(25);
		winners___2.setFillColor(Color::White);
		winners___2.setString(winners3[1]);
		winners___2.setPosition(Vector2f(1190.f, 385.f));

	}
	Text _1_;
	_1_.setFont(MyFont);
	_1_.setCharacterSize(12);
	_1_.setFillColor(Color::White);
	_1_.setString(winners[0]);
	_1_.setPosition(Vector2f(32.f, 872.f));
	Text _2_;
	_2_.setFont(MyFont);
	_2_.setCharacterSize(12);
	_2_.setFillColor(Color::White);
	_2_.setString(first_enemy);
	_2_.setPosition(Vector2f(130.f, 872.f));
	Text _15_;
	_15_.setFont(MyFont);
	_15_.setCharacterSize(12);
	_15_.setFillColor(Color::White);
	_15_.setString(enemy_names[0]);
	_15_.setPosition(Vector2f(207.f, 872.f));
	Text _3_;
	_3_.setFont(MyFont);
	_3_.setCharacterSize(12);
	_3_.setFillColor(Color::White);
	_3_.setString(enemy_names[1]);
	_3_.setPosition(Vector2f(294.f, 872.f));
	Text _4_;
	_4_.setFont(MyFont);
	_4_.setCharacterSize(12);
	_4_.setFillColor(Color::White);
	_4_.setString(enemy_names[2]);
	_4_.setPosition(Vector2f(383.f, 872.f));
	Text _5_;
	_5_.setFont(MyFont);
	_5_.setCharacterSize(12);
	_5_.setFillColor(Color::White);
	_5_.setString(enemy_names[3]);
	_5_.setPosition(Vector2f(466.f, 872.f));
	Text _6_;
	_6_.setFont(MyFont);
	_6_.setCharacterSize(12);
	_6_.setFillColor(Color::White);
	_6_.setString(enemy_names[4]);
	_6_.setPosition(Vector2f(575.f, 872.f));
	Text _7_;
	_7_.setFont(MyFont);
	_7_.setCharacterSize(12);
	_7_.setFillColor(Color::White);
	_7_.setString(enemy_names[5]);
	_7_.setPosition(Vector2f(673.f, 872.f));
	Text _8_;
	_8_.setFont(MyFont);
	_8_.setCharacterSize(12);
	_8_.setFillColor(Color::White);
	_8_.setString(enemy_names[6]);
	_8_.setPosition(Vector2f(797.f, 872.f));
	Text _9_;
	_9_.setFont(MyFont);
	_9_.setCharacterSize(12);
	_9_.setFillColor(Color::White);
	_9_.setString(enemy_names[7]);
	_9_.setPosition(Vector2f(894.f, 872.f));
	Text _10_;
	_10_.setFont(MyFont);
	_10_.setCharacterSize(12);
	_10_.setFillColor(Color::White);
	_10_.setString(enemy_names[8]);
	_10_.setPosition(Vector2f(1037.f, 872.f));
	Text _11_;
	_11_.setFont(MyFont);
	_11_.setCharacterSize(12);
	_11_.setFillColor(Color::White);
	_11_.setString(enemy_names[9]);
	_11_.setPosition(Vector2f(1131.f, 872.f));
	Text _12_;
	_12_.setFont(MyFont);
	_12_.setCharacterSize(12);
	_12_.setFillColor(Color::White);
	_12_.setString(enemy_names[10]);
	_12_.setPosition(Vector2f(1251.f, 872.f));
	Text _13_;
	_13_.setFont(MyFont);
	_13_.setCharacterSize(12);
	_13_.setFillColor(Color::White);
	_13_.setString(enemy_names[11]);
	_13_.setPosition(Vector2f(1327.f, 872.f));
	Text _14_;
	_14_.setFont(MyFont);
	_14_.setCharacterSize(12);
	_14_.setFillColor(Color::White);
	_14_.setString(enemy_names[12]);
	_14_.setPosition(Vector2f(1474.f, 872.f));
	Text _16_;
	_16_.setFont(MyFont);
	_16_.setCharacterSize(12);
	_16_.setFillColor(Color::White);
	_16_.setString(enemy_names[13]);
	_16_.setPosition(Vector2f(1610.f, 872.f));
	
	Text winnee;
	if (round > 3) {
		winnee.setFont(MyFont);
		winnee.setCharacterSize(40);
		winnee.setFillColor(Color::White);
		winnee.setString(winners[0]);
		winnee.setPosition(Vector2f(678.f, 89.f));
	}

	Texture drabinka;
	drabinka.loadFromFile("drabinka.png");
	sf::Sprite sprite_map;
	sprite_map.setTexture(drabinka);
	sprite_map.setScale((float)window.getSize().x / (float)drabinka.getSize().x, (float)window.getSize().y / (float)drabinka.getSize().y);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left)
				{
					cout << "X:" << event.mouseButton.x << endl;
					cout << "Y:" << event.mouseButton.y << endl;
				}
				window.close();
			}
		}
		window.clear(Color::Black);
		window.draw(sprite_map);
		window.draw(_1_);
		window.draw(_2_);
		window.draw(_3_);
		window.draw(_4_);
		window.draw(_5_);
		window.draw(_6_);
		window.draw(_7_);
		window.draw(_8_);
		window.draw(_9_);
		window.draw(_10_);
		window.draw(_11_);
		window.draw(_12_);
		window.draw(_13_);
		window.draw(_14_);
		window.draw(_15_);
		window.draw(_16_);
		window.draw(winners_1);
		window.draw(winners_2);
		window.draw(winners_3);
		window.draw(winners_4);
		window.draw(winners_5);
		window.draw(winners_6);
		window.draw(winners_7);
		window.draw(winners_8);
		window.draw(winners__1);
		window.draw(winners__2);
		window.draw(winners__3);
		window.draw(winners__4);
		window.draw(winners___1);
		window.draw(winners___2);
		window.draw(winnee);

		window.display();
	}

}
