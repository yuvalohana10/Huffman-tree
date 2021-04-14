#include "BSTreeNode.h"
using namespace std;


BSTreeNode::BSTreeNode()
{
	left = right = nullptr;
}
BSTreeNode::BSTreeNode(Pair item, BSTreeNode* left, BSTreeNode* right)
{

	data.key = item.key;
	data.frequency = item.frequency;
	this->left = left;
	this->right = right;
}
void BSTreeNode::setFrequency(int f)
{
	this->data.frequency = f;
}
void BSTreeNode::printInOrder()
{
	if (left != nullptr)
		left->printInOrder();
	cout << data.key << " " << data.frequency << endl;
	if (right != nullptr)
		right->printInOrder();
}
