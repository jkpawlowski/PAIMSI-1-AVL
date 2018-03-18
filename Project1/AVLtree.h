#pragma once
#include "Branch.h"
#include"TreePrinter.h"
#include<iostream>

class AVLtree
{
	Branch *root;
public:
	AVLtree();
	~AVLtree();
	void Add(int &x) { root->Add(x); }
	void Print(std::ostream &out) {
		TreePrinter *p=new TreePrinter(root); delete p;}
};

