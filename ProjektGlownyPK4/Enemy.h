#pragma once
#ifndef ENEMY_H
#define ENEMY_H

class Enemy : public Pokemon {
protected:
	int damage;

public:
	int clk_enemy;
	void read();
	void give_statistics(vector<string>);
	void give_enemy_statictics(int);
	int combat();
};


#endif // !ENEMY_H
