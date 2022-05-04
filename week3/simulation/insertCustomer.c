#include "functions.h"

void insertCustomer(int arrivalTime, int processTime, LinkedQueue *pQueue)
{
    QueueNode *customer;
    
    if (!pQueue || arrivalTime < 0 || processTime <= 0)
        error(pQueue);
    customer = malloc(sizeof(SimCustomer));
    if (!customer)
        error(pQueue);
    customer->data.status = arrival;
    customer->data.arrivalTime = arrivalTime;
    customer->data.processTime = processTime;
    customer->data.endTime = processTime;
    customer->data.startTime = 0;
    customer->data.recent = 0;
    enqueueLQ(pQueue, *customer);
}