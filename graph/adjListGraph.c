#:include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 100

typedef int vertex;
typedef int weightType;
typedef int dataType;

/** 
 * 定义邻接表中每个结点的结构
 */
typedef struct adjListNode {
	vertex adjV;  // 下标
	weightType weight;  // 权重
	struct adjListNode *next;  // 指向下一个结点的指针
} * ptrToAdjListNode;

/**
 * 定义邻接表：指针数组，每个指针指向链表的头结点
 */
typedef struct firstNode {
	ptrToAdjListNode firstEdge;  // 指针
	dataType data;  // 结点本身包含的信息
} adjList[MAX_VERTEX_NUM];

/**
 * 定义图结构:包含顶点数、边数、以及邻接表
 */
typedef struct graphNode {
	int nv;  // 顶点数
	int ne;  // 边数
	adjList graph;  // 邻接表
} * ptrToGraphNode;

typedef ptrToGraphNode adjListGraph;

ptrToGraphNode createAdjListGraph(int vertexNum);

int main()
{
	vertex vertexNum;
	scanf("%d", &vertexNum);

	ptrToGraphNode adjListGraph = createAdjListGraph(vertexNum);
	printf("%d", adjListGraph->nv);
}

/**
 * 初始化一个有vertexNum个顶点的无边图
 */
ptrToGraphNode createAdjListGraph(int vertexNum)
{
	ptrToGraphNode adjListGraph = (ptrToGraphNode)malloc(sizeof(ptrToGraphNode));
	adjListGraph->nv = vertexNum;
	adjListGraph->ne = 0;

	for(vertex v = 0; v < vertexNum; v++) {
		adjListGraph->graph[v].firstEdge = NULL;
	}

	return adjListGraph;
}

void insertEdge(ptrToAdjListGraph graph, edge e)
{
		
}
