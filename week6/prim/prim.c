#include "../arrayGraph/arraygraph.h"

void	prim(ArrayGraph *pGraph)
{
    int         visit[pGraph->currentVertexCount];
	int			min;
	int			minIdx;
	int			currIdx;
    ArrayGraph  *mst;
    
    // create empty MST
    mst = createArrayGraph(pGraph->currentVertexCount);
    
    // initialize visit array 
    for (int i = 0; i < pGraph->currentVertexCount; i++)
        visit[i] = NOT_VISITED;
	currIdx = 0;
	visit[currIdx] = VISITED;

	// get shortest path
    while (mst->currentVertexCount < pGraph->currentVertexCount)
    {
		min = INFINITY;
		minIdx = -1;
		for (int i = 0; i < pGraph->currentVertexCount; i++)
		{
			if (visit[i] == NOT_VISITED)
				continue ;
			for (int j = 0; j < pGraph->currentVertexCount; j++)
			{
				if (pGraph->ppAdjEdge[i][j] < min && pGraph->ppAdjEdge[i][j] >= 1 && visit[j] == NOT_VISITED)
				{
					currIdx = i;
					minIdx = j;
					min = pGraph->ppAdjEdge[i][j];
				}
			}
		}
        if (visit[currIdx] == VISITED && visit[minIdx] == VISITED)
            continue ;
        visit[currIdx] = VISITED;
        visit[minIdx] = VISITED;
		if (mst->pVertex[currIdx] == NOT_USED)
			addVertexAG(mst, currIdx);
        if (mst->pVertex[minIdx] == NOT_USED)
            addVertexAG(mst, minIdx);
        addEdgewithWeightAG(mst, currIdx, minIdx, pGraph->ppAdjEdge[currIdx][minIdx]);
    }

    // display minimum shortest tree
    displayArrayGraph(mst);
}