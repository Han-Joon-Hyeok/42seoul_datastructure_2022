#include "graphlinkedlist.h"

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph	*graph;

	graph = createLinkedGraph(maxVertexCount);
	graph->graphType = GRAPH_DIRECTED;
	return (graph);
}