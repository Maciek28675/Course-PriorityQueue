#include <iostream>
#include "MaxHeap.hpp"
#include "HeapPriorityQueue.hpp"
#include "Utilities.hpp"
#include "Menu.hpp"

int main()
{
	/*
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
	*/
	/////////////////////////// TESTS ///////////////////////////////

	
	DataTypeMenu m1;
	m1.run();
	
	/*
	std::vector<int> priorities = generateIntDataSet(100, 1, 0, 500);
	std::vector<int> elements = generateIntDataSet(100, 2);
		std::vector<Node<int>> nodes;

	for (int i = 0; i < 100; i++)
	{
		nodes.push_back({ elements[i], priorities[i] });
	}

	HeapPriorityQueue<int> pq(nodes, nodes.size());

	pq.display();
	*/

	// TODO: Add a menu
	// TODO: Add exception handling
	// TODO: Fix extract max in fibonnaci heap
	// TODO: Add a README.md

	return 0;
}