#ifndef MAX_HEAP_HPP
#define MAX_HEAP_HPP

#include <vector>

template <typename T>
class MaxHeap
{
private:
	std::vector<T> heap_;
	int size_;

	void heapifyUp(int index);
	void heapifyDown(int index);

public:
	MaxHeap(std::vector<T>, int);
	MaxHeap();
	~MaxHeap();

	int getSize();
	void insert(int value);
	void display();
};

//Initialize max heap with data
template <typename T>
MaxHeap<T>::MaxHeap(std::vector<T> heap, int size) : heap_(heap), size_(size)
{
	// Start index is the last non-leaf index
	int startIndex = (size_ / 2) - 1;

	for (int i = startIndex; i >= 0; i--)
	{
		heapifyDown(i);
	}
 }

//Initialize empty max heap
template <typename T>
MaxHeap<T>::MaxHeap()
{
	std::vector<T> heap{};
	heap_ = heap;
	size_ = 0;

	std::cout << "Empty max heap has been created!\n";
}

template <typename T>
MaxHeap<T>::~MaxHeap() { std::cout << "Max heap has been deleted!\n"; }

// Ensure that heap property is satisfied (moving up)
template <typename T>
void MaxHeap<T>::heapifyUp(int index)
{
	int parentIndex = (index - 1) / 2;

	while ((index > 0) && (heap_[index] > heap_[parentIndex]))
	{
		std::swap(heap_[index], heap_[parentIndex]);
		index = parentIndex;
		parentIndex = (index - 1) / 2;
	}
}

// Ensure that heap property is satisfied (moving down)
template <typename T>
void MaxHeap<T>::heapifyDown(int index)
{
	//If there is only one node, the heap property is obviously satisfied
	if (size_ == 1)
		//return;

	int leftChildIndex = 2 * index + 1;
	int rightChildIndex = 2 * index + 2;

	int largestElementIndex = index;

	if ((leftChildIndex < size_) && (heap_[leftChildIndex] > heap_[largestElementIndex]))
		largestElementIndex = leftChildIndex;

	if ((rightChildIndex < size_) && (heap_[rightChildIndex] > heap_[largestElementIndex]))
		largestElementIndex = rightChildIndex;

	if (largestElementIndex != index)
	{
		std::swap(heap_[index], heap_[largestElementIndex]);
		heapifyDown(largestElementIndex);
	}
}

#endif
