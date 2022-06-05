#include <stdio.h>
#include "arraygraph.h"

int main(void)
{
    ArrayGraph  *ugraph;
    ArrayGraph  *dgraph;

/*

    undirected

    [
        [0, 1, 0, 1],
        [1, 0, 1, 1],
        [0, 1, 0, 0],
        [1, 1, 0, 0],
    ]

*/

    ugraph = createArrayGraph(5);

    // displayArrayGraph(ugraph);

    addVertexAG(ugraph, 0);
    addVertexAG(ugraph, 1);
    addVertexAG(ugraph, 2);
    addVertexAG(ugraph, 3);
    addVertexAG(ugraph, 4);

    // addEdgeAG(ugraph, 0, 1);
    // addEdgeAG(ugraph, 0, 3);
    // addEdgeAG(ugraph, 1, 2);
    // addEdgeAG(ugraph, 1, 3);
    addEdgewithWeightAG(ugraph, 0, 1, 2);
    addEdgewithWeightAG(ugraph, 1, 2, 3);
    addEdgewithWeightAG(ugraph, 1, 4, 1);
    addEdgewithWeightAG(ugraph, 2, 3, 5);
    addEdgewithWeightAG(ugraph, 3, 4, 4);

    displayArrayGraph(ugraph);

    // arrayGraphDfs(ugraph);
    // arrayGraphBfs(ugraph);
    
    /*
        ugraph witdh 
        {
            {0, 2, 0, 0, 0},
            {2, 0, 3, 0, 1},
            {0, 3, 0, 5, 0},
            {0, 0, 5, 0, 4},
            {0, 1, 0, 4, 0}
        }
        플로이드 알고리즘 최단 경로
        [
            [0, 2, 5, 7, 3],
            [2, 0, 3, 5, 1],
            [5, 3, 0, 5, 4],
            [7, 5, 5, 0, 4],
            [3, 1, 4, 4, 0]
        ]

    */

    // floyd(ugraph);

    /*
        다익스트라 알고리즘 최단 경로 (0번 노드 기준)
        dist = [0, 2, 5, 7, 3]
    */

    // dijkstra(ugraph);

    /* 
        크루스칼 알고리즘 최소 신장 트리
        {
            {0, 2, 0, 0, 0},
            {2, 0, 3, 0, 1},
            {0, 3, 0, 0, 0},
            {0, 0, 0, 0, 4},
            {0, 1, 0, 4, 0},
        }
    */
    printf("\n\n✅ kruskal \n\n");
    kruskal(ugraph);

/*

    directed

    [
        [0, 1, 0, 0],
        [1, 0, 0, 1],
        [0, 0, 0, 0],
        [1, 0, 1, 0],
    ]

*/
    // dgraph = createArrayDirectedGraph(4);

    // displayArrayGraph(dgraph);

    // addVertexAG(dgraph, 0);
    // addVertexAG(dgraph, 1);
    // addVertexAG(dgraph, 2);
    // addVertexAG(dgraph, 3);

    // addEdgeAG(dgraph, 0, 1);
    // addEdgeAG(dgraph, 1, 0);
    // addEdgeAG(dgraph, 1, 3);
    // addEdgeAG(dgraph, 3, 1);
    // addEdgeAG(dgraph, 3, 2);
    // displayArrayGraph(dgraph);
    // arrayGraphDfs(dgraph);
    // arrayGraphBfs(dgraph);
    // deleteArrayGraph(ugraph);
    // deleteArrayGraph(dgraph);
    return (0);
}