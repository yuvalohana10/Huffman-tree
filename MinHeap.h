#pragma once
#include "BTree.h"

class MinHeap
{
private:
	BTreeNode** data;
	int maxSize;
	int heapSize;
	int allocated;

	//getters
	static int left(int i) { return i * 2 + 1; }
	static int right(int i) { return i * 2 + 2; }
	static int parent(int i) { return(i - 1) / 2; }

	void fixHeap(int i);

public:

	MinHeap(int max);
	MinHeap(BTreeNode** array, int size);
	~MinHeap();

	BTreeNode* DeleteMin();
	void insert(BTreeNode* node);
	void printInOrder(BTreeNode* root);
};

