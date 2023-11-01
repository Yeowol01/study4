#pragma once
#include <iostream>

using namespace std;

#pragma region ���� Ž�� Ʈ�� (BST)
	// ������ Ű�� ���� ���Ҹ� ����, ����, �˻��ϴµ� ȿ������ �˰����Դϴ�.

#pragma endregion


template <typename T>
class BinarySearchTree
{
private : 
	struct Node
	{
		T data;
		Node* left;
		Node* right;
	};

public : 

	Node* rootNode;

	BinarySearchTree()
	{
		rootNode = nullptr;
	}

	Node* GetRoot()
	{
		return rootNode;
	}

	Node * Insert(T data, Node* root)
	{
		if (Find(root, data) == true)
		{
			cout << "Duplicate Key" << endl;
			return root;
		}

		if (root == nullptr)
		{
			root = new Node;
			root->data = data;
			root->left = nullptr;
			root->right = nullptr;
		}
		else if (root->data > data) // else if root�� data���� �۴ٸ�?
		{
			root->left = Insert(data, root->left);
		}
		else if (root->data < data)
		{
			root->right = Insert(data, root->right);
		}

		return root;
	}

	bool Find(Node* root, T data)
	{
		if (root == nullptr)
		{
			return false;
		}

		if (root->data == data)
		{
			return true;
		}
		else
		{
			if (root->data > data)
			{
				return Find(root->left, data);
			}
			else
			{
				return Find(root->right, data);
			}
		}
	}

	T & FindMax(Node* root)
	{
		if (root == nullptr)
		{
			cout << "Binaryu Search Tree is Empty" << endl;
			exit(1);
		}

		if (root->right == nullptr)
		{
			return root->data;
		}
		else
		{
			return FindMax(root->right);
		}

	}

	T & FindMin(Node* root)
	{
		if (root == nullptr)
		{
			cout << "Binaryu Search Tree is Empty" << endl;
			exit(1);
		}

		if (root->left == nullptr)
		{
			return root->data;
		}
		else
		{
			return Findmin(root->left);
		}
	}

	void Inorder(Node* root)
	{
		if (root != nullptr)
		{
			Inorder(root->left);
			cout << root->data << " ";
			Inorder(root->right);
		}
	}
};