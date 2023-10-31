#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int* ptr = nullptr;

void Function(int* x = ptr)
{

}

int main()
{
	Function();

	BinarySearchTree<int> bst;
	bst.Insert(1, bst.GetRoot());

	return 0;
}