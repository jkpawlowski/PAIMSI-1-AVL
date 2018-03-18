#include "Menu.h"

#include<iostream>

Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::ShowOptions()
{
	cout << " Opcje AVL tree : " << endl
		<< "1. Dopisz element." << endl
		<< "2.Wypisz elementy." << endl
		<< "3.Wyswietl opcje." << endl
		<< "0.Wyjdz." << endl;


}

bool Menu::Proceed(int o,AVLtree *tree)
{
	if (o == 0)return false;
	switch(o) {
	case 1: 
		int x;
		cout << "Podaj liczbe: ";
		cin>>x;
		tree->Add(x);
		break;
	case 2: 
		tree->Print(cout); break;
	case 3: ShowOptions(); break;
	default: cout << "BLAD   zly wybor" << endl; break;
	}
	return true;
}

