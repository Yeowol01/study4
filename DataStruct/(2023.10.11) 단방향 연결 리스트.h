#pragma once
#include <iostream>

using namespace std;

#pragma region 단일 연결 리스트

// 1. 단일 연결 리스트 노드 제작

struct Node
{
    int data;
    Node* next;
};
#pragma endregion

void PushFront(Node* target, int data)
{
    Node* newNode = new Node;
    newNode->data = data;

    newNode->next = target->next;

    target->next = newNode;
}

void Remove(Node* target)
{
    Node* deleteNode = target->next;

    target->next = deleteNode->next;

    delete deleteNode;
}

int main()
{
#pragma region 단일 연결 리스트
    /*
    Node* head = new Node;
    Node* node1 = new Node;
    Node* node2 = new Node;
    Node* node3 = new Node;

    head->data = NULL;
    head->next = node1;

    node1->data = 10;
    node1->next = node2;

    node2->data = 20;
    node2->next = node3;

    node3->data = 30;
    node3->next = nullptr;

    Node* currentPtr = head->next;

    while (currentPtr != nullptr)
    {
        cout << currentPtr->data << endl;
        currentPtr = currentPtr->next;
    }
    */

    Node* head = new Node;
    head->next = nullptr;

    PushFront(head, 10);
    PushFront(head, 20);

    Remove(head);

    Node* currentPtr = head->next;

    while (currentPtr != nullptr)
    {
        cout << currentPtr->data << endl;
        currentPtr = currentPtr->next;
    }

#pragma endregion
}

