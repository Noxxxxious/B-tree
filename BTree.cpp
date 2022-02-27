#include <iostream>
#include "BTree.h"
BTree::BTree() {
	this->root = nullptr;
	this->order = 0;
}
BTree::BTree(int order) {
	this->root = nullptr;
	this->order = order;
}
void BTree::add(signed int value) {
	if (root) {
		if (!root->search(value)) {
			if (root->key_num < 2 * order - 1) {
				root->addToNode(value);
			}
			else {
				Node* new_root = new Node(order, false);
				new_root->children[0] = root;
				new_root->split(root, 0);

				if (value > new_root->keysArr[0])
					new_root->children[1]->addToNode(value);
				else
					new_root->children[0]->addToNode(value);
				root = new_root;
			}
		}
	}
	else {
		root = new Node(order, true);
		root->keysArr[0] = value;
		root->key_num = 1;
	}
}
void BTree::printTree() {
	if (root)
		root->printNode();
	else std::cout << std::endl;
}
bool BTree::search(signed int value) {
	if (!root)
		return false;
	return root->search(value);
}
BTree::~BTree() {
	if (root)
		root->delNode();
	delete root;
}