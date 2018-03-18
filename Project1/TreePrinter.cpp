#include "TreePrinter.h"


bool TreePrinter::Load() {
	shared_ptr<list<Branch*>> ptr; //dynamiczny wskaznik do warstwy elementow drzewa 
	ptr = make_shared<list<Branch*>>();

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

	//pozostale 

	shared_ptr<list<Branch*>> nxt;
	nxt= make_shared<list<Branch*>>();
	while (1) {
		if (!LayerfromLayer(layers.top(), nxt))
			break;
		layers.push(nxt);
		nxt= make_shared<list<Branch*>>();
	};
	
	
	return 1;
}

bool TreePrinter::LayerfromLayer(shared_ptr<list<Branch*>>prev, shared_ptr<list<Branch*>> nxt) {

	//dodanie wszystkich nowych galezi od lewej do prawej po kolei z elementow warstwy prev do next
	int i=0;
	for (Branch* r : *(prev)) {
		AddToLayer(nxt, r);
		i++;
	}
	return bool(i);

}

void TreePrinter::Print()
{ //wypisanie wszystkich warstw
	
	
	while (shared_ptr<list<Branch*>> ptr = layers.top()) {
		layers.pop();
		int layer = layers.size()-3;
		for (Branch* r : *(ptr)) {
			for (int i=15-(3*layer);i==0;i--) cout << " ";
			
			cout.width(3);
			cout.fill(' ');
			r->Print(cout);
			cout << "   ";
			layer--;
		}
		cout << endl;
	}
	
}
