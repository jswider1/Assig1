#pragma once

#include "Job.h"

#include <iostream>

//class representing the priority queue, using max heap
class PriorityQueue
{
private:

	int size; //the current number of elements in the queue/heap

	//max heap as an array, this is sorted in such a way that:
	//the left child of element heap[i] is the element heap[2*i+1]
	//the right child of element heap[i] is the element heap[2*i+2]
	//the parent of element heap[i] is the element heap[floor((i-1)/2)]
	Job* heap;

	//swaps the values of the ith and jth elements of the heap array
	//if any of the indices is out of range, nothing happens
	void swap(int i, int j);

	//pushes the root element of the heap down the heap until the heap property is satisfied
	void heapify();

public:

	//default constructor initializes an empty heap
	PriorityQueue() : heap(NULL), size(0) {}

	//initializes the heap to the given values and sorts them to make a valid max heap
	//values: an array of values
	//size: the size of the values array
	PriorityQueue(Job* values, int size);

	//copy constructor performs a deep copy of the heap
	PriorityQueue(const PriorityQueue& pq);

	//overloaded assignment operator performs a deep copy of the heap
	const PriorityQueue& operator=(const PriorityQueue& pq);

	//destructor deallocates the heap
	~PriorityQueue();

	//initializes the heap to the given values and sorts them to make a valid max heap, any previous values are erased
	//values: an array of values
	//size: the size of the values array
	void buildHeap(Job* values, int size);

	//inserts the given value into the heap and rearranges the heap so it remains a valid max heap
	void insert(Job value);

	//removes the root element from the heap and returns its value
	Job extractMax();

	void print() const;

	//returns the number of elements that are currently in the heap
	int getSize() const { return size; }
};


