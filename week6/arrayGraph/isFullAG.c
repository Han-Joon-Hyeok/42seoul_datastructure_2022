#include "arraygraph.h"

int isFullAG(ArrayGraph* pGraph)
{
    if (pGraph == NULL)
        return (ERROR);
	if (pGraph->currentVertexCount == pGraph->maxVertexCount)
        return (TRUE);
    return (FALSE);
}