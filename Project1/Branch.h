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
	Branch *root;// pochodzenie
	////////////////////////////////////////////////////////

//---------------konstruktory i dekonstruktoru----------//
	Branch() { left = nullptr; right = nullptr; root = nullptr; value = NULL; }
	Branch(const int &x, Branch* r) {left = nullptr; right = nullptr; value = x; root = r;
	if(root!=0)cout << "root" << root << endl;
	if(left!=0)cout << "lewy wsk" << left << endl;

	}
	virtual ~Branch();
//---------------metody---------------------------------//	
	
	
	void Print(ostream& out) { out << value;}
	bool Join(Branch* b);
	bool Unplug(Branch &b);
	int High() {
		if ((this == NULL))return 1;
		
		

		int r=1; 
		int l=1;
		if (right != nullptr) {
			r = right->High() + 1; }
		if (left != nullptr) { 
			l = left->High() + 1; }
		if (r > l)return r; 
		else return l;
	}
	
	//Branch* operator= (Branch* arg) {
	//	return arg;
	//}
	
};

