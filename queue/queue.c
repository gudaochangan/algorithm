#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int elementType;

typedef struct qNode *queue;

struct qNode {
	elementType *data;
	int head;  // 指向队头元素的下标
	int tail;  // 指向队尾下一个要插入的元素下标
	int maxSize;
};

queue createQueue(int maxSize);

bool enqueue(queue q, elementType data);

elementType dequeue(queue q);

bool isEmpty(queue q);

bool isFull(queue q);

int main(int argc, char const *argv[])
{
	// test
	int maxSize = 2;
	queue q = createQueue(maxSize);
	enqueue(q, 4);
	dequeue(q);
	enqueue(q, 5);
	enqueue(q, 7);
	printf("%d\n", dequeue(q));
	return 0;
}

queue createQueue(int maxSize)
{
	queue q = (queue)malloc(sizeof(struct qNode));

	q->data = (elementType*)malloc(sizeof(elementType) * maxSize);
	q->head = 0;
	q->tail = 0;
	q->maxSize = maxSize;
	return q;
}

bool enqueue(queue q, elementType data)
{
	if (isFull(q)) {
		return false;
	}
	q->data[q->tail] = data;

	if (q->tail == q->maxSize) {
		q->tail = 0;
	} else {
		++q->tail;
	}
	return true;
}

elementType dequeue(queue q)
{
	if (isEmpty(q)) {
		return false;
	}
	elementType x = q->data[q->head];

	if (q->head == q->maxSize - 1) {
		q->head = 0;
	} else {
		++q->head;
	}
	return x;
}

bool isEmpty(queue q)
{
	if (q->head == q->tail) {
		return true;
	}
	return false;
}

/**
 * 为了区分判断队列空和队列满，条件head==tail判定队列空，那么队列至少要留出一个元素的空间。
 */
bool isFull(queue q)
{
	if (q->tail - q->head == q->maxSize -1 || q->head == q->tail + 1) {
		return true;
	} else {
		return false;
	}
}