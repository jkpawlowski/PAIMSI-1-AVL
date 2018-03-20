#pragma once
#include "Branch.h"
#include <queue>
#include <memory>
using namespace std;
class TreePrinter
{
	Branch *root;
	int **tab; //tablica wartosci do wyjscia
	int high = 4; //roboczo wysokosc drzewa
	ostream *str;
public:
	
	TreePrinter(ostream& out,Branch *r) {
		root = r;
		str = &out;

		tab = new  int*[high];
		for (int lvl = high-1; lvl >=0; lvl--) 
			tab[lvl] = new int[Width(lvl)];
		
		
		Load(); //wczytanie drzewa z pnia
	}
	~TreePrinter() {Print();}
	void Print(); //wypisuje drzewo
	void Load(); //wczytuje drzewo
	
	int	Width(int l) { int t = 1; for (; l != 0; l--)t *= 2; return t; }
};

