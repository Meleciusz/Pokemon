#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <string>
#include "Player.h";
#include "Pokemon.h";

using namespace std;
using namespace sf;

	Player::Player() {
		
	}
	bool Player::regex_nick() {

		string line;
		bool poprawnosc = false;
		bool same = false;
		int i = 0;

		regex pattern("[a-zA-Z]+");


		if (regex_match(nick, pattern))
		{
			poprawnosc = true;
			return true;
		}
		else
			return false;
	}
	bool Player::again() {

		fstream file("nicknames.txt");
		string line;
		while (getline(file, line))
		{
			if (line.size() > 0) {
				int xp__;
				string nick_;
				stringstream ss(line);
				if (ss >> nick_ >> xp__)
				{
					if (nick == nick_)
					{
						return true;
					}
				}
			}
		}
		file.close();
		return false;
	}
	void Player::load_nick() {

		bool not_good_ = false;
		RenderWindow window(VideoMode(1800, 980, 32), "Pokemon, New Edition!");//, Style::Fullscreen);
		Event event;

		Text playerText;

		Font MyFont;
		MyFont.loadFromFile("pokemons.ttf");
		playerText.setFont(MyFont);
		playerText.setCharacterSize(50);
		playerText.setFillColor(Color::Green);
		playerText.setPosition(Vector2f(50.f, 381.f));

		Text enter_nck;
		enter_nck.setFont(MyFont);
		enter_nck.setCharacterSize(50);
		enter_nck.setFillColor(Color::White);
		enter_nck.setString("Enter ur nickname :");
		enter_nck.setPosition(Vector2f(50.f, 280.f));

		Text not_good;
		not_good.setFont(MyFont);
		not_good.setCharacterSize(50);
		not_good.setFillColor(Color::White);
		not_good.setString("Nick nie spelnia wymagan, lub juz istnieje!");
		not_good.setPosition(Vector2f(50.f, 500.f));

		RectangleShape rectangle;
		rectangle.setSize(Vector2f(window.getSize().x, 80.f));
		rectangle.setPosition(Vector2f(0.f, 371.f));
		Color color(40, 40, 40);
		rectangle.setFillColor(color);


		while (window.isOpen())
		{
			while (window.pollEvent(event)) {

				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
					if (regex_nick() == true )
					{
						if (again() == false)
						{
							window.close();
							choose_ur_pokemon();
						}
						else
							not_good_ = true;
					}
					else
						not_good_ = true;

				else if (event.type == Event::TextEntered)
				{
					if (event.text.unicode == 8)
					{
						if (nick.size() > 0) {
							nick.erase(nick.size() - 1, 1);
							playerText.setString(nick);
						}
					}
					else if (event.text.unicode < 128 && event.text.unicode > 32)
					{
						nick += event.text.unicode;
						playerText.setString(nick); // ascii
					}
				}

				else if (event.type == Event::MouseButtonPressed) {
					if (event.mouseButton.button == Mouse::Left)
					{
						cout << "X:" << event.mouseButton.x << endl;
						cout << "Y:" << event.mouseButton.y << endl;

					}
				}
			}
			window.clear(Color::Black);
			window.draw(enter_nck);
			window.draw(rectangle);
			window.draw(playerText);
			if (not_good_ == true)
				window.draw(not_good);
			window.display();
		}
	}
	void Player::choose_ur_pokemon() {
		RenderWindow window(VideoMode(1800, 980, 32), "Pokemon, New Edition!");//, Style::Fullscreen);
		Event event;

		Font MyFont;
		MyFont.loadFromFile("pokemons.ttf");

		Text text;
		text.setFont(MyFont);
		text.setCharacterSize(50);
		text.setString("Choose ur pokemon : ");
		text.setFillColor(Color::Black);
		text.setPosition(Vector2f(100.f, 100.f));
		Text charma;
		charma.setFont(MyFont);
		charma.setCharacterSize(50);
		charma.setString("Charmander");
		charma.setFillColor(Color::Red);
		charma.setPosition(Vector2f(350.f, 760.f));
		Text bulbo;
		bulbo.setFont(MyFont);
		bulbo.setCharacterSize(50);
		bulbo.setString("Bulbqsaur");
		bulbo.setFillColor(Color::Green);
		bulbo.setPosition(Vector2f(780.f, 760.f));
		Text pika;
		pika.setFont(MyFont);
		pika.setCharacterSize(50);
		pika.setString("Pikachu");
		pika.setFillColor(Color::Yellow);
		pika.setPosition(Vector2f(1195.f, 760.f));

		sf::Texture charmander;
		Texture bulbosaur;
		Texture pikachu;
		charmander.loadFromFile("charmander.png");
		bulbosaur.loadFromFile("bulbosaur.png");
		pikachu.loadFromFile("pika.png");

		sf::Sprite sprite_char;
		sf::Sprite sprite_bul;
		sf::Sprite sprite_pika;
		sprite_char.setTexture(charmander);
		sprite_bul.setTexture(bulbosaur);
		sprite_pika.setTexture(pikachu);
		sprite_char.setPosition(Vector2f(400.f, 550.f));
		sprite_bul.setPosition(Vector2f(800.f, 550.f));
		sprite_pika.setPosition(Vector2f(1200.f, 550.f));
		sprite_pika.setScale(0.2f, 0.2f);

		while (window.isOpen())
		{
			while (window.pollEvent(event))
			{

				if (event.type == Event::MouseButtonPressed) {
					/*if (event.mouseButton.button == Mouse::Left)
					{
						cout << "X:" << event.mouseButton.x << endl;
						cout << "Y:" << event.mouseButton.y << endl;
					}*/
					if ((event.mouseButton.x >= 346 && event.mouseButton.x <= 642) &&
						(event.mouseButton.y >= 547 && event.mouseButton.y <= 811))
					{
						window.close();
						Player::pokemon_name = "Charmander";
						Pokemon::read();
						hp = Pokemon::give_hp(pokemon_name);
					}
					else if ((event.mouseButton.x >= 774 && event.mouseButton.x <= 1019) &&
						(event.mouseButton.y >= 551 && event.mouseButton.y <= 820))
					{
						window.close();
						Player::pokemon_name = "Bulbasaur";
						Pokemon::read();
						hp = give_hp(pokemon_name);
					}
					else if ((event.mouseButton.x >= 1190 && event.mouseButton.x <= 1397) &&
						(event.mouseButton.y >= 552 && event.mouseButton.y <= 820))
					{
						window.close();
						Player::pokemon_name = "Pikachu";
						Pokemon::read();
						hp = give_hp(pokemon_name);
					}
				}
				else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
					window.close();
			}

			Vector2i mousePositionwindow = Mouse::getPosition(window);
			if ((mousePositionwindow.x >= 346 && mousePositionwindow.x <= 642) &&
				(mousePositionwindow.y >= 547 && mousePositionwindow.y <= 811))
			{
				charma.setStyle(Text::Underlined);
				sprite_char.setScale(0.3f, 0.3f);
			}
			else {
				charma.setStyle(Text::Bold);
				sprite_char.setScale(0.2f, 0.2f);
			}
			if ((mousePositionwindow.x >= 774 && mousePositionwindow.x <= 1019) &&
				(mousePositionwindow.y >= 551 && mousePositionwindow.y <= 820))
			{
				bulbo.setStyle(Text::Underlined);
				sprite_bul.setScale(0.3f, 0.3f);
			}
			else {
				bulbo.setStyle(Text::Bold);
				sprite_bul.setScale(0.2f, 0.2f);
			}
			if ((mousePositionwindow.x >= 1190 && mousePositionwindow.x <= 1397) &&
				(mousePositionwindow.y >= 551 && mousePositionwindow.y <= 820))
			{
				pika.setStyle(Text::Underlined);
				sprite_pika.setScale(0.3f, 0.3f);
			}
			else {
				pika.setStyle(Text::Bold);
				sprite_pika.setScale(0.2f, 0.2f);
			}


			window.clear(Color::White);
			window.draw(sprite_char);
			window.draw(sprite_bul);
			window.draw(sprite_pika);
			window.draw(text);
			window.draw(pika);
			window.draw(bulbo);
			window.draw(charma);
			window.display();
		}
	}
	void Player::read() {
		if (pokemon_name == "Pikachu")
		{
			element = "electric";
		}
		else if (pokemon_name == "Bulbasaur")
		{
			element = "grass";
		}
		else if (pokemon_name == "Charmander")
		{
			element = "fire";
		}
	}
	void Player::xp(int time, int xp) {

		int xp_sum = time + xp;

		ifstream file_o("nicknames.txt");
		string line;
		int i = 0;


		namespace x = filesystem;
		x::path file_i("D:\\Projekty\\ProjektGlownyPK4\\ProjektGlownyPK4\\nicknames.txt");
		x::path current = x::current_path();
		if (file_i.empty()) {
			x::create_directories(current);
			ofstream ofs(current);

			while (!file_o.eof())
			{
				getline(file_o, line);
				i++;
				if (i > 8)
				{
					ofstream file("nicknames.txt");
					file << "  Nick :" << nick << "  |   xp : " << xp_sum << endl;
					file.close();
				}
			}
			file_o.close();

		}

		while (!file_o.eof())
		{
			getline(file_o, line);
			i++;
			if (i > 8)
			{
				ofstream file("nicknames.txt");
				file <<"  Nick :" << nick << "  |   xp : " << xp_sum << endl;
				file.close();
			}
		}
		file_o.close();

		if (i <= 8) {
			ofstream file("nicknames.txt", ios_base::app);
			file << " Nick :  " << nick << "   |    xp :   " << xp_sum << endl;
			file.close();
		}

	}

