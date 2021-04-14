#pragma once
#include <iostream>

using namespace std;

struct Pair {
	char key;
	int frequency;
};


class BTreeNode
{
protected:
	Pair data;
	BTreeNode* left, * right;
public:
	BTreeNode();
	BTreeNode(Pair item, BTreeNode* left, BTreeNode* right);

	//getters
	Pair getValue() const { return data; }
	BTreeNode* getLeft() const { return left; }
	BTreeNode* getRight() const { return right; }
	int getFrequency() const { return data.frequency; }

	//setters
	void setRight(BTreeNode* r) { right = r; }
	void setLeft(BTreeNode* l) { left = l; }
	void setKey(int key) { data.key = key; }

	//void updateFrequencyPlusOne() { data.frequency += 1; }
	void printInOrder();
	bool isLeaf();
	void setFrequency(int f);


};

