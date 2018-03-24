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
	Branch(const int &x, Branch* r) {left = nullptr; right = nullptr; value = x; 
	

	}
	virtual ~Branch();
//---------------metody---------------------------------//	
	
	void InOrder();
	void PostOrder();
	void PreOrder();

	Branch* Root(Branch*);
	void Print(ostream& out) { out << value;}
	bool Join(Branch* b);
	bool Unplug(Branch &b);
	int High();
	
	
	//Branch* operator= (Branch* arg) {return arg;}
	
};

