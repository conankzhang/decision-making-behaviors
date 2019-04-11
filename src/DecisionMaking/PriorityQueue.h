#pragma once

#include <queue>

template<typename T, class Container=std::vector<T>, class Compare=std::less<typename Container::value_type>>
class CPriorityQueue : public std::priority_queue<T, Container, Compare>
{
public:

	bool remove(const T& value)
	{

		auto it = std::find(this->c.begin(), this->c.end(), value);

		if (it != this->c.end())
		{
			this->c.erase(it);
			std::make_heap(this->c.begin(), this->c.end(), this->comp);

			return true;
		}
		else
		{
			return false;
		}
	}

	Container& get_container() { return c; }
};
