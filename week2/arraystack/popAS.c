#include <stdio.h>
#include "arraystack.h"

char   popAS(ArrayStack* pStack)
{
    if (!pStack || pStack->currentElementCount == 0)
        return (0);
    pStack->currentElementCount -= 1;
    return (pStack->array[pStack->currentElementCount].data);
}