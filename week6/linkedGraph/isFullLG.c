#include "graphlinkedlist.h"

int isFullLG(LinkedGraph* pGraph)
{
    if (pGraph == NULL)
        return (ERROR);
	if (pGraph->currentVertexCount == pGraph->maxVertexCount)
        return (TRUE);
    return (FALSE);
}