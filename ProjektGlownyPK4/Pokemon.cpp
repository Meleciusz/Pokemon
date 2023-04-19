#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include <sstream>
#include <string>
#include "Pokemon.h"

using namespace std;
using namespace sf;

int Pokemon::get_hp() {
	return hp;
}
string Pokemon::get_name() {
	return pokemon_name;
}
string Pokemon::get_element() {
	return element;
}
void Pokemon::read() {
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
int Pokemon::give_hp(string pokemon) {
		pokemon_name = pokemon;
		int i = 0;
		while (name_list[i] != pokemon) {
			i++;
		}
		if (element_list[i] == "fire")
			return 320;
		else if (element_list[i] == "grass")
			return 350;
		else if (element_list[i] == "electric")
			return 310;
		else if (element_list[i] == "water")
			return 290;
		else 
			return 300;
	}
