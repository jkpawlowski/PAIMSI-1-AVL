#include "Branch.h"


Branch::~Branch()
{

	if(left!=0)delete left;
	if(right!=0)delete right;
	
	
}
void Branch::InOrder() //od lewej przez wezly do prawej
{
	if (left != 0)left->InOrder();

	//czynnosc na r******************//
	cout << value << endl;
	//******************************//

	if (right != 0)right->InOrder();
}

void Branch::PostOrder() // wezlowo od lewej do prawej
{
	if (left != 0)left->PostOrder();
	if (right != 0)right->PostOrder();
	
	//czynnosc na r*****************//
	cout << value << endl;
	//******************************//

}
void Branch::PreOrder()  //lewa prawa
{	
	//czynnosc na r******************//
	cout << value << endl;
	//******************************//
	
	if(left!=0)left->PreOrder();
	if(right!=0)right->PreOrder();
}
Branch * Branch::Root(Branch *r)
{
	if (this == nullptr) return nullptr;
	if (r == left) return this;
	if (r == right) return this;
	if (r->value < value) return left->Root(r);
	if (r->value>value)return right->Root(r);
}
bool Branch::Join(Branch* b) {

	if (this == NULL) {
		cerr << "nie ma do czego dolaczac" << endl;
		return 0;
	}
	if (b->value < value) {
		if (left != nullptr) 
			return left->Join(b);
		else {
			left = b;
			return 1;
		}
	}

	if (b->value> value) {
		if (right != nullptr) 
			return right->Join(b);
		else {
			right = b;
			return 1;
		}
	}

	std::cout << "obiekt wystapil wczesniej" << endl;
	return 0;

}

int Branch::High() {
	if ((this == 0))return 0;

	int r = 1;
	int l = 1;
	if (right != nullptr) {
		r = right->High() + 1;
	}
	if (left != nullptr) {
		l = left->High() + 1;
	}
	if (r > l)return r;
	else return l;
}

bool Branch::Unplug(Branch  &b)
{
	
	if (left == &b) { left = nullptr; return 1;
	}
	else if (right == &b) { right = nullptr; return 1;
	}
	
	else cout << "nie odlaczylo" << endl;
		return 0;

}


