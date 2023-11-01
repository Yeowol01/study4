#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	BinarySearchTree<int> bst;

	bst.rootNode = bst.Insert(10, bst.rootNode);

	bst.Insert(5, bst.rootNode);
	bst.Insert(15, bst.rootNode);

	cout << bst.FindMax(bst.rootNode) << endl;

	bst.Inorder(bst.GetRoot());

	return 0;
}