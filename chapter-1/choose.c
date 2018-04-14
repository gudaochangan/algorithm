/*
   给定n个数字，找出第k个大的数字
*/

#include <stdio.h>

int find(int arr[], int k);

int * bubbleSort(int arr[], int num);
int main(void)
{
	int arr[10] = {1, 3, 2, 111, 34, 43, 22, 56, 88, 104};
	printf("%d\n", find(arr, 3));
}

int find(int arr[], int k)
{
	int *sortArr = bubbleSort(arr, 10);
	return sortArr[k];
}

int * bubbleSort(int arr[], int num)
{
	for (int i = 0; i < num; ++i)
	{
		for (int j = i + 1; j < num; ++j)
		{
			if (arr[j] < arr[i]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return arr;
}