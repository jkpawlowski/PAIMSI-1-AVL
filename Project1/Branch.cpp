#include "Branch.h"





Branch::~Branch()
{
	
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
			b->root= this;
			return 1;
		}
	}

	if (b->value> value) {
		if (right != nullptr) 
			return right->Join(b);
		else {
			right = b;
			b->root= this;
			return 1;
		}
	}

	std::cout << "obiekt wystapil wczesniej" << endl;
	return 0;

}

bool Branch::Unplug(Branch  &b)
{
	
	if (left == &b) { left = nullptr; return 1;
	}
	else if (right == &b) { right = nullptr; return 1;
	}
	else if (root == &b) { root = nullptr; return 1;
	}
	else cout << "nie odlaczylo" << endl;
		return 0;

}


