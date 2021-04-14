#include "BTreeNode.h"

BTreeNode::BTreeNode()
{
	this->left = nullptr;
	this->right = nullptr;
}

BTreeNode::BTreeNode(Pair item, BTreeNode* left, BTreeNode* right)
{
	data.frequency = item.frequency;
	data.key = item.key;
	this->left = left;
	this->right = right;
}


void BTreeNode::printInOrder()
{
	if (left != nullptr)
		left->printInOrder();
	cout << data.key << " " << data.frequency << endl;
	if (right != nullptr)
		right->printInOrder();
}

bool BTreeNode::isLeaf()
{
	if (left == nullptr && right == nullptr)
		return true;
	return false;
}

void BTreeNode::setFrequency(int f) {
	data.frequency = f;
}


