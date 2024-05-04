#include <iostream>
#include "MaxHeap.hpp"
#include "HeapPriorityQueue.hpp"

int main()
{
	std::vector<int> data = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
	MaxHeap<int> h1(data, data.size());

	std::vector<Node<int>> data1 = {
		{1, 1},
		{3, 3},
		{5, 5},
		{4, 4},
		{6, 6},
		{13, 13},
		{10, 10},
		{9, 9},
		{8, 8},
		{15, 15},
		{17, 17}
	};

	HeapPriorityQueue<int> pq(data1, data1.size());
	Node<int> n1;

	n1 = pq.findMax();

	std::cout << n1.priority << " " << n1.value << '\n';
	std::cout << "Hello World!\n";

	// #TODO:
	// - Add method to display heap graphicly
	// - Add '<<' operator overload for Node struct

	return 0;
}