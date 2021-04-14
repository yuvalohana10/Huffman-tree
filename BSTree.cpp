#include "BSTree.h"

BSTree::BSTree()
{
	root = nullptr;
	sizeArray = 1;
	array = new BSTreeNode * [sizeArray];
}
BSTree::~BSTree()
{
	delete[] array;
}


BSTreeNode* BSTree::find(const char key) const
{
	BSTreeNode* tmp = root;

	while (tmp != nullptr)
	{
		if (tmp->getData().key == key)
			return tmp;
		else if (tmp->getData().key > key)
			tmp = tmp->getLeft();
		else if (tmp->getData().key < key)
			tmp = tmp->getRight();
	}

	return nullptr;
}


void BSTree::insert(Pair p)
{
	BSTreeNode* tmp = root;
	BSTreeNode* parent = nullptr;
	BSTreeNode* newNode;

	while (tmp != nullptr)
	{
		parent = tmp;
		if (p.key < tmp->getData().key)
			tmp = tmp->getLeft();
		else
			tmp = tmp->getRight();
	}

	newNode = new BSTreeNode(p, nullptr, nullptr);
	if (parent == nullptr)
		root = newNode;
	else if (p.key < parent->getData().key)
		parent->setLeft(newNode);
	else
		parent->setRight(newNode);

	count++;
}


void BSTree::printInOrder()
{
	if (root != nullptr)
		root->printInOrder();
}

void BSTree::Delete(const char key)
{

}

void BSTree::buildTreeFromFile(istream& myFile)
{
	char c;
	myFile.get(c);

	while (!myFile.eof())
	{
		BSTreeNode* loc;
		loc = find(c);
		//is the char is not in the tree
		if (loc == nullptr)
		{
			Pair p;
			p.key = c;
			p.frequency = 1;
			insert(p);
		}
		//if the char is already in the tree
		else
			loc->updateFrequencyPlusOne();
		myFile.get(c);
	}
}


