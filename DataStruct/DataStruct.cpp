#include "SingleLinkedList.h"

int main()
{
	SingleLinkedList<int> list;

	list.PushFront(10);
	list.PushFront(20);
	list.PopFront();

	cout << "list의 사이즈 : " << list.Size() << endl;

	list.Display();
}