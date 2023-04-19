#pragma once
#ifndef MOVES_H
#define MOVES_H

using namespace std; 

class Moves {
	int damage_to_enemy;

public:
	bool random_sth();
	bool crit();
	int element_attack(string pokemon_type, string pokemon_enemy_type);
	int strong_attack();
	int attack();
	bool stun_attack();
	int potion();
	void run();


	};
#endif // !MOVES_H

