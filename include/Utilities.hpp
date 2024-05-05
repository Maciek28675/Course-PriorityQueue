#ifndef UTILITIES_HPP
#define UTILITIES_HPP

template <typename T>
std::vector<T> generateData(int size, int seed = time(NULL), int start = 0, int end = 10 000)
{
	srand(seed);
	std::vector<T> data;
	for (int i = 0; i < size; i++)
	{
		data.push_back(rand() % (end - start) + start);
	}
	return data;
}

template <typename T>
std::vector<T> generatePriorities(const std::vector<T>& data, int start = 0, int end)
{
	std::vector<T> priorities;
	end = data.size()*10
	
	for (int i = 0; i < data.size(); i++)
	{
		priorities.push_back(rand() % (end - start) + start);
	}

	return priorities;
}

#endif
