// 1. 스택의 구조 : 가장 나중에 들어온 data가 가장 먼저 나간다(LIFO)
//			    스택은 top이라고 하는 변수가 존재하는데, 이 변수를 통해
//				가장 위에 데이터가 들어오거나 반환된다.

// 2. 스택에는 다음과 같은 연산이 존재한다.
//		- push : 스택에 새로운 원소를 삽입한다.
//		- pop  : 스택의 top원소를 제거하고 반환한다.
//		- empty : 스택이 비어있는지를 단순 검사한다.
//		- full : 스택이 꽉 차있는지를 단순 검사한다.
//		- size : 스택의 크기를 확인한다.
//		- peek : 스택의 맨 최상단에 있는 값을 단순 검사한다.

//배열을 활용한 스택 구현.
#include<iostream>
using namespace std;

const int arraySize = 100;
int stack[arraySize], top = -1;

void push(int x);
int pop();
bool isEmpty();
bool isFull();

void push(int x)
{
	if (isFull())
	{
		cout << "스택이 꽉 차있습니다." << endl;
		return;
	}
	else
		stack[++top] = x;

}

int pop()
{
	if (isEmpty())
	{
		cout << "스택이 비어있습니다." << endl;
	}
	else
		return stack[top--];
}

bool isEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}

bool isFull()
{
	if (top == arraySize - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	for (int i = 0; i < arraySize; i++)
	{
		push(i);
	}

	for (int i = 0; i < arraySize; i++)
	{
		cout << pop() << " ";
		if ((i+1) % 10 == 0)
			cout << endl;
	}
	return 0;
}