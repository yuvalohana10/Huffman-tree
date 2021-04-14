#include "MinHeap.h"


MinHeap::MinHeap(int max)
{
	data = new BTreeNode * [max];
	maxSize = max;
	heapSize = 0;
	allocated = 1;
}

MinHeap::MinHeap(BTreeNode** array, int size)
{
	heapSize = size;
	maxSize = size;
	allocated = 1;
	data = array;

	for (int i = (maxSize / 2) - 1; i >= 0; i--)
		fixHeap(i);
}

MinHeap::~MinHeap()
{
	if (allocated == 1)
	delete[] data;
}

BTreeNode* MinHeap::DeleteMin()
{
	if (heapSize < 1) {
		cout << "Invalid input" << endl;
		return nullptr;
	}
	BTreeNode* min = new BTreeNode;
	min = data[0];
	heapSize--;
	data[0] = data[heapSize];
	fixHeap(0);
	return min;
}

void MinHeap::insert(BTreeNode* node)
{

	if (heapSize == maxSize)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}
	int i = heapSize;
	heapSize++;

	while ((i > 0) && (data[parent(i)]->getFrequency() > node->getFrequency()))
	{
		data[i] = data[parent(i)];
		i = parent(i);
	}

	data[i] = node;
}

void MinHeap::printInOrder(BTreeNode* root)
{
	if (data != nullptr)
		data[0]->printInOrder();
}


void MinHeap::fixHeap(int i)
{

	int min;
	int left = this->left(i);
	int right = this->right(i);

	if ((left < heapSize) && (data[left]->getFrequency() < data[i]->getFrequency()))
		min = left;
	else
		min = i;
	if ((right < heapSize) && (data[right]->getFrequency() < data[min]->getFrequency()))
		min = right;
	if (min != i)
	{
		swap(data[i], data[min]);
		fixHeap(min);
	}
}

