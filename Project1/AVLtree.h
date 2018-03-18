#pragma once
#include "Branch.h"
#include<iostream>

class AVLtree
{
	Branch *root;
public:
	AVLtree();
	~AVLtree();
	void Add(int &x) { root->Add(x); }
	void Print(std::ostream &out) { root->Print(out); }
};

