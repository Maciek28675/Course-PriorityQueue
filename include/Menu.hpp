#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>

#include "Queue.hpp"
#include "HeapPriorityQueue.hpp"
#include "fibonacciheapnode.hpp"

class Menu
{
protected:
	int userChoice = 0;
	int index = 0;
public:
	virtual void display() const = 0;
	virtual void run() = 0;
};

class DataTypeMenu : public Menu
{
public:
	void display() const override;
	void run() override;
};

template <typename T>
class QueueMenu : public Menu
{
protected:
	Queue<T>* pq = nullptr;
	const int exitOption = 5;

public:
	void display() const override;
	void run() override;

	template <typename T> friend class OperationMenu;
};

template <typename T>
class OperationMenu : public Menu
{
protected:
	Queue<T>* pq = nullptr;
	const int exitOption = 10;

public:
	void display() const override;
	void run() override;

	template <typename T> friend class QueueMenu;
};


//////// DataTypeMenu ////////

void DataTypeMenu::display() const
{
	std::cout << "----------\n";
	std::cout << "1. Int\n";
	std::cout << "2. Float\n";
	std::cout << "3. Char\n";
	std::cout << "4. String\n";
	std::cout << "----------\n";

	std::cout << "Choose a data type to use with priority queue: ";
}

void DataTypeMenu::run()
{
	while (true)
	{
		this->display();
		std::cin >> userChoice;

		std::cout << "Press enter to continue";

		// Wait for enter
		std::cin.get();
		std::cin.get();

		system("cls");

		switch (userChoice)
		{
			case 1:
			{
				QueueMenu<int> m1;
				m1.run();
				break;
			}
			case 2:
			{
				QueueMenu<float> m2;
				m2.run();
				break;
			}
			case 3:
			{
				QueueMenu<char> m3;
				m3.run()
				break;
			}
			case 4:
			{
				QueueMenu<std::string> m4;
				m4.run()
				break;
			}
			default:
			{
				std::cerr << "error: chosen option does not exist\n";
				exit(1);
			}
		}
	}

}

//////// QueueMenu ////////

template <typename T>
void QueueMenu<T>::display() const
{
	// In progress
}

template <typename T>
void QueueMenu<T>::run()
{
	// In progress
}

//////// OperationMenu ////////

template <typename T>
void OperationMenu<T>::display() const
{
	// In progress
}

template <typename T>
void OperationMenu<T>::run()
{
	// In progress
}

#endif