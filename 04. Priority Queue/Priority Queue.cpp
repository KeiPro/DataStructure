#include <iostream>
#include <vector>

class priority_queue
{
public:

	priority_queue();
	void push(int);
	int pop();
	int top();
	bool isEmpty();
	void swap(int, int);

	
private:

	std::vector<int> _container;
};

priority_queue::priority_queue()
{
	_container.reserve(10);
}

void priority_queue::push(int num)
{
	_container.push_back(num);

	int currIndex = _container.size() - 1;
	while (currIndex != 0)
	{
		int parentIndex = (currIndex - 1) / 2;
		if (_container[currIndex] > _container[parentIndex])
		{
			swap(currIndex, parentIndex);
			currIndex = parentIndex;
			continue;
		}
		else break;
	}
}

void priority_queue::swap(int index1, int index2)
{
	int temp = _container[index1];
	_container[index1] = _container[index2];
	_container[index2] = temp;
}

int priority_queue::pop()
{
	if (_container.size() <= 0)
	{
		std::cout << "not exist items." << std::endl;
		return -1;
	}

	int returnValue = _container[0];

	_container[0] = _container[_container.size() - 1];
	_container.pop_back();

	int currIndex = 0;

	while (true)
	{
		// ¿ÞÂÊ ÀÚ½Ä
		int left = (currIndex + 1) * 2 - 1;
		int right = (currIndex + 1) * 2;

		int nextIndex = currIndex;
		if (left < _container.size() && _container[nextIndex] < _container[left])
			nextIndex = left;

		if (right < _container.size() && _container[nextIndex] < _container[right])
			nextIndex = right;

		if (nextIndex == currIndex)
			break;

		swap(currIndex, nextIndex);
		currIndex = nextIndex;
	}

	return returnValue;
}

int priority_queue::top()
{
	return _container[0];
}

bool priority_queue::isEmpty()
{
	return _container.empty();
}

int main()
{
	priority_queue pq;
	for (int i = 1; i <= 10; i++)
		pq.push(i * 10);

	for (int i = 0; i < 10; i++)
		std::cout << pq.pop() << " ";

	std::cout << pq.isEmpty();
}


