#include "functions.h"

int main(void)
{
    int i;
    int t;
    int processTime;
    int amount = 0;
    LinkedQueue *pArrivalQueue;
    LinkedQueue *pWaitQueue;

    pArrivalQueue = malloc(sizeof(LinkedQueue));
    pWaitQueue = malloc(sizeof(LinkedQueue));

    printf("Input the queue length : ");
    scanf("%d", &amount);

    // 고객 정보 초기화(도착 시간, 서비스 시간)
    for(i = 0; i < amount * 2; i += 2)
    {
        processTime = getRandomProcessTime();
        printf("i: %d, processTime: %d\n", i, processTime);
        insertCustomer(i, processTime, pArrivalQueue);
    }

    // Start processing

    // while (!isLinkedQueueEmpty(pWaitQueue))
    // {

    //     t += 1;
    // }

    // for (nasabah *n = nasabahs; n; n=n->next) {
    //     servedByCS(n, cs1, cs2);
    // }

    // printf("%d\n", cs1->count);

    return (0);
}