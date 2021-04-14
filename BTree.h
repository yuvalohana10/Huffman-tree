#pragma once
#include "BTreeNode.h"

class BTree
{
private:
	BTreeNode* root;

public:

	BTree();
	~BTree();

	//getters
	BTreeNode* getRoot() const { return root; }

	void printInOrder() const;
};

