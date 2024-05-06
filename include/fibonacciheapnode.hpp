#ifndef FIBONACCI_HEAP_NODE_HPP
#define FIBONACCI_HEAP_NODE_HPP

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include "node.hpp"
#include "Queue.hpp"


template <typename T>
class FibonacciHeapNode
{
public:
	FibonacciHeapNode(T key, int prio) : key(key), priority(prio), parent(nullptr), child(nullptr), left(this), right(this), degree(0), mark(false) {}
	~FibonacciHeapNode();

	T key;
	FibonacciHeapNode<T>* parent;
	FibonacciHeapNode<T>* child;
	FibonacciHeapNode<T>* left;
	FibonacciHeapNode<T>* right;
	int degree;
	int piority;
	bool mark;
};

template <typename T>
class FibonacciHeap : public Queue<T>
{
public:
	FibonacciHeap() : minNode(nullptr), numOfNodes(0) {}
	~FibonacciHeap();
	
	void insert(T key, int priority) override;
	Node<T> extractMax() override;
	Node<T> findMax() override;
	Node<T> peek();
	void modifyKey(FibonacciHeapNode<T>* node, T newKey) override;
	void modifyKey(T value, int priority) override {}
	size_t getSize() override;
	void display() override;

private:
	FibonacciHeapNode<T>* minNode;
	size_t numOfNodes;

	void consolidate();
	void link(FibonacciHeapNode<T>* node1, FibonacciHeapNode<T>* node2);
	void cut(FibonacciHeapNode<T>* node, FibonacciHeapNode<T>* parent);
};

template <typename T>
FibonacciHeap<T>::~FibonacciHeap()
{
	if (minNode != nullptr)
	{
		FibonacciHeapNode<T>* start = minNode;
		FibonacciHeapNode<T>* current = minNode;
		do
		{
			FibonacciHeapNode<T>* next = current->right;
			delete current;
			current = next;
		} while (current != start);
	}
}

template <typename T>
void FibonacciHeap<T>::insert(T key, int priority)
{
	FibonacciHeapNode<T>* newNode = new FibonacciHeapNode<T>(key, priority);
	if (minNode == nullptr)
	{
		minNode = newNode;
	}
	else
	{
		minNode->left->right = newNode;
		newNode->left = minNode->left;
		minNode->left = newNode;
		newNode->right = minNode;
		if (newNode->priority > minNode->priority)
		{
			minNode = newNode;
		}
	}
	numOfNodes++;
}

template <typename T>
Node<T> FibonacciHeap<T>::extractMax()
{
	if (minNode == nullptr)
	{
		return;
	}
	FibonacciHeapNode<T>* maxNode = minNode;
	if (maxNode->child != nullptr)
	{
		FibonacciHeapNode<T>* start = maxNode->child;
		FibonacciHeapNode<T>* current = maxNode->child;
		do
		{
			FibonacciHeapNode<T>* next = current->right;
			current->parent = nullptr;
			current->right = minNode->right;
			current->left = minNode;
			minNode->right->left = current;
			minNode->right = current;
			if (current->priority > minNode->priority)
			{
				minNode = current;
			}
			current = next;
		} 
		while (current != start);
	}
	maxNode->left->right = maxNode->right;
	maxNode->right->left = maxNode->left;
	if (maxNode == maxNode->right)
	{
		minNode = nullptr;
	}
	else
	{
		minNode = maxNode->right;
		consolidate();
	}
	numOfNodes--;
	delete maxNode;
}

template <typename T>
Node<T> FibonacciHeap<T>::findMax()
{
	return minNode;
}

template <typename T>
Node<T> FibonacciHeap<T>::peek()
{
	return minNode;
}

template <typename T>
void FibonacciHeap<T>::modifyKey(FibonacciHeapNode<T>* node, T newKey)
{
	if (newKey < node->key)
	{
		node->key = newKey;
		FibonacciHeapNode<T>* parent = node->parent;
		if (parent != nullptr && node->priority < parent->priority)
		{
			cut(node, parent);
			while (parent != nullptr && parent->mark)
			{
				cut(parent, parent->parent);
				parent = parent->parent;
			}
		}
		if (node->priority > minNode->priority)
		{
			minNode = node;
		}
	}
}

template <typename T>
size_t FibonacciHeap<T>::getSize()
{
	return numOfNodes;
}

template <typename T>
void FibonacciHeap<T>::display()
{
	if (minNode == nullptr)
	{
		return;
	}
	FibonacciHeapNode<T>* start = minNode;
	FibonacciHeapNode<T>* current = minNode;
	do
	{
		std::cout << current->key << " ";
		current = current->right;
	} while (current != start);
	std::cout << std::endl;
}

template <typename T>
void FibonacciHeap<T>::consolidate()
{
	int maxDegree = 0;
	FibonacciHeapNode<T>* start = minNode;
	FibonacciHeapNode<T>* current = minNode;
	do
	{
		FibonacciHeapNode<T>* next = current->right;
		int degree = current->degree;
		while (degree >= maxDegree)
		{
			maxDegree *= 2;
		}
		FibonacciHeapNode<T>* arr[maxDegree];
		for (int i = 0; i < maxDegree; i++)
		{
			arr[i] = nullptr;
		}
		FibonacciHeapNode<T>* x = current;
		while (arr[x->degree] != nullptr)
		{
			FibonacciHeapNode<T>* y = arr[x->degree];
			if (x->priority < y->priority)
			{
				FibonacciHeapNode<T>* temp = x;
				x = y;
				y = temp;
			}
			link(y, x);
			arr[x->degree - 1] = nullptr;
		}
		arr[x->degree] = x;
		current = next;
	} while (current != start);
	minNode = nullptr;
	for (int i = 0; i < maxDegree; i++)
	{
		if (arr[i] != nullptr)
		{
			if (minNode == nullptr)
			{
				minNode = arr[i];
				minNode->left = minNode;
				minNode->right = minNode;
			}
			else
			{
				minNode->left->right = arr[i];
				arr[i]->left = minNode->left;
				minNode->left = arr[i];
				arr[i]->right = minNode;
				if (arr[i]->priority > minNode->priority)
				{
					minNode = arr[i];
				}
			}
		}
	}
}

template <typename T>
void FibonacciHeap<T>::link(FibonacciHeapNode<T>* node1, FibonacciHeapNode<T>* node2)
{
	node1->left->right = node1->right;
	node1->right->left = node1->left;
	node1->parent = node2;
	if (node2->child == nullptr)
	{
		node2->child = node1;
		node1->left = node1;
		node1->right = node1;
	}
	else
	{
		node1->right = node2->child;
		node1->left = node2->child->left;
		node2->child->left->right = node1;
		node2->child->left = node1;
	}
	node2->degree++;
	node1->mark = false;
}

template <typename T>
void FibonacciHeap<T>::cut(FibonacciHeapNode<T>* node, FibonacciHeapNode<T>* parent)
{
	node->left->right = node->right;
	node->right->left = node->left;
	parent->degree--;
	if (parent->child == node)
	{
		parent->child = node->right;
	}
	if (parent->degree == 0)
	{
		parent->child = nullptr;
	}
	node->left = minNode;
	node->right = minNode->right;
	minNode->right->left = node;
	minNode->right = node;
	node->parent = nullptr;
	node->mark = false;
}

#endif