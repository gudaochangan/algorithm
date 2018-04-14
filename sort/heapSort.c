#include <stdio.h>
#include <stdlib.h>

typedef int elementType;

typedef struct heap *ptrHeap;

struct heap
{
	int heapSize;
	elementType *data;
};

int parent(int i);

int left(int i);

int right(int i);

void exchange(elementType a[], int i, int j);

ptrHeap buildMaxHeap(elementType a[], const int count);

ptrHeap maxHeapIFY(ptrHeap maxHeap , int i);

elementType * heapSort(elementType a[], const int count);

int main()
{
	int a[] = {5, 3, 17, 10, 84, 19, 6, 22, 9, 33, 22, 3, 23};

	int count = sizeof(a) / sizeof(elementType);

	elementType * sortA = heapSort(a, count);

	for (int i = 0; i < count; ++i)
	{
		printf("%d\n", sortA[i]);
	}

}

int parent(int i)
{
	return (i - 1) / 2;
}

int left(int i)
{
	return (i<<1) + 1;
}

int right(int i)
{
	return (i<<1) + 2;
}

elementType* heapSort(elementType a[], const int count)
{
	ptrHeap maxHeap = buildMaxHeap(a, count);
	for (int i = count - 1; i >=  1; i--)
	{
		exchange(maxHeap->data, i, 0);
		maxHeap->heapSize--;
		maxHeapIFY(maxHeap, 0);
	}

	return maxHeap->data;
}

/**
 * 建立最大堆 
 */
ptrHeap buildMaxHeap(elementType a[], const int count)
{
	ptrHeap maxHeap = (ptrHeap)malloc(sizeof(struct heap));
	maxHeap->heapSize = count;
	maxHeap->data = a;
	
	for (int i = (count - 2)>>1; i >= 0; --i)
	{
		maxHeapIFY(maxHeap, i);
	}

	return maxHeap;
}

/**
 * 维护最大堆的性质
 */
ptrHeap maxHeapIFY(ptrHeap maxHeap, int i)
{
	int l = left(i);
	int r = right(i);
	int largest = i;

	// find max value of i, l, r
	if (l < maxHeap->heapSize && maxHeap->data[l] > maxHeap->data[i]) {
		largest = l;
	} 
	if (r < maxHeap->heapSize && maxHeap->data[r] > maxHeap->data[largest]) {
		largest = r;
	}

	if (largest != i) {
		// printf("%d %d \n",  maxHeap->data[i], maxHeap->data[largest]);
		exchange(maxHeap->data, i, largest);
		return maxHeapIFY(maxHeap, largest);
	}
	return maxHeap;
}

void exchange(elementType a[], int i, int j)
{
	elementType tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}