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
	void Add(const int &x) { root->Add(x); }
	void Print(std::ostream &out) {TreePrinter *p=new TreePrinter(out,root); delete p;}
	//void Delete(const int &x) { root->Cut(root->Find(x)); }
};

