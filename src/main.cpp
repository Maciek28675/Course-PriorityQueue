#include <iostream>
#include "MaxHeap.hpp"
#include "HeapPriorityQueue.hpp"
#include "Utilities.hpp"

int main()
{
	measurePerformance(10000, 10000);
	measurePerformance(10000, 20000);
	measurePerformance(10000, 30000);
	measurePerformance(10000, 40000);
	measurePerformance(10000, 50000);
	measurePerformance(10000, 60000);
	measurePerformance(10000, 70000);
	measurePerformance(10000, 80000);
	measurePerformance(10000, 90000);
	measurePerformance(10000, 100000);
	measurePerformance(10000, 110000);
	measurePerformance(10000, 120000);
	measurePerformance(10000, 130000);
	measurePerformance(10000, 140000);
	measurePerformance(10000, 150000);
	measurePerformance(10000, 200000);
	measurePerformance(10000, 250000);
	measurePerformance(10000, 300000);
	measurePerformance(10000, 400000);
	measurePerformance(10000, 500000);
	

	/*
	std::vector<Node<int>> data = {
		{4, 4},
		{10, 10},
		{3, 3},
		{5, 5},
		{1, 1},
	};

	HeapPriorityQueue<int> pq(data, data.size());

	pq.display();
	*/

	// #TODO:
	// - Add method to display heap graphicly
	// - Add a menu
	// - Add exception handling

	return 0;
}