#include "AVLtree.h"
#include "TreePrinter.h"
#include<iostream>


using namespace std;

AVLtree::AVLtree()
{
	
}


AVLtree::~AVLtree()
{

}

void AVLtree::Cut(Branch * x)
{
	

	if (x != nullptr) {
	/*ok*/	if ((x->left == nullptr) && (x->right == nullptr) && (x == root)) root = nullptr;//jest pniem drzewa i ostatni
		else if ((x->left == nullptr) && (x->right == nullptr) && (x != root)) { //ostatni ale nie pierwszy
			x->root->Unplug(*x);
			
			
		}
		else if ((x->left == nullptr) && (x->right != nullptr) && (x != root)){ //srodkowy r 
			x->root->Unplug(*x);
			
			x->root->Join(x->right);
		}
		else if ((x->left != nullptr) && (x->right == nullptr) && (x != root)) { //srodkowyl
			x->root->Unplug(*x);
			
			x->root->Join(x->left);
		}
		else if ((x->left != nullptr) && (x->right != nullptr) && (x != root)) {//srodkowy l i r
			x->root->Unplug(*x);
			
			x->right->Join(x->left);
			x->root->Join(x->right);
			
		}

		delete x;
	}
		else cerr << "nie maczego usunac" << endl;
}

Branch* AVLtree::Find(const int & x)
{
	Branch* b=root;
	while (1) {
		if (b == nullptr) {
			std::cerr << "nie ma takiego elementu" << endl;
			return nullptr;
		}
		if (b->value == x)
			return b;
		if (x < b->value) {
			b = b->left;
		}
		else
			b = b->right;
		
	}
	
}


