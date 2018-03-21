#pragma once
#include "Branch.h"
#include <queue>
#include <memory>
using namespace std;
class TreePrinter
{
public:
	
	int **tab; //tablica wartosci do wyjscia
	int high; //roboczo wysokosc drzewa
	ostream *str;

	
	TreePrinter(ostream& out,Branch *r) {
		
		
		str = &out;
		high = r->High();

		tab = new  int*[high];
		for (int lvl = high-1; lvl >=0; lvl--) 
			tab[lvl] = new int[Width(lvl)];
		
		if(r!=nullptr)
		Load(r); //wczytanie drzewa z pnia
	}
	~TreePrinter() { Print();}
	void Print(); //wypisuje drzewo
	void Load(Branch*); //wczytuje drzewo
	
	int	Width(int l) { int t = 1; for (; l != 0; l--)t *= 2; return t; }
};

