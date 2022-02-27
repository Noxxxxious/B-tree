#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <stdlib.h>
#include <crtdbg.h>
#include "BTree.h"
#include "Node.h"
using namespace std;

int main() {
	char command;
	BTree* b_tree = new BTree();
	while (cin >> command) {
		if (command == 'I') {
			unsigned int order;
			cin >> order;
			b_tree = new BTree(order);
		}
		else if (command == 'A') {
			signed int value;
			cin >> value;
			b_tree->add(value);
		}
		else if (command == '?') {
			signed int value;
			cin >> value;
			if (b_tree->search(value))
				cout << value << " +" << endl;
			else
				cout << value << " -" << endl;
		}
		else if (command == 'P') {
			b_tree->printTree();
		}
		else if (command == 'X') {
			b_tree->~BTree();
			_CrtDumpMemoryLeaks();
			return 0;
		}
	 }
}