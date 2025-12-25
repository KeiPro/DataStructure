#pragma once
#include <iostream>
#include <vector>

template<typename Compare>
class kei_priority_queue
{
public:

	void push(int num)
	{
		_container.push_back(num);

		int currIndex = static_cast<int>(_container.size()) - 1;
	
		while (currIndex != 0)
		{
			int parentIndex = (currIndex - 1) / 2;

			if (_comp(_container[currIndex], _container[parentIndex]) == false)
				break;

			std::swap(_container[currIndex], _container[parentIndex]);
			currIndex = parentIndex;
		}
	}


	int pop()
	{
		if (isEmpty())
			throw std::out_of_range("Cannot pop from an empty priorityQ");

		int returnValue = _container[0];

		_container[0] = _container.back();
		_container.pop_back();

		int currIndex = 0;
		int containerSize = static_cast<int>(_container.size());

		while (true)
		{
			int left = (currIndex + 1) * 2 - 1;
			int right = (currIndex + 1) * 2;

			int bestIndex = currIndex;
			if (left < containerSize && _comp(_container[left], _container[bestIndex]))
				bestIndex = left;

			if (right < containerSize && _comp(_container[right], _container[bestIndex]))
				bestIndex = right;

			if (bestIndex == currIndex)
				break;

			std::swap(_container[currIndex], _container[bestIndex]);
			currIndex = bestIndex;
		}

		return returnValue;
	}

	int top() const
	{
		if (isEmpty())
			throw std::out_of_range("Cannot get top element from an empty priority queue.");

		return _container[0];
	}

	bool isEmpty() const
	{
		return _container.empty();
	}

private:

	std::vector<int> _container;
	Compare _comp;
};