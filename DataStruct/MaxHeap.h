#pragma once
#include <iostream>

using namespace std;

#define SIZE 8

template <typename T>
class MaxHeap
{
private : 
	T heapBuffer[SIZE];
	int index;

	void MaxHeapify(int rootIndex)
	{
		int largest = rootIndex;
		int leftChild = 2 * rootIndex;
		int rightChild = 2 * rootIndex + 1;

		if (leftChild <= index && heapBuffer[leftChild] > heapBuffer[largest])
		{
			largest = leftChild;
		}

		if (rightChild <= index && heapBuffer[rightChild] > heapBuffer[largest])
		{
			largest = rightChild;
		}

		if (largest != rootIndex)
		{
			swap(heapBuffer[rootIndex], heapBuffer[largest]);
			MaxHeapify(largest);
		}
	}

public : 
	MaxHeap()
	{
		for (int i = 0; i < SIZE; i++)
		{
			heapBuffer[i] = NULL;
		}

		index = 0;
	}

	void Insert(T data)
	{
		if (IsFull())
		{
			cout << "MaxHeap is Full" << endl;
			return;
		}

		heapBuffer[++index] = data;

		int child = index;
		int parent = index / 2;

		while (child > 1)
		{
			// �ڽ� ���� �θ� ����� �����͸� ���մϴ�.
			if (heapBuffer[parent] < heapBuffer[child])
			{
				swap(heapBuffer[parent], heapBuffer[child]);
			}

			child = parent;
			parent = child / 2;
		}

	}

	T& Delete()
	{
		// 1. Heap�� ����ִٸ� ���α׷��� �����մϴ�.
		if (index <= 0)
		{
			cout << "Heap is Empty" << endl;
			exit(1);
		}

		// 2. �ӽ� ���� <- ���� ū ���� �����ϴ� ����
		T result = heapBuffer[1];

		// 3. index�� ����Ű�� �迭�� ���� ù ��° ���ҿ� �־��ݴϴ�.
		heapBuffer[1] = heapBuffer[index];

		// 4. index�� ����Ű�� �迭�� ���� �ʱ�ȭ�մϴ�.
		heapBuffer[index] == NULL;

		// 5. index�� ���� ���ҽ�ŵ�ϴ�.
		index--;

		int parent = 1;

		while (parent * 2 <= index)
		{
			int child = parent * 2;

			// ������ �ڽ��� ��尡 Ŭ ��
			if (heapBuffer[child] <= heapBuffer[child] + 1)
			{
				child++;
			}

			// �θ� ����� Key ���� �ڽ� ����� Key ������ ũ�ٸ� �ݺ��� �����մϴ�.
			if (heapBuffer[child] < heapBuffer[parent])
			{
				break;
			}

			swap(heapBuffer[parent], heapBuffer[child]);
			parent = child;
		}

		return result;
	}

	/*
	void DeleteMax()
	{
		if (IsEmpty())
		{
			cout << "MaxHeap is Empty" << endl;
			return;
		}

		// ��Ʈ ���� ������ ��带 ��ȯ
		swap(heapBuffer[1], heapBuffer[index]);

		// ��Ʈ ��带 ����
		heapBuffer[index] = NULL;
		index--;

		// �ִ� �� �Ӽ��� �����ϵ��� ��Ʈ�������� ����
		MaxHeapify(1);
	}
	*/

	bool IsEmpty()
	{
		return (index == 0);
	}
	
	bool IsFull()
	{
		if (index == SIZE - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Display()
	{
		for (const T & element : heapBuffer)
		{
			cout << element << " ";
		}
	}

};