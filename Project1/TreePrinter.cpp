#include "TreePrinter.h"

	
void TreePrinter::Load(Branch *br) {
	
	queue<Branch*> que; //kolejka robocza
	
	que.push(br);
	
	
	if(br!=nullptr)
	for (int l = 0 ; l < high; l++) {  //petla warstw
		
		for (int e = 0; e < Width(l); e++) {
			
			br = que.front();
			que.pop();

			if (br!=0) {
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
	else cerr << "pusto" << endl;
	
	while (que.empty())que.pop();
}

void TreePrinter::Print() {

	
	int w[] = { 30,14,6,2,0 };//wciecia
	int s[] = { 25,29,13,5,1};//odstepy

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