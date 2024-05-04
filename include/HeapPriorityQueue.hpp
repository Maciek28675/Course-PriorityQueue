#ifndef HEAP_PRIORITY_QUEUE_HPP
#define HEAP_PRIORITY_QUEUE_HPP

#include "Node.hpp"

template <typename T>
class HeapPriorityQueue
{
private:
	std::vector<Node<T>> heap_;
	size_t size_;

	void heapifyUp(int index);
	void heapifyDown(int index);

public:
	HeapPriorityQueue();
	HeapPriorityQueue(std::vector<Node<T>>, size_t);
	~HeapPriorityQueue();

	void insert(T value, int priority);
	Node<T> exctractMax();
	Node<T> findMax();
	void modifyKey(T value, int priority);
	size_t getSize();
	void display();
};

template <typename T>
HeapPriorityQueue<T>::HeapPriorityQueue()
{
	std::vector<Node<T>> heap;
	heap_ = heap;
	size_ = 0;

	std::cout << "Empty priority queue has been created!\n";
}

template <typename T>
HeapPriorityQueue<T>::HeapPriorityQueue(std::vector<Node<T>> heap, size_t size) : heap_(heap), size_(size)
{
	// Start index is the last non-leaf index
	int startIndex = (size_ / 2) - 1;

	for (int i = startIndex; i >= 0; i--)
	{
		heapifyDown(i);
	}
}

template <typename T>
HeapPriorityQueue<T>::~HeapPriorityQueue()
{
	std::cout << "priority queue has been deleted!\n";
}

template <typename T>
void HeapPriorityQueue<T>::heapifyUp(int index)
{
	int parentIndex = (index - 1) / 2;

	while ((index > 0) && (heap_[index].priority > heap_[parentIndex].priority))
	{
		std::swap(heap_[index], heap_[parentIndex]);
		index = parentIndex;
		parentIndex = (index - 1) / 2;
	}
}

template <typename T>
void HeapPriorityQueue<T>::heapifyDown(int index)
{
	//If there is only one node, the heap property is obviously satisfied
	if (size_ == 1)
		return;

	int leftChildIndex = 2 * index + 1;
	int rightChildIndex = 2 * index + 2;

	int largestElementIndex = index;

	if ((leftChildIndex < size_) && (heap_[leftChildIndex].priority > heap_[largestElementIndex].priority))
		largestElementIndex = leftChildIndex;

	if ((rightChildIndex < size_) && (heap_[rightChildIndex].priority > heap_[largestElementIndex].priority))
		largestElementIndex = rightChildIndex;

	if (largestElementIndex != index)
	{
		std::swap(heap_[index], heap_[largestElementIndex]);
		heapifyDown(largestElementIndex);
	}
}

//Insert new node into queue while satisfying heap property
template <typename T>
void HeapPriorityQueue<T>::insert(T value, int priority)
{
	heap_.push_back({ value, priority });
	heapifyUp(size_ - 1);
}

//Get element with highest priority and delete it
template <typename T>
Node<T> HeapPriorityQueue<T>::exctractMax()
{
	Node<T> oldRoot = heap_[0];
	heap_[0] = heap_[size_ - 1];
	heapifyDown(0);

	return oldRoot;
}

//Get element with highest priority
template <typename T>
Node<T> HeapPriorityQueue<T>::findMax()
{
	return heap_[0];
}

template <typename T>
void HeapPriorityQueue<T>::modifyKey(T value, int priority)
{
	int index = 0;

	//Traverse the heap to find specified element
	for (int i = 0; i < size_; i++)
	{
		if (heap_[i].value == value)
		{
			index = i;
			break;
		}
	}

	//If priority of found element is the same as specified priority do nothing
	if (heap_[index].priority == priority)
		return;

	//Incerease key
	if (priority > heap_[index].priority)
	{
		heap_[index].priority++;
		heapifyUp(index);
	}

	//Decrease key
	else if (priority < heap_[index].priority)
	{
		heap_[index].priority--;
		heapifyDown(index);
	}
}

template <typename T>
size_t HeapPriorityQueue<T>::getSize()
{
	return size_;
}

template <typename T>
void HeapPriorityQueue<T>::display()
{
	//in progress
}

#endif