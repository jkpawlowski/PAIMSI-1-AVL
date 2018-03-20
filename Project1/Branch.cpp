#include "Branch.h"





Branch::~Branch()
{
	
}

void Branch::Add(const int &x)
{
	Branch *place= FindPlace( x);
	if(place!=nullptr)
	place->value = x;
	
}

Branch * Branch::FindPlace(const int &x)
{	
	if (value == NULL)
		return this;
	if (x < value) {
		if (left != nullptr)
			return left->FindPlace(x);
		else {
			left = new Branch(x);
			return left;
		}
	}
	
	if (x > value) {
		if (right != nullptr)
			return right->FindPlace(x);
		else {
			right = new Branch(x);
			return right;
		}
	}
	
	std::cout << "obiekt wystapil wczesniej" << endl;
	 return nullptr;
	}

