#include <stdbool.h>

typedef struct node
{
	elementType data;
	struct node * left;  // 指向左分支的指针
	struct node * right;  // 指向右分支的指针
} * pNode;

typedef struct binTree
{
	pNode root;
	int size_t;
} * bst;

/**
 * 判定一个二叉搜索树是否为空
 */
bool isEmpty(pNode root);

/**
 * 	创建一个二叉搜索树
 */
bool createBinTree();

pNode initTree();

pNode insert(elementType data, pNode root);
/**
 * 先序遍历
 */
void preOrderTraversal(pNode root);

/**
 * 中序遍历
 */
void inOrderTraversal(pNode root);

/**
 * 后序遍历
 */
void postOrderTraversal(pNode root);

/**
 * 层次遍历
 */
void levOrderTraversal(pNode root);
