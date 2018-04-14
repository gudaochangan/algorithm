#include <stdio.h>

typedef int elementType;

elementType* insertSort(elementType a[], int n);

int main()
{
	int a[] = {3, 16, 5, 7, 10};
	datatype * sort = insertSort(a, 5);
	for (int i = 0; i < 5; ++i)
	{
		printf("%d\n", a[i]);
	}
}

/*
 * 插入排序
 */
datatype* insertSort(datatype a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		datatype tmp = a[i];
		for (int j = i; j > 0 && a[j-1] > tmp; j--)
		{
			a[j] = a[j-1];
		}
		a[j] = tmp;
	}
	return a;
}