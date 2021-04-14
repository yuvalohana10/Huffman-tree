#pragma once
#include "MinHeap.h"

class PriorityQueue :public MinHeap
{

public:

	PriorityQueue(BTreeNode** array, int size) : MinHeap(array, size) { ; }
};