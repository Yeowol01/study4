#pragma once
#include <iostream>
#include <vector>

using namespace std;

#define SIZE 5

#pragma region ������ �����ε�
class Vector2
{
private:
	int x;
	int y;

public:
	Vector2(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2 operator+(const Vector2& vector2)
	{
		Vector2 clone(this->x + vector2.x, this->y + vector2.y);

		return clone;
	}

	Vector2 operator-(const Vector2& vector2)
	{
		Vector2 clone(this->x - vector2.x, this->y - vector2.y);

		return clone;
	}

	Vector2 operator*(const Vector2& vector2)
	{
		Vector2 clone(this->x * vector2.x, this->y * vector2.y);

		return clone;
	}

	Vector2 operator/(const Vector2& vector2)
	{
		Vector2 clone(this->x / vector2.x, this->y / vector2.y);

		return clone;
	}

	Vector2 operator++()
	{
		this->x++;
		this->y++;

		return *this;
	}

	Vector2 operator++(int)
	{
		Vector2 clone = *this;

		this->x++;
		this->y++;

		return clone;
	}

	int GetX()
	{
		return x;
	}

	int GetY()
	{
		return y;
	}
};

#pragma endregion


// int a[5] = { 8,2,6,3,7 };

/*
void bubblesort(int a[])
{
	int tmp;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}
*/

int main()
{
#pragma region ��ǰ ����
	// ���� ������ �� ���Ҹ� �˻��Ͽ� �����ϴ� �˰������Դϴ�.

	// �ð� ���⵵ o(n^2)

	/*
	bubblesort(a);

	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	*/

	/*
	int bubbleBuffer[SIZE] = { 0,4,3,2,1 };

		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < (SIZE - i) - 1; j++)
			{
				if (bubbleBuffer[j] > bubbleBuffer[j + 1])
				{
					swap(bubbleBuffer[j], bubbleBuffer[j + 1]);
				}
			}
		}

		for (const int & element : bubbleBuffer)
		{
			cout << element << " ";
		}
		*/


#pragma endregion

#pragma region ������ �����ε�

	Vector2 Up(0, 1);
	Vector2 Right(1, 0);

	// clone ��ü (1,1)
	Vector2 temp = Up + Right;

	Vector2 a = temp++;

	cout << temp.GetX() << endl;
	cout << temp.GetY() << endl;

	++temp;

	cout << temp.GetX() << endl;
	cout << temp.GetY() << endl;

#pragma endregion


	return 0;
}