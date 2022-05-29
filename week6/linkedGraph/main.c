#include <stdio.h>
#include "graphlinkedlist.h"

int main(void)
{
    LinkedGraph  *ugraph;
    LinkedGraph  *dgraph;

/*

    undirected

    [
        [0, 1, 0, 1],
        [1, 0, 1, 1],
        [0, 1, 0, 0],
        [1, 1, 0, 0],
    ]

*/

    ugraph = createLinkedGraph(4);

    displayLinkedGraph(ugraph);

    addVertexLG(ugraph, 0);
    addVertexLG(ugraph, 1);
    addVertexLG(ugraph, 2);
    addVertexLG(ugraph, 3);

    addEdgeLG(ugraph, 0, 1);
    addEdgeLG(ugraph, 0, 3);
    addEdgeLG(ugraph, 1, 2);
    addEdgeLG(ugraph, 1, 3);
    displayLinkedGraph(ugraph);

/*

    directed

    [
        [0, 1, 0, 0],
        [1, 0, 0, 1],
        [0, 0, 0, 0],
        [1, 0, 0, 0],
    ]

*/
    dgraph = createLinkedDirectedGraph(4);

    displayLinkedGraph(dgraph);

    addVertexLG(dgraph, 0);
    addVertexLG(dgraph, 1);
    addVertexLG(dgraph, 2);
    addVertexLG(dgraph, 3);

    addEdgeLG(dgraph, 0, 1);
    addEdgeLG(dgraph, 1, 0);
    addEdgeLG(dgraph, 1, 3);
    addEdgeLG(dgraph, 3, 1);

    displayLinkedGraph(dgraph);
    deleteLinkedGraph(ugraph);
    deleteLinkedGraph(dgraph);
    return (0);
}