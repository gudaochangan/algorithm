#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int position;
typedef int elementType;

typedef struct sNode *stack;

struct sNode {
	position top;
	elementType *data; /*存储元素的数组*/
	int maxSize;
};

stack createStack(int maxSize);

bool push(stack s, elementType data);

elementType pop(stack s);

bool isFull(stack s);

bool isEmpty(stack s);

int main(int argc, char const *argv[])
{
	stack s = createStack(10);
	push(s, 5);
	push(s, 4);
	push(s, 4);
	printf("%d\n", s->top);
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
}

stack createStack(int maxSize)
{
	stack s = (stack)malloc(sizeof(struct sNode));
	s->data = (elementType *)malloc(sizeof(elementType) * maxSize);
	s->top = -1;
	s->maxSize = maxSize;
	return s;
}

bool push(stack s, elementType data)
{
	if (isFull(s)) {
		return false;
	}
	s->data[++s->top] = data;
	return true;
}

elementType pop(stack s)
{
	if (isEmpty(s)) {
		return false;
	}
	return s->data[s->top--];
}

bool isFull(stack s)
{
	if (s->top == s->maxSize - 1) {
		return true;
	}
	return false;
}

bool isEmpty(stack s) {
	if (s->top == -1) {
		return true;
	}
	return false;
}