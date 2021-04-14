#pragma once
#include "BSTreeNode.h"

class BSTree
{

private:
	BSTreeNode* root;
	BSTreeNode** array;
	int count = 0;
	int sizeArray;

public:
	BSTree();
	~BSTree();

	//getters
	int getSizeArray() { return sizeArray; }
	BSTreeNode** returnArray() const { return array; }
	BSTreeNode* getRoot() const { return root; }
	int getCount() const { return count; }

	//setters
	void setArray(BSTreeNode** array) { this->array = array; }

	BSTreeNode* find(const char key)const;    
	void buildTreeFromFile(istream& myFile);
	void insert(Pair p);
	void printInOrder();
	void Delete(const char key);

};

