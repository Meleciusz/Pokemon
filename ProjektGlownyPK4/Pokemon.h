#pragma once
#ifndef POKEMON_H
#define POKEMON_H 

using namespace std;

class Pokemon {
protected:
	int hp;
	string pokemon_name;
	string element;
	vector<string> element_list;
	vector<string> name_list;

public:
	int get_hp();
	string get_name();
	string get_element();
	void read();
	int give_hp(string pokemon);
};


#endif // !POKEMON_H
