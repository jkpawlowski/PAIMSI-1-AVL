#include "TreePrinter.h"


bool TreePrinter::Load() {
	shared_ptr<list<Branch*>> ptr; //dynamiczny wskaznik do warstwy elementow drzewa 
	ptr = make_shared<shared_ptr<list<Branch*>>>();

	{ //dodawanie pierwszego glownego elementu
		if (root->value != NULL) {
			ptr->push_front(root);
			layers.push(ptr);
		}
		else {
			cout << "puste dzrzewo" << endl;
			return 0;
		}
	}

}

shared_ptr<list<Branch*>> TreePrinter::LayerfromLayer(shared_ptr<list<Branch*>>prev, shared_ptr<list<Branch*>> nxt) {

	//dodanie wszystkich nowych galezi od lewej do prawej po kolei z elementow warstwy prev do next
	AddToLayer(ptr, root);
	layers.push(ptr);

	return nxt;
}
TreePrinter::~TreePrinter()
{
	Print();
}

void TreePrinter::Print()
{ //wypisanie wszystkich warstw
	shared_ptr<list<Branch*>> ptr = layers.top();
	layers.pop();
	
}
