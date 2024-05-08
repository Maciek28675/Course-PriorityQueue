# Implementation of a priority queue in C++
In this project we've implemented priority queue using regular MAX heap and Fibonacci heap.  
Each structure has it's own set of basic operations like modifyKey, exctractMax, insert, etc.  
We've measured time of execution of every operation to compare data structures performance and determine which one is best for every scenario. We've also verified whether time complexity of those operations matches the theory (and it does for almost all cases).  
  
The project follows basic OOP principles, which are encapsulation, polymorphism, inheritance and abstraction.  
  
## How to compile
The project uses cmake for compilation purposes.  
To compile it, follow this steps:

```cmd
mkdir build
cd build
cmake ..
cmake --build .
```

## How we measured performance  
To do that, we've filled a data structure with random generated data (ranging from 10 000 to 500 000). Then performed an operation (for ex. exctract-max) for a specified amonut of times and calculated the avarage time. We've then repeated the process for bigger data sets and created a chart.  
To measure time we've used chrono library

### Code snippet used to measure performance

```cpp
// measure time of operation
for (int i = 0; i < repetitions; i++)
{
	Timer timer;

	timer.start();
	pqCopy->insert(elementToInsert, priorityToInsert);
	timer.stop();

	duration = timer.getDuration();
	sum += duration;

	pqCopy = pq
}

averageTime = sum / repetitions;
```
## Example result of performance measurement

![measurement example 1](https://github.com/Maciek28675/PriorityQueue/blob/master/Images/fig1.bmp)

### Example chart

![chart 1](https://github.com/Maciek28675/PriorityQueue/blob/master/Images/fig4.bmp)

## Menu
The program features user friendly menu. The user can choose a data structure, it's data type and an operation to perform.  
Here is how it looks like:  

![menu example 1](https://github.com/Maciek28675/PriorityQueue/blob/master/Images/fig3.bmp)

![menu example 2](https://github.com/Maciek28675/PriorityQueue/blob/master/Images/fig2.bmp)
