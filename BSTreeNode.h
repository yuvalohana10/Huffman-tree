#pragma once
using namespace std;
#include "BTree.h"
#include <iostream>


class BSTreeNode {
private:
	Pair data;
	BSTreeNode* left, * right;

public:
	BSTreeNode();
	BSTreeNode(Pair item, BSTreeNode* left, BSTreeNode* right);
	~BSTreeNode() { delete this->left, delete this->right; }

	//getters
	Pair getData() const { return data; }
	BSTreeNode* getLeft() const { return left; }
	BSTreeNode* getRight() const { return right; }

	//setters
	void setRight(BSTreeNode* r) { right = r; }
	void setLeft(BSTreeNode* l) { left = l; }
	void setFrequency(int f);
	void setKey(int key) { data.key = key; }
	void updateFrequencyPlusOne() { data.frequency += 1; }
	void printInOrder();


};

