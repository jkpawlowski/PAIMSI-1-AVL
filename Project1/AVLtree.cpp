#include "AVLtree.h"
#include "TreePrinter.h"
#include<iostream>


using namespace std;

AVLtree::AVLtree()
{
	
}


AVLtree::~AVLtree()
{
	if(root!=0)delete root;
	
}
void AVLtree::Print(std::ostream &out) {
	if (root != nullptr) {

		TreePrinter *p = new TreePrinter(out, root);
		delete p;
	}
}
void AVLtree::Add(const int &x) { 
	Branch* r = new Branch(x, nullptr);
	if (root != nullptr)root->Join(r); 
	else root = r; 
	while (Balance(root)); 
}
bool AVLtree::Balance(Branch* r)
{
	bool x = 0;
	
	
	//czynnosc na r*****************//
	
	if (abs(r->left->High() - r->right->High()) >= 2) {
		x += 1;
		if (r->left->High() - r->right->High() >= 2) Rotate(r, r->left);//lewy wiekszy
		else Rotate(r, r->right);	//prawy wiekszy
	}

	if (r->left != 0)x += Balance(r->left);
	if (r->right != 0)x += Balance(r->right);

	//******************************//

	return x;
}

void AVLtree::Rotate(Branch *r0, Branch *r) // r0 przechodzi pod r, r staje sie pniem dla r0
{
	if(r0==root){
		
		root->Unplug(*r);
		root = r;
		root->Join(r0);

	}
	
	else {
		Branch* r00 = root->Root(r0);//pien dla r0
		r00->Unplug(*r0);
		r00->Join(r);

		r0->Unplug(*r);

		r->Join(r0);
	}
}

void AVLtree::Cut(Branch * x)
{
	

	if (x != nullptr) {
	/*ok*/	if ((x->left == nullptr) && (x->right == nullptr) && (x == root)) root = nullptr;//jest pniem drzewa i ostatni
		else if ((x->left == nullptr) && (x->right == nullptr) && (x != root)) { //ostatni ale nie pierwszy
			root->Root(x)->Unplug(*x);
			
			
		}
		else if ((x->left == nullptr) && (x->right != nullptr) && (x != root)){ //srodkowy r 
			Branch* tmp= root->Root(x);
			tmp->Unplug(*x);
			tmp->Join(x->right);
		}
		else if ((x->left != nullptr) && (x->right == nullptr) && (x != root)) { //srodkowyl
			Branch* tmp = root->Root(x);
			tmp->Unplug(*x);
			tmp->Join(x->left);
		}
		else if ((x->left != nullptr) && (x->right != nullptr) && (x != root)) {//srodkowy l i r
			Branch* tmp = root->Root(x);
			tmp->Unplug(*x);
			x->right->Join(x->left);
			tmp->Join(x->right);
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


