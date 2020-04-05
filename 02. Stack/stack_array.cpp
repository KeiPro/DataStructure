// 1. ������ ���� : ���� ���߿� ���� data�� ���� ���� ������(LIFO)
//			    ������ top�̶�� �ϴ� ������ �����ϴµ�, �� ������ ����
//				���� ���� �����Ͱ� �����ų� ��ȯ�ȴ�.

// 2. ���ÿ��� ������ ���� ������ �����Ѵ�.
//		- push : ���ÿ� ���ο� ���Ҹ� �����Ѵ�.
//		- pop  : ������ top���Ҹ� �����ϰ� ��ȯ�Ѵ�.
//		- empty : ������ ����ִ����� �ܼ� �˻��Ѵ�.
//		- full : ������ �� ���ִ����� �ܼ� �˻��Ѵ�.
//		- size : ������ ũ�⸦ Ȯ���Ѵ�.
//		- peek : ������ �� �ֻ�ܿ� �ִ� ���� �ܼ� �˻��Ѵ�.

//�迭�� Ȱ���� ���� ����.
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
		cout << "������ �� ���ֽ��ϴ�." << endl;
		return;
	}
	else
		stack[++top] = x;

}

int pop()
{
	if (isEmpty())
	{
		cout << "������ ����ֽ��ϴ�." << endl;
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