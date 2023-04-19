#include <SFML/Graphics.hpp>
#include<iostream>
#include "Menu.h"
#include "Player.h"
#include "Pokemon.h"
#include "Enemy.h"
#include "Moves.h"
#include "Display.h"
#include "Fight.h"

import Module; 

using namespace std;
using namespace sf;


int main()
{
	Clock clock;
	clock.restart();
	shared_ptr<Menu> menu(new Menu);
	menu->show_Menu();
	if (menu->quit() == false)
		return 0;
	shared_ptr<Player> player(new Player);
	player->load_nick();
	player->read();
	shared_ptr<Fight> fight(new Fight(*player));
	shared_ptr<Display> display(new Display);
	float round = fight->get_round();
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			fight->whos_next();
			int first_enemy_number = fight->get_enemy_first_number();
			fight->else_fight(first_enemy_number);
			vector<string> cos = fight->get_winners();
			int round = fight->get_round();
			string first_round_enemy_name = fight->get_enemy_pokemon_name();
			vector<string> enemy_names = fight->get_names();
			display->tours(cos, enemy_names, first_round_enemy_name, round);

			fight->fight_map();
		}
		else
		{
			int first_enemy_number = fight->get_enemy_first_number();
			fight->fight_map();
			fight->else_fight(first_enemy_number);
		}

		if (fight->get_hp() <= 0)
			break;
		else
			fight->heal("heal");

		vector<string> cos = fight->get_winners();
		fight->round();
		if (fight->get_exit() == true)
			break;

		int round = fight->get_round();
		string first_round_enemy_name = fight->get_enemy_pokemon_name();
		vector<string> enemy_names = fight->get_names();
		display->tours(cos, enemy_names, first_round_enemy_name, round);

		if (i == 4)
			display->end_win();
	}
	Time time = clock.getElapsedTime();
	int time_ = time.asSeconds();
	int xp_ = fight->get_xp();
	player->xp(time_, xp_);

		display->end();
}
