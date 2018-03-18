#pragma once
#include <iostream>
#include"AVLtree.h"
using namespace std;
class Menu
{
public:
	Menu();
	~Menu();
	void ShowOptions();
	bool Proceed(int o,AVLtree *tree);
	int GetOrder() { int o;  cout << "Podaj opcje: "; cin >> o; return o; }
};

