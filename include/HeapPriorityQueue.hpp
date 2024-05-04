#ifndef HEAP_PRIORITY_QUEUE_HPP
#define HEAP_PRIORITY_QUEUE_HPP

#include "MaxHeap.hpp"

template <typename T>
class HeapPriorityQueue
{
private:
	MaxHeap queue_;
	size_t size_;

public:
	HeapPriorityQueue();
	~HeapPriorityQueue();

	void insert(T value, int priority);
	T exctractMax();
	void findMax();
	void modifyKey(T value, int priority);
	size_t getSize();
};

#endif