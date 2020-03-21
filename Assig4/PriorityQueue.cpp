#include "PriorityQueue.h"
#include <math.h>

void PriorityQueue::swap(int i, int j)
{
	if (i == j || i < 0 || i >= size || j < 0 || j >= size)
	{
		return; //at least one of the two indices is out of range
	}

	//swap the values
	Job temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
}

void PriorityQueue::heapify()
{


	int r = 0; //the current index of the moved element
	int leftChild = (2 * r) + 1; //index of the left child of the moved elememnt
	int rightChild = (2 * r) + 2; //index of the right child of the moved element

	while (leftChild < size) //r has children
	{
		if (leftChild == size - 1) //r has only 1 child 
		{
			//if the value of r is smaller than the value of the child, swap their values
			if (heap[r] < heap[leftChild])
			{
				swap(r, leftChild);
			}

			break; //we have reached a leaf node
		}
		else //r has 2 children 
		{
			//compare the values of r and its left and right child
			//if at least one child is larger than r, swap the value of r with the value of its larger child 
			if ((heap[r] < heap[leftChild]) && (heap[leftChild] >= heap[rightChild]))
			{
				//left child is larger, swap them and update the indices
				swap(r, leftChild);
				r = leftChild;
				leftChild = (2 * r) + 1;
				rightChild = (2 * r) + 2;
			}
			else if ((heap[r] < heap[rightChild]) && (heap[rightChild] > heap[leftChild]))
			{

				swap(r, rightChild);
				r = rightChild;
				leftChild = (2 * r) + 1;
				rightChild = (2 * r) + 2;
			}
			else break; //r is larger than both children, it is now in its proper place
		}
	}
}

PriorityQueue::PriorityQueue(Job* values, int size)
{
	buildHeap(values, size);
}

PriorityQueue::PriorityQueue(const PriorityQueue& pq)
{
	size = pq.size; //copy the size

	//copy the heap
	if (pq.heap != NULL)
	{
		heap = new Job[size]; //allocate space for the new heap

		//copy the values
		for (int i = 0; i < size; i++)
		{
			heap[i] = pq.heap[i];
		}
	}
	else
	{
		heap = NULL;
	}
}

const PriorityQueue& PriorityQueue::operator=(const PriorityQueue& pq)
{
	if (&pq == this)
	{
		return *this; //assignment to itself, we are done
	}

	if (heap != NULL)
	{
		delete[] heap; //delete previous data
	}

	size = pq.size; //copy the size

	//copy the heap
	if (pq.heap != NULL)
	{
		heap = new Job[size]; //allocate space for the new heap

		//copy the values
		for (int i = 0; i < size; i++)
		{
			heap[i] = pq.heap[i];
		}
	}
	else
	{
		heap = NULL;
	}

	return *this;
}

PriorityQueue::~PriorityQueue()
{
	delete[] heap; //free the data
}

void PriorityQueue::buildHeap(Job* values, int size)
{
	//inserts all the elements into the heap one by one
	for (int i = 0; i < size; i++)
	{
		insert(values[i]);
	}
}

void PriorityQueue::insert(Job value)
{
	size++; //new size

	Job* newHeap = new Job[size]; //allocate array of new size

	newHeap[0] = value; //put the value into the first element

	//copy the original values into the rest of the array
	for (int i = 1; i < size; i++)
	{
		newHeap[i] = heap[i - 1];
	}

	if (heap != NULL) delete[] heap; //erase the original array
	heap = newHeap; //and replace it with the new one

	heapify(); //push the new first element down the heap until the heap property is satisfied
}

Job PriorityQueue::extractMax()
{
	if (heap != NULL) //heap is non empty
	{
		if (size == 1) //heap has only one element
		{
			Job value = heap[0]; //take its value
			delete[] heap; //erase the heap, because it's now empty
			heap = NULL;
			size--; //decrement the size

			return value; //return the value
		}

		//heap has more than one element

		Job value = heap[0]; //take the value of the first element

		swap(0, size - 1); //swap the first and last elements

		Job* newHeap = new Job[size - 1]; //allocate space for new heap that is one element shorter

		//copy all the original elements except the last one (our extracted value) into the new heap
		for (int i = 0; i < size - 1; i++)
		{
			newHeap[i] = heap[i];
		}

		delete[] heap; //delete the original heap
		heap = newHeap; //and replace it with the new heap
		size--; //decrement the size

		heapify(); //push the root element (the former last) down the heap until the heap property is satisfied

		return value; //return the extracted value
	}
	else //heap is empty
	{
		return Job();
	}
}

void PriorityQueue::print() const
{
	for (int j = 0; j < size; j++)
	{
		std::cout << heap[j].priority << " " << heap[j].duration;
		std::cout << "\n";
	}
}

