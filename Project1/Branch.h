#pragma once
#include <iostream>
using namespace std;
class Branch
{
public:
	////////////////////////////////////////////////////////
	int value;  // przehowywana informacja
	
	Branch *left; //wskaznik na mniejsza wartosc
	Branch *right; //wskaznik na wieksza wartosc
	
	////////////////////////////////////////////////////////

//---------------konstruktory i dekonstruktoru----------//
	Branch() { left = nullptr; right = nullptr;  value = NULL; }
	Branch(const int &x, Branch* r) {left = nullptr; right = nullptr; value = x; }
	virtual ~Branch();
//---------------metody---------------------------------//	
	
	void InOrder();
	void PostOrder();
	void PreOrder();

	Branch* Root(Branch*); //zwraca ojca danej galezi
	void Print(ostream& out) { out << value;} //wypisuje galaz na strumien
	bool Join(Branch* b); //dolacza do galezi
	bool Unplug(Branch &b); //odlacza od galezi
	int High();	//zwraca wysokosc
	
};

