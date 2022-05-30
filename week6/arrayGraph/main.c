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

    // ugraph = createArrayGraph(4);

    // displayArrayGraph(ugraph);

    // addVertexAG(ugraph, 0);
    // addVertexAG(ugraph, 1);
    // addVertexAG(ugraph, 2);
    // addVertexAG(ugraph, 3);

    // addEdgeAG(ugraph, 0, 1);
    // addEdgeAG(ugraph, 0, 3);
    // addEdgeAG(ugraph, 1, 2);
    // addEdgeAG(ugraph, 1, 3);
    // displayArrayGraph(ugraph);
    // arrayGraphDfs(ugraph);
    // arrayGraphBfs(ugraph);

/*

    directed

    [
        [0, 1, 0, 0],
        [1, 0, 0, 1],
        [0, 0, 0, 0],
        [1, 0, 1, 0],
    ]

*/
    dgraph = createArrayDirectedGraph(4);

    // displayArrayGraph(dgraph);

    addVertexAG(dgraph, 0);
    addVertexAG(dgraph, 1);
    addVertexAG(dgraph, 2);
    addVertexAG(dgraph, 3);

    addEdgeAG(dgraph, 0, 1);
    addEdgeAG(dgraph, 1, 0);
    addEdgeAG(dgraph, 1, 3);
    addEdgeAG(dgraph, 3, 1);
    addEdgeAG(dgraph, 3, 2);
    displayArrayGraph(dgraph);
    // arrayGraphDfs(dgraph);
    arrayGraphBfs(dgraph);
    // deleteArrayGraph(ugraph);
    // deleteArrayGraph(dgraph);
    return (0);
}