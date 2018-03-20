#include "TreePrinter.h"

	
void TreePrinter::Load() {
	
	queue<Branch*> que; //kolejka robocza
	Branch* br=new Branch(root->value) ;//roboczy
	br = root;
	que.push(br);
	

	//que.push(br);

	for (int l = 0 ; l < high; l++) {  //petla warstw
		
		for (int e = 0; e < Width(l); e++) {
			
			br = que.front();
			que.pop();

			if (br != nullptr) {
				tab[l][e] = br->value;
				que.push(br->left);
				que.push(br->right);
			}
			else {
				tab[l][e] = NULL;
				que.push(nullptr);
				que.push(nullptr);
			}

			
		}
	}
	
}

void TreePrinter::Print() {

	
	int w[] = { 21,9,3,0 };//wciecia
	int s[] = { 0,21,9,3 };//odstepy

	for (int l = 0; l < high; l++) {  //petla warstw
		for (int i = 0; i < w[l]; i++) cout << " ";//wciecie
		for (int e = 0; e < Width(l); e++) {
			if (tab[l][e] != NULL) {
				str->width(3);
				str->fill('_');
				*str << tab[l][e];
			}
			else *str << "_|_";
			for (int i = 0; i < s[l]; i++) *str << " ";
		}
		*str <<endl;
	}
}