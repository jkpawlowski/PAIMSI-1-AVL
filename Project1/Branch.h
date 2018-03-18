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

	Branch();
	Branch(const int &x) {
		value = x;
		left = nullptr;
		right = nullptr;
	}
	virtual ~Branch();
	void Add(const int &x);
	Branch* FindPlace(const int &x);
	void Print(ostream& out) { out << value;}
	
};

