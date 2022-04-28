#include "mapdef.h"
#include "linkedstack.h"

/*

    의사 코드
    1. 시작점을 찾는다.
    2. 현재 위치가 이동할 수 있는 길이라면 현재 위치를 스택에 push
    3. 상하좌우를 둘러보고 이동할 수 있는 길이 있다면 해당 길로 이동.
        - 이미 방문한 길은 다시 이동하지 않는다.
    4. 2~3번을 반복하고, 더 이상 이동할 수 있는 길이 없다면 스택을 pop 하며 이동할 수 있는 위치를 찾는다.    

*/

// 시작 지점(s) 찾는 함수
MapPosition    findStartingPosition(int maze[WIDTH][HEIGHT])
{
    int i;
    int j;
    MapPosition pos;

    i = 0;
    pos.x = 0;
    pos.y = 0;
    pos.direction = 0;
    while (i < WIDTH)
    {
        j = 0;
        while (j < HEIGHT)
        {
            pos.x = i;
            pos.y = j;
            if (maze[i][j] == START)
                return (pos);
            j++;
        }
        i++;
    }
    pos.direction = -1;
    return (pos);
}

LinkedStack *findPath(int maze[WIDTH][HEIGHT], MapPosition pos, LinkedStack *pStack)
{
    int	result;
    int upX;
    int upY;
    int rightX;
    int rightY;
    int downX;
    int downY;
    int leftX;
    int leftY;

    if (!pStack)
        return (NULL);
    result = TRUE;
	pushLS(pStack, pos);
    if (maze[pos.x][pos.y] == END)
        return (pStack);
    while (result != FALSE)
    {
        maze[pos.x][pos.y] = VISIT; // 현재 위치를 2로 변경
        // 상하좌우 좌표 설정
        upX = pos.x + DIRECTION_OFFSETS[0][0];
        upY = pos.y + DIRECTION_OFFSETS[0][1];
        rightX = pos.x + DIRECTION_OFFSETS[1][0];
        rightY = pos.y + DIRECTION_OFFSETS[1][1];
        downX = pos.x + DIRECTION_OFFSETS[2][0];
        downY = pos.y + DIRECTION_OFFSETS[2][1];
        leftX = pos.x + DIRECTION_OFFSETS[3][0];
        leftY = pos.y + DIRECTION_OFFSETS[3][1];

        // 위로 이동
        if (upX >= 0 && upY >= 0 && maze[upY][upX] == NOT_VISIT)
		{
            pos.y -= 1;
            pos.direction = 0;
            findPath(maze, pos, pStack);
        }
        // 우로 이동
        if (rightX >= 0 && rightY >= 0 && maze[rightY][rightX] == NOT_VISIT)
		{
            pos.x += 1;
            pos.direction = 1;
            findPath(maze, pos, pStack);
        }
        // 아래로 이동
        if (downX >= 0 && downY >= 0 && maze[downY][downX] == NOT_VISIT)
		{
            pos.y += 1;
            pos.direction = 2;
            findPath(maze, pos, pStack);
        }
        // 좌로 이동
        if (leftX >= 0 && leftY >= 0 && maze[leftY][leftX] == NOT_VISIT)
		{
            pos.x -= 1;
            pos.direction = 3;
            findPath(maze, pos, pStack);
        }
        // 상하좌우 이동을 못하는 경우 
        else
            result = FALSE;
    }
    popLS(pStack);
    return (pStack);
}

void	displayPath(LinkedStack *pStack)
{
    StackNode   *pop;

	if (!pStack)
    {
        while (!isLinkedStackEmpty(pStack))
        {
            pop = popLS(pStack);
            printf("(%d, %d)\n", pop->pos.x, pop->pos.y);
        }
    }
    else
        printf("미로를 빠져나갈 길을 찾지 못했습니다.");
}

int main(void)
{
    LinkedStack *pStack;
    MapPosition pos;
    
    int         maze[WIDTH][HEIGHT] = 
    {
        {START, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, END}
    };
    pStack = createLinkedStack();
    pos = findStartingPosition(maze);
    if (pos.direction == -1)
    {
        printf("Error occurs because there is no start.\n");
        return (ERROR);
    }
    pStack = findPath(maze, pos, pStack);
    displayPath(pStack);
    return (0);
}