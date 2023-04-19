#pragma once
#ifndef MENU_H
#define MENU_H

using namespace std;

class Menu {
	int screen;
	bool ex;
public:
	Menu();
	bool quit();
	void show_Menu();
};
#endif // !MENU_H
