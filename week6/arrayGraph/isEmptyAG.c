#include "arraygraph.h"

int isEmptyAG(ArrayGraph* pGraph)
{
    if (pGraph == NULL)
        return (ERROR);
	if (pGraph->currentVertexCount == 0)
        return (TRUE);
    return (FALSE);
}