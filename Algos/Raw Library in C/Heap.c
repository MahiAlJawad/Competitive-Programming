/***
Min heap implementation with C
heap[] array contains the complete binary tree, where for each node
all of it's child nodes are greater than it. heap[0] contains the
smallest element of the tree.
 ***/
#include <stdio.h>

#define MAX_SIZE 100 //maximum number of nodes should be given support

int heap[MAX_SIZE];
int heapSize = 0;

void heapInit()//should be called at the start of building heap
{
	heapSize = 0;
}

int heapPush(int value)
{
	if (heapSize + 1 > MAX_SIZE)
	{
		printf("queue is full!");
		return 0;
	}

	heap[heapSize] = value;//Putting the element at the last position
    heapSize++;
	int current = heapSize-1;// last element i.e. new added element
	while (current > 0 && heap[current] < heap[(current - 1) / 2])
	{
		int temp = heap[(current - 1) / 2];
		heap[(current - 1) / 2] = heap[current];
		heap[current] = temp;
		current = (current - 1) / 2;
	}
	return 1;
}

int heapPop(int *value)//popped value will be stored to the *value integer pointer
{
	if (heapSize <= 0)//Underflow
	{
		return -1;
	}

	*value = heap[0];//Minimum element is saved
	heapSize = heapSize - 1;

	heap[0] = heap[heapSize];//Array's last element is putted at the root, where the smallest element should be

	int current = 0;
	while (current * 2 + 1 < heapSize)//Till the current node is not a leaf node
	{
		int child;
		if (current * 2 + 2 == heapSize)//If the current node has only first child.(that child would be the last element of heap array)
		{
			child = current * 2 + 1;
		}
		else
		{
			child = heap[current * 2 + 1] < heap[current * 2 + 2] ? current * 2 + 1 : current * 2 + 2;
		}

		if (heap[current] < heap[child])
		{
			break;
		}

		int temp = heap[current];
		heap[current] = heap[child];
		heap[child] = temp;

		current = child;
	}
	return 1;
}

int main()
{
	heapInit();
	for(int i= 10; i>=0; i--)
    {
        heapPush(i);
    }
    int popped;
    while(heapPop(&popped)!= -1)
    {
        printf("Popped: %d\n", popped);
    }
	return 0;
}
