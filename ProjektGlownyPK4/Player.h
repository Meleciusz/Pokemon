#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Pokemon.h"
using namespace std;

class Player : public Pokemon {

	string nick;

public:
	Player();
	bool regex_nick();
	bool again();
	void load_nick();
	void choose_ur_pokemon();
	void read();
	void xp(int time, int xp);
};
#endif // !PLAYER_H
