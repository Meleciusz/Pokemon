#pragma once
#ifndef FIGHT_H
#define FIGHT_H


#include "Moves.h"
#include "Player.h"
using namespace std; 

class Fight {
	vector<string> winners;
	vector<string> enemy_names;
	vector<int> numbers;
	int actual_round;
	int enemy_first_number;
	int potion;
	int xp;
	int hp;
	bool w8;
	bool exit;
	int enemy_hp;
	int basic_player_hp;
	int basic_enemy_hp;
	string player_pokemon_name;
	string enemy_pokemon_name;
	string player_pokemon_element;
	string enemy_pokemon_element;
	Moves moves;
public:
	int get_enemy_first_number();
	int get_xp();
	void round();
	int get_round();
	int get_hp();
	vector<string> get_names();
	string get_enemy_pokemon_name();
	bool get_exit();
	vector<string> get_winners();
	Fight(Player _show_);
	void Load();
	void Enemy_Combat();
	void fight_map();
	void show_info();
	void heal(string what);
	void whos_next();
	void numbers_los(int first_enemy_number);
	void else_fight(int first_enemy_number);
	void enemy_batlle_winners(string x, string y);
	void enemy_battle(int x, int y);
};


#endif // !FIGHT_H

