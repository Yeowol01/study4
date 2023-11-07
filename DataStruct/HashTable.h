#pragma once
#include <iostream>
#include <string>

using namespace std;

#define SIZE 5

#pragma region 해시 테이블
// (Key, Value)로 데이터를 저장하는 자료 구조 중 하나로
// 빠르게 데이터를 검색할 수 있는 자료 구조입니다.
#pragma endregion

template<typename KEY, typename VALUE>
class HashTable
{
private:
	struct Node
	{
		KEY key;
		VALUE value;

		Node* next;
	};

	struct Bucket
	{
		int count;
		Node* head;
	};

	Bucket bucket[SIZE];
public:
	HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}
	}

	template<typename T>
	int HashFunction(T key)
	{
		int hashIndex = int(key) % SIZE;

		return hashIndex;
	}

	template<>
	int HashFunction(std::string key)
	{
		int sumValue = 0;

		for (const char& element : key)
		{
			sumValue += (int)element;
		}

		int hashIndex = sumValue % SIZE;

		return hashIndex;
	}

	Node* CreateNode(KEY key, VALUE value)
	{
		Node* newNode = new Node;

		newNode->key = key;

		newNode->value = value;

		newNode->next = nullptr;

		return newNode;
	}

	void Insert(KEY key, VALUE value)
	{
		// 해시 함수를 통해서 값을 받는 임시 변수
		int hashIndex = HashFunction(key);

		// 새로운 노드를 생성합니다.
		Node* newNode = CreateNode(key, value);

		// 노드가 1개 라도 존재하지 않는다면
		if (bucket[hashIndex].count == 0)
		{
			// 1. bucket[hashIndex]의 head 포인터에 새로운 노드의 주솟값을 저장합니다.
			bucket[hashIndex].head = newNode;

			// 2. bucket[hashIndex]의 count 변수의 값을 증가시킵니다.
			bucket[hashIndex].count++;
		}
		else // 노드가 1개 라도 존재한다면
		{
			// 1. NewNode의 next에 bucket[hashIndex]의 head의 값을 넣어줍니다.
			newNode->next = bucket[hashIndex].head;

			// 2. bucket[hashIndex].head를 방금 새로 생성한 노드의 주소를 가리키게 합니다.
			bucket[hashIndex].head = newNode;

			// 3. bucket[hashIndex].count의 값을 증가시킵니다.
			bucket[hashIndex].count++;
		}

	}

	void Remove(KEY key)
	{
		// 1. 해시 함수를 통해서 값을 받는 임시 변수
		int hashIndex = HashFunction(key);

		// 2. Node를 탐색할 수 있는 순회용 포인터 변수 선언
		// 각 Bucket의 Head를 저장합니다.
		Node* currentNode = bucket[hashIndex].head;
		
		// 3. 이전 노드를 저장할 수 있는 포인터 변수 선언
		Node* traceNode = nullptr;

		// 4. currentNode가 nullptr이라고 하면 함수를 종료합니다.
		if (currentNode == nullptr)
		{
			cout << "HashTable is Empty" << endl;
			return;
		}

		// 5. currentNode를 이용해서 내가 찾고자 하는 key 값을 찾으면 됩니다.
		while (currentNode != nullptr)
		{
			// currentNode->key 값과 내가 삭제하고 싶은 key 값이 같다면
			if (currentNode->key == key)
			{
				// 내가 삭제하고자 하는 key가 head에 있는 노드라면
				if (currentNode == bucket[hashIndex].head)
				{
					bucket[hashIndex].head = currentNode->next;
				}
				else
				{
					traceNode->next = currentNode->next;
				}

				// 각 bucket의 카운트를 감소시킵니다.
				bucket[hashIndex].count--;

				// 해당 메모리를 삭제합니다.
				delete currentNode;

				return;
			}

			traceNode = currentNode;
			currentNode = currentNode->next;
		}

		cout << "Not key Found" << endl;
	}

	void Display()
	{
		for (int i = 0; i < SIZE; i++)
		{
			Node* currentNode = bucket[i].head;

			while (currentNode != nullptr)
			{
				cout << "[" << i << "]" << "KEY : " << currentNode->key << "VALUE : " << currentNode->value << " --->";
				currentNode = currentNode->next;
			}

			cout << endl;
		}
	}

	~HashTable()
	{

	}

};