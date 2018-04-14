#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 100

typedef int weightType;
typedef int dataType;
typedef int vertex;  // 用顶点的下标表示顶点，为整形


typedef struct graphNode {
	int nv;  // 顶点数
	int ev;  // 边数
	weightType edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  // 边
	dataType data[MAX_VERTEX_NUM];  // 存放顶点的数据
} *ptrToGraphNode;

typedef ptrToGraphNode matrixGraph;

typedef struct edgeNode {
	vertex v1, v2;  // 两个顶点
	weightType weight;  // 权重
} * ptrToEdgeNode;

typedef ptrToEdgeNode edge;

matrixGraph createGraph(int vertexNum);
void insertEdge(matrixGraph graph, edge e);

int main()
{
	matrixGraph graph = createGraph(8);
	printf("%d", graph->nv);
	edge e1 = malloc(sizeof(edge));
	e1->v1 = 2;
	e1->v2 = 3;
	e1->weight = 2;
	insertEdge(graph, e1);
	printf("%d", graph->edge[e1->v1][e1->v2]);
}

matrixGraph createGraph(int vertexNum)
{
	vertex v, w;
	matrixGraph graph;
	
	graph = (matrixGraph)malloc(sizeof(struct graphNode));
	graph->nv = vertexNum;
	graph->ev = 0;

	for (v = 0; v < graph->nv; v++) {
		for (w = 0; w < graph->ev; w++) {
			graph->edge[v][w] = 0;
		}
	}
	return graph;
}

void insertEdge(matrixGraph graph, edge e)
{
	graph->edge[e->v1][e->v2] = e->weight;

	// 若是双向图，再插入一条边
	graph->edge[e->v2][e->v1] = e->weight;
}
