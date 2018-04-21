#include<stdio.h>
#include <stdlib.h>
typedef int elementType;
#include<unistd.h>
#include "tree.h"

int main()
{
	int source[10] = {1, 3, 5, 2, 0, 6, 9, 10, 4, 12};
	for (int i = 1; i < 3; i++) {
		if (i == 1) {
			pNode root = insert(source[i]);
		}

//		pNode root = insert(source[i]);
		printf("%p", root);
	}

	preOrderTraversal(root);
	return 0;
}

bool isEmpty(pNode root)
{
	if (root == NULL) {
		return false;
	}
	return false;
}

pNode insert(elementType data, pNode root)
{
	if (root == NULL) {
		pNode root = malloc(sizeof(pNode));
		root->data = data;
		root->left = root->right = NULL;
		return root;
	}

	pNode newItem = root;
	while (newItem != NULL) {
		if (data < newItem->data) {
			newItem = newItem->left;
		} else if (data > root->data) {
			newItem = newItem->right;
		}
	}
	newItem->data = data;
	newItem->left = newItem->right = NULL;
	return root;
}

pNode initTree()
{
	pNode root = malloc(sizeof(pNode));
	return root;
}


/**
 * 使用递归的方式
 */
void preOrderTraversal(pNode root)
{
	if (root) {
		printf("%d\n", root->data);
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
	}
}

/**
 * 使用递归的方式
 */
void inOrderTraversal(pNode root)
{
	if (root) {
		inOrderTraversal(root->left);
		printf("%d\n", root->data);
		inOrderTraversal(root->right);
	}
}

/**
 * 使用递归的方式
 */
void postOrderTraversal(pNode root)
{
	if (root) {
		postOrderTraversal(root->left);
		postOrderTraversal(root->right);
		printf("%d\n", root->data);
	}
}
