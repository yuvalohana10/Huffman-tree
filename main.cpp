#include "BSTree.h"
#include "BTree.h"
#include "PriorityQueue.h"

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

//This program is getting a string whitch is a name of a file.the program builds a binart search tree that contains thr chars from the text file and
//their frequency.Then, we convers the tree into an array in order to build a min heap for the huffman algoritem.After we build the min heap we creats an huffman tree.
//We prints the chars and their huffman decodes and the size of the decoded file.


int makeArrFromTree(BSTreeNode* root, BTreeNode* array[], int i);//This function read from my file and update fileBSTree( a binary search tree)
BTreeNode* Huffman(BTreeNode** arr, int n);//make an huffman tree from  minheap
int printHuffmanCode(string str, BTreeNode* root);// print huffman code 

int main() {

	string fileName;
	BSTree fileBSTree;
	ifstream myFile;
	
	//Getting file name 
	getline(cin, fileName);
	myFile.open(fileName); // open file

	//check if open succeded
	if (!myFile)
	{
		cout << "invalid input";
		exit(1);
	}

	//build a binart search tree from file
	fileBSTree.buildTreeFromFile(myFile);
	//get the count of the node in the tree
	int count = fileBSTree.getCount();

	//dynaic hallocation
	BTreeNode** array = new BTreeNode * [count];
	for (int i = 0; i < count; i++)
		array[i] = new BTreeNode;

	//build array from tree
	int i = makeArrFromTree(fileBSTree.getRoot(), array, 0);

	//create huffman tree
	BTreeNode* huffmanRoot = Huffman(array, count);
	string str;

	//print huffman code 
	int fileSize = printHuffmanCode(str, huffmanRoot);

	//print file size 
	cout << endl << fileSize << endl;

	myFile.close();
}

int makeArrFromTree(BSTreeNode* root, BTreeNode* array[], int i)
{
	if (root == nullptr)

		return i;

	array[i]->setFrequency(root->getData().frequency);
	array[i]->setKey(root->getData().key);

	i++;
	if (root->getLeft() != nullptr)
		i = makeArrFromTree(root->getLeft(), array, i);
	if (root->getRight() != nullptr)
		i = makeArrFromTree(root->getRight(), array, i);
	return i;
}

BTreeNode* Huffman(BTreeNode** arr, int n)
{
	PriorityQueue Q(arr, n);
	BTreeNode* node, * right, * left;
	int i;
	
	for (int i = 1; i < n; i++)
	{
		BTreeNode*  node = new BTreeNode;
		left = new BTreeNode;
		right = new BTreeNode;
		node->setLeft(Q.DeleteMin());
		node->setRight(Q.DeleteMin());
		node->setFrequency(node->getLeft()->getFrequency() + node->getRight()->getFrequency());
		Q.insert(node);
	}
	return Q.DeleteMin();
}

int printHuffmanCode(string str, BTreeNode* root)
{
	int size = 0;

	if (root == nullptr)
		return -1;
	if (root->isLeaf() == true)
	{
		if (root->getValue().key == '\n')
			cout << "'\\n'" << ": " << str << endl;
		else if (str.length() == 0)
			str = "1";
		
		cout << "'" << root->getValue().key << "' : " << str << endl;

		size = (root->getFrequency() * str.length());
	}

	else
	{
		if (root->getLeft())
			size += printHuffmanCode(str + "0", root->getLeft());


		if (root->getRight())
			size += printHuffmanCode(str + "1", root->getRight());
	}

	return size;
		
}
