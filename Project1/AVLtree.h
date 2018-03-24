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
	void Add(const int &x);
	void Print(std::ostream &out);
	void Delete(const int &x) { Cut(Find(x)); while (Balance(root));}
	//***************************************************//
	bool Balance(Branch* r); //przechodzi cale drzewo 
	void Rotate(Branch*, Branch*); //zamienia pien na gloz, galoz na pien
	void Cut(Branch* x);//usuwa komorke i laczy lancuch
	Branch* Find(const int &x);//zwraca adres: -komorki w drzewie o danej wartosci lub -NULL
	int High() { return root->High(); } //zwraca wysokosc drzewa
};

