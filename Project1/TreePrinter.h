#pragma once
#include "Branch.h"
#include <stack>
#include <list>
#include <memory>
using namespace std;
class TreePrinter
{
	Branch *root;
	stack<shared_ptr<list<Branch*>>> layers;
	
public:
	void AddToLayer(shared_ptr<list<Branch*>>ptr , Branch *r) {  //ustalanie nowej warstwy od pnia
		
		if (r->left != nullptr)
			ptr->push_back(r->left);
		if (r->right != nullptr)
			ptr->push_back(r->right);
	}
	TreePrinter(Branch *r) {
		root = r;
		layers.push(NULL);
		 Load(); //wczytanie drzewa z pnia

	}
	~TreePrinter() {Print();}
	void Print(); //wypisuje drzewo
	bool Load(); //wczytuje drzewo
	bool LayerfromLayer(shared_ptr<list<Branch*>>prev, shared_ptr<list<Branch*>> nxt);
};

