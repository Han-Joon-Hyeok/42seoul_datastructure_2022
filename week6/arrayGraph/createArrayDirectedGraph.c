#include "arraygraph.h"

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph	*graph;

	graph = createArrayGraph(maxVertexCount);
	graph->graphType = GRAPH_DIRECTED;
	return (graph);
}