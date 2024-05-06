
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "Node.hpp"
#include "fibonacciHeapNode.hpp"

template <typename T>
class Queue
{
public:
	virtual void insert(T value, int index) = 0;
	virtual Node<T> extractMax() = 0;
	virtual Node<T> findMax() = 0;
	virtual void getSize() = 0;
	virtual void display() = 0;

	virtual void modifyKey(T value, int priority) = 0;
	virtual void modifyKey(FibonacciHeapNode<T>* node, T newKey) = 0;
};

#endif