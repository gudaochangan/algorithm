#include <stdio.h>
#include <stdlib.h>

typedef int elementType;

typedef struct _resData * ptrResData;

struct _resData{
	int left;
	int right;
	int sum;
};

ptrResData findMaximumSubarray(elementType a[], int low, int high);

ptrResData findMaxCrossingSubarray(elementType a[], int low, int mid, int high);

/**
 * 暴力破解最大子数组问题
 */
ptrResData bruteForce(elementType a[], int low, int high);

int main(int argc, char const *argv[])
{
    int a[] = {1, 3, -5, 2, 0, 2, -2, -4, 0, 1, 7, 8, -4, 2};

	// int a[] = {-1, -2, 3, 4, 0, -3, 0, 7, 10, 2, -8, 3, 6};
	ptrResData res = findMaximumSubarray(a, 0, (sizeof(a) / sizeof(elementType)) - 1);
	// ptrResData res = bruteForce(a, 0, (sizeof(a)/sizeof(elementType) - 1));
	printf("%d\n", res->left);
	printf("%d\n", res->right);
	printf("%d\n", res->sum);
	return 0;
}

/**
 * 使用分支法解决最大子数组问题
 */
ptrResData findMaximumSubarray(elementType a[], int low, int high)
{
	ptrResData res = (ptrResData)malloc(sizeof(struct _resData));
	if (high == low) {	// base case
		res->left = low;
		res->right = high;
		res->sum = a[low] ? a[low] : 0;
		return res;	
	} else {
		int mid = (low + high) / 2;
		ptrResData left  = findMaximumSubarray(a, low, mid);
		ptrResData right = findMaximumSubarray(a, mid + 1, high);
		ptrResData cross = findMaxCrossingSubarray(a, low, mid, high);

		if (left->sum >= right->sum && left->sum >= cross->sum) {
			return left;
		} else if (right->sum >= left->sum && right->sum >= cross->sum) {
			return right;
		} else {
			return cross;
		}
	}
}

ptrResData findMaxCrossingSubarray(elementType a[], int low, int mid, int high)
{
	int sum = 0, leftSum = 0, rightSum = 0;
	int maxLeft, maxRight;
	ptrResData res = (ptrResData)malloc(sizeof(struct _resData));

	for (int i = mid; i >= low; --i)
	{
		sum += a[i];
		if (sum > leftSum) {
			leftSum = sum;
			maxLeft = i;
		}
	}

	sum = 0;

	for (int j = mid + 1; j <= high; ++j)
	{
		sum += a[j];
		if (sum > rightSum) {
			rightSum = sum;
			maxRight = j;
		}
	}

	res->left = maxLeft;
	res->right = maxRight;
	res->sum = leftSum + rightSum;
	return res;
}

ptrResData bruteForce(elementType a[], int low, int high)
{
	int maxSum = 0, left = 0, right = 0;

	ptrResData res = (ptrResData)malloc(sizeof(struct _resData));

	for (int i = low; i <= high; ++i)
	{
		int nowSum = 0, nowMaxSum = 0;
		left = right = i;
		for (int j = i + 1; j <= high; ++j)
		{
			nowSum += a[j];
			if (nowSum > nowMaxSum) {
				right = j;
				nowMaxSum = nowSum;
			}
		}
		if (nowMaxSum > maxSum) {
			maxSum = nowMaxSum;
			res->left = left;
			res->right = right;
			res->sum = maxSum;
		}
	}

	return res;
}
