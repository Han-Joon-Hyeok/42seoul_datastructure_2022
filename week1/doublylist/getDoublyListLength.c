#include "doublylist.h"

int	getDoublyListLength(DoublyList *pList)
{
	if (!pList)
		return (FALSE);
	return (pList->currentElementCount);
}
