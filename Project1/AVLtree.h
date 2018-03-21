#pragma once
#include "Branch.h"
#include"TreePrinter.h"
#include<iostream>

class AVLtree
{
public:
	/////////////////////////////////////////////////
	Branch *root; //pieñ drzewa --pierwsza komorka--
	/////////////////////////////////////////////////

	AVLtree();
	~AVLtree();
	//****************glowne funkcje*****************//
	void Add(const int &x) { Branch* r = new Branch(x, nullptr); if (root != nullptr)root->Join(r); else root = r; }
	void Print(std::ostream &out) {
		if (root != nullptr) {
			
			TreePrinter *p = new TreePrinter(out, root);
			delete p;
		}
	}

	void Delete(const int &x) { Cut(Find(x)); }
	//***************************************************//

	void Cut(Branch* x);//usuwa komorke i laczy lancuch
	Branch* Find(const int &x);//zwraca adres: -komorki w drzewie o danej wartosci lub -NULL
	int High() { return root->High(); }
};

