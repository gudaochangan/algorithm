#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned left;
    unsigned right;
    int sum;
} max_subarray;

max_subarray find_maximum_subarray(int a[], unsigned low, unsigned high);

int main(int argc, char const *argv[])
{
    int a[] = {1, 3, -5, 2, 0, 2, -2, -4, 0, 1, 7, 8, -4, 2};
    max_subarray subarray = find_maximum_subarray(a, 0, (sizeof(a) / sizeof(unsigned))  - 1);
    
    printf("%d %d %d\n", subarray.left, subarray.right, subarray.sum);
    return 0;
}

max_subarray find_maximum_subarray(int A[], unsigned low, unsigned high) {
    max_subarray suffixes[high - low];

    suffixes[0].left = low; 
    suffixes[0].right = low + 1;
    suffixes[0].sum = A[low];

    for (int i = low + 1; i < high; i++) {
        if (suffixes[i - 1].sum < 0) {
            suffixes[i].left = i;
            suffixes[i].right = i + 1;
            suffixes[i].sum = A[i];
        } else {
            max_subarray *previous = &suffixes[i - 1];
            suffixes[i].left = previous->left;
            suffixes[i].right = i + 1;
            suffixes[i].sum = previous->sum + A[i];
        }
    }

    max_subarray *max = &suffixes[0]; 

    for (int i = low + 1; i < high; i++) {
        if (max->sum < suffixes[i].sum) {
            max = &suffixes[i];
        }
    }

    return *max;
}