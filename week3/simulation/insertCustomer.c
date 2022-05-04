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
    enqueueLQ(pQueue, *customer);
}