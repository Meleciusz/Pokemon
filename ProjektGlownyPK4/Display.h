#pragma once
#ifndef DISPLAY_H
#define DISPLAY_H 

using namespace std; 

class Display {
	vector<string> winners1;
	vector<string> winners2;
	vector<string> winners3;
	string first_enemy;
public:
	void end();

	void end_win();

	void tours(vector<string>, vector<string>, string, int);

};
#endif // !DISPLAY_H

