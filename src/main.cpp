#include <iostream>
#include "MaxHeap.hpp"

int main()
{
	std::vector<int> data = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
	MaxHeap<int> h1(data, data.size());

	std::cout << "Hello World!\n";

	// #TODO:
	// - Add method to display heap graphicly

	return 0;
}