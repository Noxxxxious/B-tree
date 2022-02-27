#include <iostream>
#include "Node.h"
Node::Node(int order, bool is_leaf) {
	this->order = order;
	this->is_leaf = is_leaf;
	this->children = new Node * [2 * order]{ nullptr };
	this->key_num = 0;
	this->keysArr = new int[2 * order - 1];
}
void Node::printNode() {
	int index = 0;
	for (index; index < key_num; index++) {
		if (!is_leaf)
			children[index]->printNode();
		std::cout << keysArr[index] << " ";
	}
	if (!is_leaf)
		children[index]->printNode();
	std::cout << std::endl;
}
bool Node::search(signed int value) {
	int index = 0;
	while (value > keysArr[index] && index < key_num)
		index++;
	if (value == keysArr[index])
		return true;
	if (is_leaf)
		return false;
	return children[index]->search(value);
}
void Node::split(Node* child, int index) {
    Node* new_node = new Node(child->order, child->is_leaf);
    new_node->key_num = order - 1;

    for (int i = 0; i < order - 1; i++)
        new_node->keysArr[i] = child->keysArr[i + order];
    if (!child->is_leaf) {
        for (int i = 0; i < order; i++)
            new_node->children[i] = child->children[i + order];
    }

    child->key_num = order - 1;
    for (int i = key_num; i > index + 1; i--)
        children[i + 1] = children[i];
    children[index + 1] = new_node;

	for (int i = key_num - 1; i >= index; i--)
		keysArr[i + 1] = keysArr[i];

    keysArr[index] = child->keysArr[order - 1];
	key_num++;
}
void Node::addToNode(signed int value) {
	if (!is_leaf) {
		int i = key_num - 1;
		while (i >= 0 && value < keysArr[i])
			i--;
		if (children[i + 1]->key_num == 2 * order - 1) {
			split(children[i + 1], i + 1);
			if (value > keysArr[i + 1])
				i++;
		}
		children[i + 1]->addToNode(value);
	}
	else {
		int i;
		for (i = key_num - 1; i >= 0 && value < keysArr[i]; i--)
			keysArr[i + 1] = keysArr[i];
		keysArr[i + 1] = value;
		key_num++;
	}
}
void Node::delNode() {
	int index = 0;
	for (index; index < key_num; index++) {
		if (!is_leaf)
			children[index]->delNode();
		delete children[index];
	}
	if (!is_leaf)
		children[index]->delNode();
}
Node::~Node() {
	delete[] keysArr;
	delete[] children;
}