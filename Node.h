#pragma once
class Node {
private:
	Node** children;
	signed int* keysArr;
	int key_num;
	int order;
	bool is_leaf;
public:
	Node();
	Node(int order, bool is_leaf);

	void printNode();
	bool search(signed int value);
	void split(Node* child, int index);
	void addToNode(signed int value);

	friend class BTree;

	void delNode();
	~Node();
};