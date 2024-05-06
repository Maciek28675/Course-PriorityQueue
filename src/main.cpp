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

	// #TODO:
	// - Add method to display heap graphicly
	// - Add '<<' operator overload for Node struct

	return 0;
}