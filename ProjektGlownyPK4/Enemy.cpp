#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include <sstream>
#include <string>
#include "Pokemon.h"
#include "Enemy.h"


void Enemy::read() {
	fstream plik("pokemons.txt");
	if (plik.good()) {
		string line;
		while (getline(plik, line))
		{
			if (line.size() > 0)
			{
				string pokemon_name;
				string element;
				stringstream ss(line);
				if (ss >> pokemon_name >> element)
				{
					name_list.push_back(pokemon_name);
					element_list.push_back(element);
				}
				else
					cout << "We got problem boss" << endl;
			}
		}
	}
	else
	{
		cout << "Problem" << endl;
	}
}
void Enemy::give_statistics(vector<string> winners) {
	if (winners.empty())
	{
		srand(time(NULL));
		clk_enemy = rand() % 15;
		pokemon_name = name_list[clk_enemy]; // jezeli nie ma wygranych to losowy przeciwnik 
	}
	else
	{
		pokemon_name = winners[1]; // jezeli sa juz wygrani to gram z 2 przeciwnikiem 
	}
	
	int i = 0;
	while (name_list[i] != pokemon_name)
		i++;   

	element = element_list[i];  //nadawanie zywiolu 

	hp = give_hp(pokemon_name);  //nadawanie hp za pomoca zywiolu

}
void Enemy::give_enemy_statictics(int which) {
	pokemon_name = name_list[which];

	element = element_list[which];  //nadawanie zywiolu 

	hp = give_hp(pokemon_name);  //nadawanie hp za pomoca zywiolu

}
int Enemy::combat() {
	int random = rand() % 4;
	//Pokemons help;
	if (random == 0)
	{

		//element_attack();
	}
	else if (random == 1)
	{

	}
	else if (random == 2)
	{

	}
	else if (random == 3)
	{

	}
	return 9;
}

