#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include <sstream>
#include <mutex>
#include <thread>
#include <string>
#include <condition_variable>
#include "Fight.h"
#include "Player.h"
#include "Enemy.h"
#include "Moves.h"


using namespace std;
using namespace sf;

int Fight::get_enemy_first_number() {
	return enemy_first_number;
}
int Fight::get_xp() {
	return xp;
}
void Fight::round() {
	actual_round++;
}
int Fight::get_round()
{
	return actual_round;
}
int Fight::get_hp()
{
	return hp;
}
vector<string> Fight::get_names() {
	return enemy_names;
}
string Fight::get_enemy_pokemon_name() {
	return enemy_pokemon_name;
}
bool Fight::get_exit()
{
	return exit;
}
vector<string> Fight::get_winners()
{
	return winners;
}
Fight::Fight(Player _show_) {
	w8 = true;
	xp = 0;
	hp = _show_.get_hp();
	basic_player_hp = hp;
	player_pokemon_name = _show_.get_name();
	player_pokemon_element = _show_.get_element();
	actual_round = 0;
	potion = 1;
}
void Fight::Enemy_Combat() {

	srand(time(NULL));
	int hlp = rand() % 3;  
	if (hlp == 0) {
		hp = hp - moves.element_attack(enemy_pokemon_element, player_pokemon_element);
	}
	else if (hlp == 1) {
		hp = hp - moves.strong_attack();
	}
	else if (hlp == 2) {
		hp = hp - moves.attack();
	}
}
void Fight::fight_map() {
	exit = false;
	RenderWindow window(VideoMode(1500, 1000, 32), "Pokemon, New Edition!");//, Style::Fullscreen);
	Event event;
	Time t = seconds(0.9f);
	sf::Clock clock;
	if(actual_round != 0)
		whos_next();

	Font MyFont;
	MyFont.loadFromFile("pokemons.ttf");

	Text Player_pokemon_name;
	Player_pokemon_name.setFont(MyFont);
	Player_pokemon_name.setCharacterSize(50);
	Player_pokemon_name.setFillColor(Color::Black);
	Player_pokemon_name.setString(player_pokemon_name);
	Player_pokemon_name.setPosition(Vector2f(875.f, 484.f));

	Text Enemy_pokemon_name;
	Enemy_pokemon_name.setFont(MyFont);
	Enemy_pokemon_name.setCharacterSize(50);
	Enemy_pokemon_name.setFillColor(Color::Black);
	Enemy_pokemon_name.setString(enemy_pokemon_name);
	Enemy_pokemon_name.setPosition(Vector2f(116.f, 128.f));

	Text Stun_attack;
	Stun_attack.setFont(MyFont);
	Stun_attack.setCharacterSize(35);
	Stun_attack.setFillColor(Color::White);
	Stun_attack.setString("Stun attack");
	Stun_attack.setPosition(Vector2f(500.f, 870.f));

	Text what;
	what.setFont(MyFont);
	what.setCharacterSize(100);
	what.setString("?");
	what.setPosition(Vector2f(1230.f, 727.f));

	Text what_next;
	what_next.setFont(MyFont);
	what_next.setCharacterSize(60);
	what_next.setFillColor(Color::Black);
	what_next.setString("What next?");
	what_next.setPosition(Vector2f(75.f, 792.f));

	Text Elemental_attack;
	Elemental_attack.setFont(MyFont);
	Elemental_attack.setCharacterSize(33);
	Elemental_attack.setFillColor(Color::White);
	Elemental_attack.setString("Elemental attack");
	Elemental_attack.setPosition(Vector2f(813.f, 870.f));

	Text Run;
	Run.setFont(MyFont);
	Run.setCharacterSize(50);
	Run.setFillColor(Color::White);
	Run.setString("Run");
	Run.setPosition(Vector2f(1217.f, 870.f));

	Text Attack;
	Attack.setFont(MyFont);
	Attack.setCharacterSize(35);
	Attack.setFillColor(Color::White);
	Attack.setString("Attack");
	Attack.setPosition(Vector2f(560.f, 755.f));

	Text Strong_attack;
	Strong_attack.setFont(MyFont);
	Strong_attack.setCharacterSize(35);
	Strong_attack.setFillColor(Color::White);
	Strong_attack.setString("Strong attack");
	Strong_attack.setPosition(Vector2f(830.f, 755.f));


	Texture map;
	map.loadFromFile("Battle_Map_.png");

	Texture pokemon_back_;
	if (player_pokemon_name == "Pikachu") {
		pokemon_back_.loadFromFile("pikachu_back.png");
	}
	else if (player_pokemon_name == "Charmander")
	{
		pokemon_back_.loadFromFile("charmander_back.png");
	}
	else
		pokemon_back_.loadFromFile("bulbasaur_back.png");

	Texture enemy_fighter;
	if (enemy_pokemon_name == "Pikachu") {
		enemy_fighter.loadFromFile("pikachu.png");
	}
	else if(enemy_pokemon_name == "Bulbasaur") {
		enemy_fighter.loadFromFile("bulbasaur.png");
	}
	else if(enemy_pokemon_name == "Charmander") {
		enemy_fighter.loadFromFile("charmanderr.png");
	}
	else if(enemy_pokemon_name == "Squirtle") {
		enemy_fighter.loadFromFile("squirtle.png");
	}
	else if(enemy_pokemon_name == "Ratata") {
		enemy_fighter.loadFromFile("ratata_fight.png");
	}
	else if(enemy_pokemon_name == "Kakuna") {
		enemy_fighter.loadFromFile("kakuna.png");
	}
	else if(enemy_pokemon_name == "Vulpix") {
		enemy_fighter.loadFromFile("vulpix.png");
	}
	else if(enemy_pokemon_name == "Zubat") {
		enemy_fighter.loadFromFile("zubat.png");
	}
	else if(enemy_pokemon_name == "Onix") {
		enemy_fighter.loadFromFile("onix.png");
	}
	else if(enemy_pokemon_name == "Growlithe") {
		enemy_fighter.loadFromFile("growlithe.png");
	}
	else if(enemy_pokemon_name == "Tentacool") {
		enemy_fighter.loadFromFile("tentacool.png");
	}
	else if(enemy_pokemon_name == "Golem") {
		enemy_fighter.loadFromFile("golem.png");
	}
	else if(enemy_pokemon_name == "Ponyta") {
		enemy_fighter.loadFromFile("ponyta.png");
	}
	else if(enemy_pokemon_name == "Magnemite") {
		enemy_fighter.loadFromFile("magnemite.png");
	}
	else if(enemy_pokemon_name == "Seel") {
		enemy_fighter.loadFromFile("seel.png");
	}

	RectangleShape hp1;
	hp1.setSize(Vector2f(hp, 5.f));
	hp1.setPosition(Vector2f(973.f, 565.f));
	Color color(Color::Green);
	hp1.setFillColor(color);
	RectangleShape hp1_;
	hp1_.setSize(Vector2f(hp - basic_player_hp, 5.f));
	hp1_.setPosition(Vector2f(973.f + basic_player_hp, 565.f));
	hp1_.setFillColor(Color::Red);
	RectangleShape hp2;
	hp2.setSize(Vector2f(enemy_hp, 5.f));
	hp2.setPosition(Vector2f(207.f, 210.f));
	hp2.setFillColor(color);
	RectangleShape hp2_;
	hp2_.setSize(Vector2f(enemy_hp - basic_enemy_hp, 5.f));
	hp2_.setPosition(Vector2f(207.f + basic_enemy_hp, 210.f));
	hp2_.setFillColor(Color::Red);

	map.setSmooth(true);
	sf::Sprite sprite_map;
	sprite_map.setTexture(map);
	sprite_map.setScale((float)window.getSize().x / (float)map.getSize().x, (float)window.getSize().y / (float)map.getSize().y);

	sf::Sprite sprite_pokemon_back_;
	sprite_pokemon_back_.setTexture(pokemon_back_);
	sprite_pokemon_back_.setPosition(Vector2f(270.f, 410.f));

	sf::Sprite sprite_ratata_fight;
	sprite_ratata_fight.setTexture(enemy_fighter);
	sprite_ratata_fight.setPosition(Vector2f(800.f, 150.f));

	SoundBuffer buffer; 
	buffer.loadFromFile("attack1.wav");
	Sound sound;
	sound.setBuffer(buffer);
	sound.setVolume(50.f);

	Texture player_element_texture;
	Texture enemy_element_texture;
	if(player_pokemon_element == "fire")
		player_element_texture.loadFromFile("fire.png");
	else if(player_pokemon_element == "water")
		player_element_texture.loadFromFile("water.png");
	else if(player_pokemon_element == "electric")
		player_element_texture.loadFromFile("bolt.png");
	else if(player_pokemon_element == "grass")
		player_element_texture.loadFromFile("grass.png");
	else
		enemy_element_texture.loadFromFile("inne.png");

	if (enemy_pokemon_element == "fire")
		enemy_element_texture.loadFromFile("fire.png");
	else if (enemy_pokemon_element == "water")
		enemy_element_texture.loadFromFile("water.png");
	else if (enemy_pokemon_element == "electric")
		enemy_element_texture.loadFromFile("bolt.png");
	else if (enemy_pokemon_element == "grass")
		enemy_element_texture.loadFromFile("grass.png");
	else
		enemy_element_texture.loadFromFile("inne.png");

	Sprite player_element_sprite;
	Sprite enemy_element_sprite;

	player_element_sprite.setTexture(player_element_texture);
	player_element_sprite.setPosition(Vector2f(1299.f, 470.f));
	enemy_element_sprite.setTexture(enemy_element_texture);
	enemy_element_sprite.setPosition(Vector2f(524.f, 110.f));

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed) {
				if (w8 == true) {
					if (event.mouseButton.button == Mouse::Left)
					{
						cout << "X:" << event.mouseButton.x << endl;
						cout << "Y:" << event.mouseButton.y << endl;
						if ((event.mouseButton.x >= 805 && event.mouseButton.x <= 1094) &&
							(event.mouseButton.y >= 853 && event.mouseButton.y <= 945))
						{
							enemy_hp = enemy_hp - moves.element_attack(player_pokemon_element, enemy_pokemon_element);
							xp += 50;
							Enemy_Combat();
							clock.restart();
							w8 = false;
						}
						else if ((event.mouseButton.x >= 463 && event.mouseButton.x <= 771) &&
							(event.mouseButton.y >= 855 && event.mouseButton.y <= 941))
						{
							if (moves.stun_attack() == true) {
								xp += 20;
								enemy_hp = enemy_hp - moves.attack();
								Enemy_Combat();
							}
							else
							{
								xp += 100;
								enemy_hp = enemy_hp - moves.attack();
							}
							clock.restart();
							w8 = false;
						}
						else if ((event.mouseButton.x >= 803 && event.mouseButton.x <= 1097) &&
							(event.mouseButton.y >= 735 && event.mouseButton.y <= 824))
						{
							enemy_hp = enemy_hp - moves.strong_attack();
							xp += 70;
							Enemy_Combat();
							clock.restart();
							w8 = false;
						}
						else if ((event.mouseButton.x >= 1387 && event.mouseButton.x <= 1500) &&
							(event.mouseButton.y >= 5 && event.mouseButton.y <= 147))
						{
							if (potion > 0) {
								if (hp + moves.potion() <= basic_player_hp)
									hp = hp + moves.potion();
								else
									hp = basic_enemy_hp;

								xp -= 20;
								potion--;
								Enemy_Combat();
								clock.restart();
								w8 = false;
							}
						}
						else if ((event.mouseButton.x >= 466 && event.mouseButton.x <= 773) &&
							(event.mouseButton.y >= 732 && event.mouseButton.y <= 829))
						{
							enemy_hp = enemy_hp - moves.attack();
							xp += 30;
							//sound.play();
							clock.restart();
							Enemy_Combat();
							w8 = false;
						}
						else if ((event.mouseButton.x >= 1221 && event.mouseButton.x <= 1300) &&
							(event.mouseButton.y >= 733 && event.mouseButton.y <= 830))
						{
							//pokazanie informacji
							show_info();
						}
						else if ((event.mouseButton.x >= 1126 && event.mouseButton.x <= 1444) &&
							(event.mouseButton.y >= 854 && event.mouseButton.y <= 952))
						{
							xp = 0;
							moves.run();
							exit = true;
							window.close();
						}
					}
				}
			}
		}

		Vector2i mousePositionwindow = Mouse::getPosition(window);

		if ((mousePositionwindow.x >= 1221 && mousePositionwindow.x < 1300) &&
			(mousePositionwindow.y > 733 && mousePositionwindow.y < 830))
		{
			what.setFillColor(Color::Red);
		}
		else
			what.setFillColor(Color::White);
		if ((mousePositionwindow.x >= 805 && mousePositionwindow.x <= 1094) &&
			(mousePositionwindow.y >= 853 && mousePositionwindow.y <= 945))
		{
			Elemental_attack.setFillColor(Color::Red);
		}
		else
			Elemental_attack.setFillColor(Color::White);
		if ((mousePositionwindow.x >= 463 && mousePositionwindow.x <= 771) &&
			(mousePositionwindow.y >= 855 && mousePositionwindow.y <= 941))
		{
			Stun_attack.setFillColor(Color::Red);
		}
		else
			Stun_attack.setFillColor(Color::White);
		if ((mousePositionwindow.x >= 803 && mousePositionwindow.x <= 1097) &&
			(mousePositionwindow.y >= 735 && mousePositionwindow.y <= 824))
		{
			Strong_attack.setFillColor(Color::Red);
		}
		else
			Strong_attack.setFillColor(Color::White);
		if ((mousePositionwindow.x >= 466 && mousePositionwindow.x <= 773) &&
			(mousePositionwindow.y >= 732 && mousePositionwindow.y <= 829))
		{
			Attack.setFillColor(Color::Red);
		}
		else
			Attack.setFillColor(Color::White);
		if ((mousePositionwindow.x >= 1126 && mousePositionwindow.x <= 1444) &&
			(mousePositionwindow.y >= 854 && mousePositionwindow.y <= 952))
		{
			Run.setFillColor(Color::Red);
		}
		else
			Run.setFillColor(Color::White);

		window.clear(Color::Black);
		window.draw(sprite_map);
		window.draw(sprite_pokemon_back_);
		window.draw(sprite_ratata_fight);

		window.draw(hp1);
		if (clock.getElapsedTime() >= t)
		{
			hp1.setSize(Vector2f(hp, 15.f));
			hp1_.setSize(Vector2f(hp - basic_player_hp, 15.f));
			w8 = true;
		}
		window.draw(hp1_);
		if (enemy_hp < 0 || hp < 0)
		{
			//winners.clear();
			//winners.push_back(player_pokemon_name);
			window.close();
		}
		hp2.setSize(Vector2f(enemy_hp, 15.f));
		window.draw(hp2);
		hp2_.setSize(Vector2f(enemy_hp - basic_enemy_hp, 15.f));
		window.draw(hp2_);
		window.draw(Player_pokemon_name);
		window.draw(Enemy_pokemon_name);
		window.draw(Strong_attack);
		window.draw(Stun_attack);
		window.draw(what_next);
		window.draw(what);
		window.draw(Attack);
		window.draw(player_element_sprite);
		window.draw(enemy_element_sprite);
		window.draw(Run);
		window.draw(Elemental_attack);
		window.display();
	}

}
void Fight::show_info() {
	RenderWindow window(VideoMode(1800, 980, 32), "Pokemon, New Edition!");//, Style::Fullscreen);
	Event event;

	Font MyFont;
	MyFont.loadFromFile("pokemons.ttf");

	Text Back;
	Back.setFont(MyFont);
	Back.setString("Back");
	Back.setCharacterSize(50);
	Back.setFillColor(Color::White);
	Back.setPosition(Vector2f(120.f, 875.f));

	Text info_p;
	info_p.setFont(MyFont);
	info_p.setString("Information about player");
	info_p.setCharacterSize(50);
	info_p.setFillColor(Color::Yellow);
	info_p.setPosition(Vector2f(0.f, 300.f));

	Text info_e;
	info_e.setFont(MyFont);
	info_e.setString("Information about enemy");
	info_e.setCharacterSize(50);
	info_e.setFillColor(Color::Yellow);
	info_e.setPosition(Vector2f(0.f, 0.f));

	Text enemy__name;
	enemy__name.setFont(MyFont);
	enemy__name.setString(enemy_pokemon_name);
	enemy__name.setCharacterSize(50);
	enemy__name.setFillColor(Color::White);
	enemy__name.setPosition(Vector2f(900.f, 100.f));

	Text enemy_name;
	enemy_name.setFont(MyFont);
	enemy_name.setString("Enemy pokemon name :");
	enemy_name.setCharacterSize(50);
	enemy_name.setFillColor(Color::White);
	enemy_name.setPosition(Vector2f(0.f, 100.f));

	Text enemy__element;
	enemy__element.setFont(MyFont);
	enemy__element.setString("Enemy pokemon element :");
	enemy__element.setCharacterSize(50);
	enemy__element.setFillColor(Color::White);
	enemy__element.setPosition(Vector2f(0.f, 200.f));

	Text enemy_element;
	enemy_element.setFont(MyFont);
	enemy_element.setString(enemy_pokemon_element);
	enemy_element.setCharacterSize(50);
	enemy_element.setFillColor(Color::White);
	enemy_element.setPosition(Vector2f(900.f, 200.f));

	Text elemental_additional;
	elemental_additional.setFont(MyFont);
	elemental_additional.setString("Additional damage to : ");
	elemental_additional.setCharacterSize(50);
	elemental_additional.setFillColor(Color::White);
	elemental_additional.setPosition(Vector2f(0.f, 400.f));

	Text elemental__additional;
	elemental__additional.setFont(MyFont);
	elemental__additional.setCharacterSize(50);
	elemental__additional.setFillColor(Color::White);
	elemental__additional.setPosition(Vector2f(900.f, 400.f));

	Text crit_info;
	crit_info.setFont(MyFont);
	crit_info.setString("Crit chance : ");
	crit_info.setCharacterSize(50);
	crit_info.setFillColor(Color::White);
	crit_info.setPosition(Vector2f(0.f, 500.f));

	Text crit;
	crit.setFont(MyFont);
	crit.setString("25%");
	crit.setCharacterSize(50);
	crit.setFillColor(Color::White);
	crit.setPosition(Vector2f(900.f, 500.f));

	Text string_info;
	string_info.setFont(MyFont);
	string_info.setString("Strong attack chance : ");
	string_info.setCharacterSize(50);
	string_info.setFillColor(Color::White);
	string_info.setPosition(Vector2f(0.f, 600.f));

	Text strong;
	strong.setFont(MyFont);
	strong.setString("25%");
	strong.setCharacterSize(50);
	strong.setFillColor(Color::White);
	strong.setPosition(Vector2f(900.f, 600.f));

	Text stun_info;
	stun_info.setFont(MyFont);
	stun_info.setString("Stun chance : ");
	stun_info.setCharacterSize(50);
	stun_info.setFillColor(Color::White);
	stun_info.setPosition(Vector2f(0.f, 700.f));

	Text stun;
	stun.setFont(MyFont);
	stun.setString("25%");
	stun.setCharacterSize(50);
	stun.setFillColor(Color::White);
	stun.setPosition(Vector2f(900.f, 700.f));

	Text potion_info;
	potion_info.setFont(MyFont);
	potion_info.setString("Potions : ");
	potion_info.setCharacterSize(50);
	potion_info.setFillColor(Color::White);
	potion_info.setPosition(Vector2f(0.f, 800.f));

	string potions = to_string(potion);
	Text potion;
	potion.setFont(MyFont);
	potion.setString(potions);
	potion.setCharacterSize(50);
	potion.setFillColor(Color::White);
	potion.setPosition(Vector2f(900.f, 800.f));

	if (player_pokemon_element == "water")
	{
		elemental__additional.setString("Grass & Fire");
	}
	else if (player_pokemon_element == "grass")
	{
		elemental__additional.setString("Water & Electric");
	}
	else if (player_pokemon_element == "electric")
	{
		elemental__additional.setString("Water");
	}
	else if (player_pokemon_element == "fire")
	{
		elemental__additional.setString("Grass");
	}
	else
	{
		elemental__additional.setString(" -- ");
	}


	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed) {
				if ((event.mouseButton.x >= 114 && event.mouseButton.x <= 234) &&
					(event.mouseButton.y >= 876 && event.mouseButton.y <= 935))
				{
					window.close();
				}
				if (event.mouseButton.button == Mouse::Left)
				{
					cout << "X:" << event.mouseButton.x << endl;
					cout << "Y:" << event.mouseButton.y << endl;
				}
			}
		}

		Vector2i mousePositionwindow = Mouse::getPosition(window);
		if ((mousePositionwindow.x >= 114 && mousePositionwindow.x < 234) &&
			(mousePositionwindow.y > 876 && mousePositionwindow.y < 935))
		{
			Back.setFillColor(Color::Red);
		}
		else
			Back.setFillColor(Color::White);

		window.clear(Color::Black);
		window.draw(Back);
		window.draw(enemy__name);
		window.draw(enemy__element);
		window.draw(crit_info);
		window.draw(crit);
		window.draw(strong);
		window.draw(info_p);
		window.draw(info_e);
		window.draw(string_info);
		window.draw(stun_info);
		window.draw(stun);
		window.draw(enemy_element);
		window.draw(enemy_name);
		window.draw(potion_info);
		window.draw(potion);
		window.draw(elemental_additional);
		window.draw(elemental__additional);
		window.display();

	}

}
void Fight::heal(string what) {
	if (what == "heal") {
		hp = basic_player_hp;
	}
	potion++;
}
void Fight::whos_next() {
	Enemy enemy;
	enemy.read();
	enemy.give_statistics(winners);
	enemy_hp = enemy.get_hp();
	basic_enemy_hp = enemy_hp;
	enemy_pokemon_name = enemy.get_name();
	enemy_pokemon_element = enemy.get_element();
	enemy_first_number = enemy.clk_enemy;
}
void Fight::numbers_los(int first_enemy_number) {
	srand(time(NULL));
	int help = rand() % 15;
	while (first_enemy_number != help)
	{
		int help = rand() % 15;
		numbers.push_back(help);
	}
	while (true) {
		bool b = true;
		help = rand() % 15;
		if (numbers.size() == 14)
			break;

		for (int i = 0; i < numbers.size(); i++) {
			if (help == numbers[i] || help == first_enemy_number) {
				b = false;
				break;
			}
		}
		if (b == true)
			numbers.push_back(help);
	}
}
void Fight::else_fight(int first_enemy_number) {
	Enemy enemy_pokemon;
	if (actual_round == 0)
	{
		//narazie bedzie losowane kto wygra, jak bedzie czas to potem zmien 
		//tutaj bedzie uzywany thread 
		winners.push_back(player_pokemon_name);
		numbers_los(first_enemy_number);

		enemy_battle(numbers[0], numbers[1]);
		enemy_battle(numbers[2], numbers[3]);
		enemy_battle(numbers[4], numbers[5]);
		enemy_battle(numbers[6], numbers[7]);
		enemy_battle(numbers[8], numbers[9]);
		enemy_battle(numbers[10], numbers[11]);
		enemy_battle(numbers[12], numbers[13]);

	}
	else if (actual_round == 1)
	{
		vector<string> hlp;
		int i = 0;
		for (auto x : winners)
		{
			hlp.push_back(winners[i]);
			i++;
		}

		winners.clear();
		winners.push_back(player_pokemon_name);
		enemy_batlle_winners(hlp[2], hlp[3]);
		enemy_batlle_winners(hlp[4], hlp[5]);
		enemy_batlle_winners(hlp[6], hlp[7]);
		hlp.clear();

	}
	else if (actual_round == 2)
	{
		vector<string> hlp;
		int i = 0;
		for (auto x : winners)
		{
			hlp.push_back(winners[i]);
			i++;
		}
		winners.clear();
		winners.push_back(player_pokemon_name);
		enemy_batlle_winners(hlp[2], hlp[3]);

	}
	else if (actual_round == 3) {
		winners.clear();
		winners.push_back(player_pokemon_name);
	}
}
void Fight::enemy_batlle_winners(string x, string y) {
	srand(time(NULL));
	int help = rand() % 2;
	if (help == 1)
	{
		winners.push_back(x);
	}
	else
	{
		winners.push_back(y);
	}

}
void Fight::enemy_battle(int x, int y) {
	Enemy enemy_;
	enemy_.read();

	srand(time(NULL));
	int help = rand() % 2;
		enemy_.give_enemy_statictics(x);
		enemy_names.push_back(enemy_.get_name());
		enemy_.give_enemy_statictics(y);
		enemy_names.push_back(enemy_.get_name());
	if (help == 1)
	{
		winners.push_back(enemy_.get_name());
	}
	else
	{
		winners.push_back(enemy_.get_name());
	}
}

