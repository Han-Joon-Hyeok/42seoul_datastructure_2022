#ifndef _GRAPH_LINKEDLIST_
#define _GRAPH_LINKEDLIST_

#include "./linkedList/linkedlist.h"

typedef struct LinkedGraphType
{
	int	maxVertexCount;
	int currentVertexCount;
	int graphType;
	int *pVertex;
	LinkedList **ppAdjEdge; // 안에 헤더노드들
} LinkedGraph;

LinkedGraph* createLinkedGraph(int maxVertexCount);
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount);
int isEmptyLG(LinkedGraph* pGraph);
int isFullLG(LinkedGraph* pGraph);			// 추가
int checkVertexValid(LinkedGraph* pGraph, int vertexID);
ListNode*	searchVertexID(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addVertexLG(LinkedGraph* pGraph, int vertexID);
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgeNodeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);
int addEdgeNodewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);
int removeVertexLG(LinkedGraph* pGraph, int vertexID);
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int removeEdgeNodeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
void deleteLinkedGraph(LinkedGraph* pGraph);
void displayLinkedGraph(LinkedGraph* pGraph);
void	linkedGraphDfs(LinkedGraph *pGraph);

#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED				1
#define NOT_USED			0

#define SUCCESS				1
#define FAIL				0

#define TRUE				1
#define FALSE				0
#define ERROR				-1

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2

#define VISITED			1
#define NOT_VISITED		0

#endif