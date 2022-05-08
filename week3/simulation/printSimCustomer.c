#include "functions.h"

// 현재 조회하고자 하는 고객의 정보를 출력
void printSimCustomer(int currentTime, SimCustomer customer)
{
    char    *status;

    if (customer.status == 0)
        status = "도착";
    else if (customer.status == 1)
        status = "서비스 시작";
    else
        status = "서비스 종료";
    printf("⏰ 현재 시각     : %d\n", currentTime);
    printf("🚥 현재 고객 상태: %d\n", status);
    printf("⏳ 도착 시각     : %d\n", customer.arrivalTime);
    printf("🏃‍♂️ 시작 시각     : %d\n", customer.startTime);
    printf("🏭 서비스 시간   : %d\n", customer.processTime);
    printf("👋 종료 시간     : %d\n", customer.endTime);
}