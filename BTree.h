#pragma once
#include "Node.h"
class BTree {
private:
	Node* root;
	int order;
public:
	BTree();
	BTree(int order);

	void add(signed int value);
	void printTree();
	bool search( signed int value);

	~BTree();
};