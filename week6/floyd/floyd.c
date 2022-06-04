#include "../arrayGraph/arraygraph.h"
#include <stdio.h>

void    floyd(ArrayGraph *pGraph)
{
    int nodeCount;
    int path[pGraph->currentVertexCount][pGraph->currentVertexCount];

    if (pGraph == NULL)
        return ;
    printf("\n\n✅ Floyd algorithm \n\n");
    nodeCount = pGraph->currentVertexCount;
    for (int i = 0; i < nodeCount; i++)
    {
        for (int j = 0; j < nodeCount; j++)
        {
            if (i == j)         // 음수 사이클이 발생할 때, 어떻게 dfs 를 활용할 수 있는지?
                path[i][j] = 0;
            else if (pGraph->ppAdjEdge[i][j] == 0)
                path[i][j] = INFINITY;
            else
                path[i][j] = pGraph->ppAdjEdge[i][j];
        }
    }

    for (int k = 0; k < nodeCount; k++)
        for (int i = 0; i < nodeCount; i++)
            for (int j = 0; j < nodeCount; j++)
                if (path[i][j] > path[i][k] + path[k][j])
                    path[i][j] = path[i][k] + path[k][j];


    for (int i = 0; i < nodeCount; i++)
    {
        for (int j = 0; j < nodeCount; j++)
            printf("%d ", path[i][j]);
        printf("\n");
    }
}