#include <stdio.h>
#include <stdlib.h>

typedef int elementType;

elementType * quickSort(elementType a[], int l, int r);
int partition(elementType a[], int l, int r);
void exchange(elementType a[], int i, int j);

int main()
{
	int a[] = {2, 2, 2, 2, 2, 2, 2};
	int count = sizeof(a) / sizeof(elementType);
	elementType * sortA =  quickSort(a, 0, count - 1);
	for (int i = 0; i < count; ++i)
	{
		printf("%d\n", a[i]);
	}
}


elementType * quickSort(elementType a[], int l, int r)
{
	if (l < r) {
		int p = partition(a, l, r);
		printf("p %d\n", p);
		quickSort(a, l, p - 1);
		quickSort(a, p + 1, r);
	}
	return a;
}

/*
 * 数组划分的简单思路：取数组的最后一个元素作为临界值，从第二个元素开始向右查找，记录下一个需要插入的<=临界值的元素，最后交换临界元素和待插入的元素
 * 之前一直卡在想要从第一个元素开始扫描，或者前和后同时扫描：前者没有留出交换的元素，后者更增加了程序的复杂性
 * 随机取临界点情况：交换临界点和最后一个元素即可
 */
int partition(elementType a[], int l, int r)
{
	elementType x = a[r];
	int i = l;
	for (int j = l; j < r; ++j)
	{
		if (a[j] <= x) {
			exchange(a, i, j);
			i = i + 1;
		}
	}
	exchange(a, i, r);
	return i - 1;
}

void exchange(elementType a[], int i, int j)
{
	elementType tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}
