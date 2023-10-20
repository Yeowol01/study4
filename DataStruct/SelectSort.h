#pragma once
#include <iostream>

using namespace std;

int main()
{
#pragma region 선택 정렬
	// 정렬되지 않은 데이터들에 대해 가장 작은 데이터를 찾아서 가장 앞에 있는 데이터와 교환하는 알고리즘입니다.

	// 시간 복잡도 o(n^2)

	int selectBuffer[] = { 6,2,8,1,0 };

	int size = sizeof(selectBuffer) / sizeof(int);

	for (int i = 0; i < size; i++)
	{
		int min = selectBuffer[i]; // 6

		int select = i;

		for (int j = i + 1; j < size; j++)
		{
			if (min > selectBuffer[j])
			{
				min = selectBuffer[j];
				select = j;
			}
		}

		swap(selectBuffer[i], selectBuffer[select]);
	}

	for (int& element : selectBuffer)
	{
		cout << element << " ";
	}

#pragma endregion



	return 0;
}