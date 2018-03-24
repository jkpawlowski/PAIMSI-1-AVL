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
		<< "2.Wypisz elementy (wys. max 5)." << endl
		<< "3.Usun element." << endl
		<< "4.Wysokosc drzewa?" << endl
		<< "5.Wypisanie In-Order" << endl
		<< "6.Wypisanie Pre-Order" << endl
		<< "7.Wypisanie Post-Order" << endl
		<< "9.Wyswietl opcje." << endl
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
	case 3:
		
		cout << "Podaj liczbe: ";
		cin >> x;
		tree->Delete(x);
		break;
	case 4:
		cout<<"wysokosc drzewa wynosi: "<<tree->High()<<endl; 
		break;
	case 5:
		cout << "Czynnosci In-Order" <<  endl;
		tree->root->InOrder();
		break;
	case 6:
		cout << "Czynnosci Pre-Order" << endl;
		tree->root->PreOrder();
		break;
	case 7:
		cout << "Czynnosci Post-Order" << endl;
		tree->root->PostOrder();
		break;
	case 9: ShowOptions(); break;
	default: cout << "BLAD   zly wybor" << endl; break;
	}
	return true;
}

