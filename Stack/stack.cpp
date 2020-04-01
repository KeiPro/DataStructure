#include<iostream>
#define NUM 10
using namespace std;

template<typename T>

class stack
{
private:
	T data[NUM];
	int level;
public:
	stack()
	{
		this->level = -1;
	}

	bool push(T data)
	{
		if (full()) return false;
		else
		{
			this->data[++(this->level)] = data;
			return true;
		}
	}

	T pop()
	{
		if (isEmpty()) return NULL;
		else
		{
			return this->data[(this->level)--];
		}
	}

	T peek()
	{
		if (isEmpty()) return NULL;
		else
		{
			return this->data[this->level];
		}
	}
};

int main()
{
	return 0;
}