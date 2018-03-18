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
		Branch();
	}
	virtual ~Branch();
	void Add(const int &x);
	Branch* FindPlace(const int &x);
	void Print(ostream& out) { 
		out << "->rdzen" << value << "->nogi"; 
		if(left!=nullptr)left->Print(out); 
		if(right!=nullptr)right->Print(out); out << endl; }
	
};

