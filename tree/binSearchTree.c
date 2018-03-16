#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<stdbool.h>

typedef int elementType;

typedef struct treeNode
{
	elementType element;
	struct treeNode *left;
	struct treeNode *right;
} *position, *searchTree;

bool isEmpty(searchTree t);
searchTree makeEmpty(searchTree t);
position find(elementType x, searchTree t);
position findMin(searchTree t);
position findmax(searchTree t);
searchTree insert(elementType x, searchTree t);
searchTree delete(elementType x, searchTree t);
elementType retrieve(position p);
void preOrderBST(searchTree t);
void inOrderBST(searchTree t);
int main()
{
	searchTree t = NULL;
	int data[10] = {1, 3, 4, 2, 0, 8, 13, -2, -5, 18};
	for (int i = 0; i < 10; i++) {
		t = insert(data[i], t);
	}
	//position node = find(8, t);
	//printf("%p", node);
	inOrderBST(t);
	delete(8, t);
	inOrderBST(t);
}

searchTree makeEmpty(searchTree t)
{
	if (t != NULL) {
		makeEmpty(t->left);
		makeEmpty(t->right);
		free(t);
	}
	return NULL;
}

position find(elementType x, searchTree t)
{
	while(t != NULL && t->element != x) {
		if (x < t->element) {
			t = t->left;
		} else if (x > t->element) {
			t = t->right;
		}
	}
	return t;
}

bool isEmpty(searchTree t)
{
	return t == NULL;
}

position findMin(searchTree t)
{
	if (t != NULL) {
		while (t->left != NULL) {
			t = t->left;
		}
	}
	return t;
}

position findMax(searchTree t)
{
	if (t != NULL) {
		while (t->right != NULL) {
			t = t->right;
		}
	}
	return t;
}

/**
 * 插入单个值
 */
searchTree insert(elementType x, searchTree t)
{
	if (t == NULL) {
		t = malloc(sizeof(struct treeNode));
		if (t == NULL) {
			exit(-1);
		}
		t->left = t->right = NULL;
		t->element = x;
	} else {
		if (x < t->element) {
			t->left = insert(x, t->left);
		} else if(x > t->element) {
			t->right = insert(x, t->right);
		} else {
		}
	}
	return t;
}

/**
 * 删除某个值
 */
searchTree delete(elementType x, searchTree t)
{
	if (t == NULL) {
		exit(-1);
	}
	position tmpCell;
	if (x < t->element) {
		t->left = delete(x, t->left);
	} else if (x > t->element) {
		t->right = delete(x, t->right);
	} else {
		// 替换为右子树的最小值，并递归删除该值
		if (t->left && t->right) {
			tmpCell = findMin(t->right);
			t->element = tmpCell->element;
			t->right = delete(t->element, t->right);
		} else {
			tmpCell = t;
			if (t->left == NULL) {
				t = t->right;
			} else if (t->right == NULL) {
				t = t->left;
			}
			free(tmpCell);
		}
	}
	return t;
}

/**
 * 先序输出
 */
void preOrderBST(searchTree t)
{
	if (isEmpty(t)) {
		printf("树为空");
		return;
	}
	printf("%d\n", t->element);
	preOrderBST(t->left);
	preOrderBST(t->right);
}

/**
 * 中序输出
 */
void inOrderBST(searchTree t)
{
	if (isEmpty(t)) {
		return;
	}
	inOrderBST(t->left);
	printf("%d\n", t->element);
	inOrderBST(t->right);
}
