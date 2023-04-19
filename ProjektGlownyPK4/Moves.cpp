#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include <sstream>
#include <string>
#include "Moves.h"

using namespace std;
using namespace sf;

bool Moves::random_sth() {

	srand(time(NULL));
	int if_crit = rand() % 101;
	if (if_crit <= 25)
		return true;
	else
		return false;
}
bool Moves::crit() {
	bool if_crit = random_sth();
	if (if_crit == true)
		return true;
	else
		return false;
}
int Moves::element_attack(string pokemon_type, string pokemon_enemy_type) {
	//atak ¿ywio³u 

	srand(time(NULL));
	damage_to_enemy = 17;

	if (crit() == true)
	{
		int additional_damage = rand() % 7; /////////////////////////do sprawdzenia 
		damage_to_enemy = damage_to_enemy + additional_damage;
	}


	if (pokemon_type == "water")
	{
		if (pokemon_enemy_type == "fire" || pokemon_enemy_type == "grass")
		{
			damage_to_enemy += 2;
		}
		else if (pokemon_enemy_type == "electric")
		{
			damage_to_enemy -= 3;
		}
		else
			damage_to_enemy += 0;
	}
	else if (pokemon_type == "grass")
	{
		if (pokemon_enemy_type == "water" || pokemon_enemy_type == "electric")
		{
			damage_to_enemy += 2;
		}
		else if (pokemon_enemy_type == "fire")
		{
			damage_to_enemy -= 3;
		}
		else
			damage_to_enemy += 0;

	}
	else if (pokemon_type == "electric")
	{
		if (pokemon_enemy_type == "water")
		{
			damage_to_enemy += 5;
		}
		else if (pokemon_enemy_type == "grass")
		{
			damage_to_enemy -= 3;
		}
		else
			damage_to_enemy += 0;

	}
	else if (pokemon_type == "fire")
	{
		if (pokemon_enemy_type == "grass")
		{
			damage_to_enemy += 5;
		}
		else if (pokemon_enemy_type == "water")
		{
			damage_to_enemy -= 3;
		}
		else
			damage_to_enemy += 0;

	}
	else
	{
		damage_to_enemy += rand() % 2;
	}

	return damage_to_enemy;
}
int Moves::strong_attack() {
	//procentowa szansa na trafienie, du¿o obra¿eñ 
	srand(time(NULL));
	damage_to_enemy = 17;
	int additional_damage = 0;
	if (crit() == true)
	{
		int additional_damage = rand() % 7; 
		damage_to_enemy = damage_to_enemy + additional_damage;
	}
	
	if (random_sth() == true)
	{
		damage_to_enemy = 40;
		return damage_to_enemy += additional_damage;
	}
	return damage_to_enemy;
}
int Moves::attack() {

	damage_to_enemy = 17;

	if (crit() == true)
	{
		int additional_damage = rand() % 7; 
		damage_to_enemy = damage_to_enemy + additional_damage;
	}

	return damage_to_enemy;

}
bool Moves::stun_attack() {
	//ma³o dmg, szansa na og³uszenie przeciwnika 

	bool chance = random_sth();
	if (chance == true) {
		return true;
	}
	else
		return false;
}
int Moves::potion() {

	int potion_healing = 30;

	return potion_healing;
}
void Moves::run() {
}


