#pragma once
#include <iostream>
using namespace std;
class Branch
{
public:
	int value;
	int weight;
	Branch *left;
	Branch *right;

	Branch(){left = nullptr;right = nullptr;}
	Branch(const int &x) { value = x; Branch(); }
	virtual ~Branch();
	
	void Add(const int &x);
	Branch* FindPlace(const int &x);
	void Print(ostream& out) { out << value;}

	Branch* operator= (Branch* arg) {
		return arg;
	}
	
};

