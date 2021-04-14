#include "BTree.h"

BTree::BTree()
{
	root = nullptr;
}

BTree::~BTree()
{
	delete root;
	root = nullptr;
}

void BTree::printInOrder() const
{
	if (root != nullptr)
		root->printInOrder();
}


