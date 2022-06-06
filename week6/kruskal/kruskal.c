#include "../arrayGraph/arraygraph.h"
#include "../minHeap/heap.h"

void    kruskal(ArrayGraph *pGraph)
{
    int         edgeCount;
    int         visit[pGraph->currentVertexCount];
    const int   size = (pGraph->currentVertexCount * (pGraph->currentVertexCount - 1)) / 2;
    minHeap     *heap;
    minHeapNode element;
    minHeapNode *node;
    ArrayGraph  *mst;
    
    // create empty MST
    mst = createArrayGraph(pGraph->currentVertexCount);
    for (int i = 0; i < pGraph->currentVertexCount; i++)
        addVertexAG(mst, i);
    edgeCount = pGraph->currentVertexCount - 1;

    // create minimum heap
    heap = createminHeap(size);
    
    // initialize visit array 
    for (int i = 0; i < pGraph->currentVertexCount; i++)
        visit[i] = NOT_VISITED;

    // sort edges ascending order
    for (int i = 0; i < pGraph->currentVertexCount; i++)
    {
        for (int j = i + 1; j < pGraph->currentVertexCount; j++)
        {
            if (pGraph->ppAdjEdge[i][j] == 0)
                continue ;
            element.weight = pGraph->ppAdjEdge[i][j];
            element.fromVertexId = i;
            element.toVertexId = j;
            insertminHeap(heap, element);
        }
    }

    // get shortest path
    while (isHeapEmpty(heap) == FALSE && edgeCount > 0)
    {
        node = deleteminHeap(heap);
        if (visit[node->fromVertexId] == VISITED && visit[node->toVertexId] == VISITED)
            continue ;
        visit[node->fromVertexId] = VISITED;
        visit[node->toVertexId] = VISITED;
        addEdgewithWeightAG(mst, node->fromVertexId, node->toVertexId, node->weight);
        edgeCount -= 1;
    }

    // display minimum shortest tree
    displayArrayGraph(mst);

    // delete minimum heap
    deleteminHeap(heap);
}