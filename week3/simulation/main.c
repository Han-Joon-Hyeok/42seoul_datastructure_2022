#include "functions.h"

int main(void)
{
    int i;
    int t = 0;
    int processTime;
    int serviceCount = 0;
    int totalWaitTime = 0;
    int amount = 0;
    LinkedQueue *pArrivalQueue;
    LinkedQueue *pWaitQueue;
    QueueNode   *currCustomer;

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

    // 업무 시작
    while (!isLinkedQueueEmpty(pArrivalQueue) || !isLinkedQueueEmpty(pWaitQueue))
    {
        processArrival(t, pArrivalQueue, pWaitQueue);
        currCustomer = peekLQ(pWaitQueue);
        
        if (currCustomer->data.status == arrival) // 현재 서비스 중인 고객이 없으면 새로운 고객 서비스 시작
        {
            currCustomer->data.status = start;
            currCustomer->data.startTime = t;
            currCustomer->data.endTime += processTime;
        }
        else if (currCustomer->data.status == end) // 현재 서비스 중인 고객이 모두 업무를 마치면 Wait 큐에서 삭제
        {
            dequeueLQ(pWaitQueue);
            processServiceNodeStart(t, pWaitQueue);
            currCustomer = peekLQ(pWaitQueue);
            currCustomer->data.endTime += t;
            currCustomer->data.startTime = t;
        }

        // 고객의 상태를 변경을 담당
        // 현재 상태를 end 로 변경
        if (currCustomer->data.startTime + currCustomer->data.processTime == t)
        {

        }
        // 현재 상태를 end 로 변경
        if (currCustomer->data.startTime + currCustomer->data.recent  == currCustomer->data.endTime)
        {
            currCustomer->data.status = end;
        }

        // 고객의 서비스 시작과 종료를 담당
            // processServiceNodeEnd(t, peekLQ(pWaitQueue), &serviceCount, &totalWaitTime);
        t += 1;
        currCustomer->data.recent++;
    }

    // for (nasabah *n = nasabahs; n; n=n->next) {
    //     servedByCS(n, cs1, cs2);
    // }

    // printf("%d\n", cs1->count);

    return (0);
}