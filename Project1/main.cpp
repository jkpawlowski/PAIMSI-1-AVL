#include <iostream>
#include "AVLtree.h"
#include "Menu.h"
int main() {
	using namespace std;
	Menu m;
	AVLtree *tree;
	tree = new AVLtree();
	m.ShowOptions();
	
	while (		m.Proceed( m.GetOrder(), tree)		);
	
    
	
	return 0;
}
