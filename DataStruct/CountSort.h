#pragma once
#include <iostream>

using namespace std;

#define COUNT_SIZE 5
#define BUFFER_SIZE 10

int main()
{
#pragma region ��� ����
	// �������� ���� ���� ������ �ʰ�, �ܼ��ϰ� �� ���ڰ� �� �� �ִ��� ������ ���� ������ ���� �����ϴ� �˰����Դϴ�.

	// �ð� ���⵵ : O(n + k)

	int buffer[BUFFER_SIZE] = { 1,5,3,4,4,3,1,2,5,1 };

	int countBuffer[COUNT_SIZE] = { 0, };

	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		countBuffer[buffer[i] - 1] += 1;
	}

	for (int i = 0; i < COUNT_SIZE; i++)
	{
		cout << countBuffer[i] << endl;
	}

#pragma endregion

}