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

// 상 우 하 좌 (시계방향 탐색) -> 뚫려있으면 그 방향으로 가서 다시 상 우 하 좌 탐색. 이때, 이미 방문한 곳은 방문 X && 벽 방문 X
// if ( NOT_VISIT == search)

// 입력값이 미로 전체 모양 8x8
// 시작점 s, 종료지점 e

/*
    char    maze[8][8];
    maze[0] = strcpy("11111111")

    maze[0] = 1 1 1 1 1 1 1 1
    maze[1] = 1 0 0 0 0 0 e 1
    maze[2] = 1 0 1 0 1 1 1 1
    maze[3] = 1 0 1 0 s 0 1 1
    maze[4] = 1 0 1 1 1 0 1 1
    maze[5] = 1 0 1 1 1 0 1 1
    maze[6] = 1 0 0 0 0 0 0 1
    maze[7] = 1 1 1 1 1 1 1 1
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

    if (!pStack)
        return (NULL);
    result = TRUE;
	pushLS(pStack, pos);
    if (maze[pos.x][pos.y] == END)
        return (pStack);
    while (result != FALSE)
    {
        maze[pos.x][pos.y] = VISIT; // 현재 위치를 2로 변경
        // 위로 이동
        // pos.direction == 0 (위) == 1 (우) 
        if (maze[pos.x][pos.y + DIRECTION_OFFSETS[pos.direction][1]]!= VISIT && maze[pos.x][pos.y + DIRECTION_OFFSETS[pos.direction][1]] != WALL)
		{
            pos.y -= 1;
            pos.direction = 0;
            findPath(maze, pos, pStack);
        }
        // pos.move
        // pos.direction -> pos.direction 반대방향이면 if문 안돌기
        // 1 1 1 1 1 1 1
        // 1 1 1 0 1 0 1
        // 1 1 1 0 1 0 1
        // 1 e 0 s 0 0 1
        // 1 1 1 1 1 1 1
        // push 하기 전에 이미 경로를 체크한다.
        // 빠져 나올 떄 2가 있으면 pop??
        // 위 우 아래 좌 -> direction
        // 위로 쭉 가다가 막혔을때 양옆도 막힌 경우 -> 위 우 아래 (지나왔던길)
        // 우로 이동
        // if (maze[pos.x][pos.y] == 'e')
        
        if (maze[pos.x + DIRECTION_OFFSETS[pos.direction][0]][pos.y] != VISIT && maze[pos.x + DIRECTION_OFFSETS[pos.direction][0]][pos.y] != WALL)
		{
            pos.x += 1;
            pos.direction = 1;
            findPath(maze, pos, pStack);
        }
        // 아래로 이동
        if (maze[pos.x][pos.y + DIRECTION_OFFSETS[pos.direction][1]] != VISIT && maze[pos.x][pos.y + DIRECTION_OFFSETS[pos.direction][1]] != WALL)
		{
            pos.y += 1;
            pos.direction = 2;
            findPath(maze, pos, pStack);
        }
        // 좌로 이동
        if (maze[pos.x + DIRECTION_OFFSETS[pos.direction][0]][pos.y] != VISIT && maze[pos.x + DIRECTION_OFFSETS[pos.direction][0]][pos.y] != WALL)
		{
            pos.x -= 1;
            pos.direction = 4;
            findPath(maze, pos, pStack);
        }
        // 상하좌우 이동을 못하는 경우 
        else
            result = FALSE;
    }
    return (NULL);
}

// int findAvailablePath(char pos)
// {
//     if (pos == NOT_VISIT)
//         return (1);
//     return (0);
// }

// LinkedStack *findPath(char maze[WIDTH][HEIGHT], MapPosition start_pos)
// {
//     LinkedStack		*pathStack;
//     StackNode		*popstat;
//     int         x;
//     int         y;

//     x = start_pos.x;
//     y = start_pos.y;
//     maze[x][y];

//     // 재귀로 구현하면 이렇게도 가능할 것 같아요..!
//     // 이런 식으로..? 
//     // 위로 계속 이동하다가 안되면 오른쪽으로 계속 이동하고, 오른쪽으로 이동해서 다시 상우하좌 살피고 순서대로 가지 않을까 싶어요.
//     // 위로 이동
//     // 아 좋은 방법 생각났어요
//     // 오홍
//     // 그니까요 흫긓ㄱ
//     if (maze[x][y + 1] != VISIT && maze[x][y + 1] != WALL)
//     {
//         start_pos.y += 1;
//         findPath(maze, start_pos);
//     }

//     if (findAvailablePath(maze[x][y - 1])) // 이렇게 체크해도 되지 않을까요
//     {
//         pushLS(pathStack, 'U');
//         start_pos.direction++;
//         start_pos.y -= 1;
//          // 여기서 체크는 무조건 하고 만약 이동 가능하면 그대로 재귀 돌리고
//         // 체크 해서 만약 다음이 막히면 밑으로 내려가서 체크 쭉 하다가 아 잠시만요 생각보다 어렵네요
//         // 아 그냥 이거 밑에 다 돌린다음에 안되면 direction만큼 pop 하면 될거 같아요
//         // 만약 체크 안되면 ( else 면)
//         // 어떻게 생각하시나요 direction을 이동 거
//         // direction 이 의미하는게 이동거리 음. . 
//         // 아하 좋습니다 좋습니다
//         // 그럼 해당 if문 전부 재귀 돌려버릴까요
//         // 넵넵 재귀로 한번 구현해보면 좋을 것 같아요
//         // 그럼 findAvailablePath 함수에서 한번 볼까요
//         // 그러면 findAvailablePath 함수가 수행하는게, 해당 방향으로 계속 움직이는 걸까요?? 
//         // 아하 한 스텝만 검사하는군요
//         // 그리고 pop할 때 해당 pos들을 다 2로 바꿔주면 될거 같아요
//         // if 문 조건을 이동하려는 방향에서 + 1 만큼 이동했을 때, 벽이 아니면서, 이미 방문한 곳이 아닌 조건을 주면 어떨까 싶어요!
//     }
//     // 아 맞다 오늘 러시 평가 몇시부터 시작이시죠?? 아하 알겠습니당 그전까지 최대한 해보아용
//     // 저 12시 30분까지 가야되느ㅜㄴ데 점심 약속이 있어서 11시 30분에 가봐야될거 같아요
//     else if (findAvailablePath(maze[x + 1][y]))
//     {
//         pushLS(pathStack, 'R');
//         start_pos.direction++;
//         start_pos.x += 1;
//     }
//     else if (findAvailablePath(maze[x][y + 1]))
//     {
//         pushLS(pathStack, 'D');
//         start_pos.direction++;
//         start_pos.y += 1;
//     }
//     else if (findAvailablePath(maze[x - 1][y]))
//     {
//         pushLS(pathStack, 'L');
//         start_pos.direction++;
//         start_pos.x -= 1;
//     }
//     else
//     {
//         while (start_pos.direction--)
//         {
//             // 더 고려해야될게 있을까요???
//             // 여기서 위치 체크하면서 pop 할 때 해당 위치도 VISIT으로 바꾸면 될거 같아요
//             popstat = popLS(pathStack);
//             maze[start_pos.x][start_pos.y] = VISIT;
//             if (popstat->data == 'U')
//             {
//                 start_pos.y += 1;
//             }
//             // stack 에서 뽑아낸 정보가 Up 이라면 음 헷갈리네요
//             // stack 에서 pop한 정보가 up이라서 뒤로 돌아가야되니까
//             // 전에는 - 해준걸 다시 + 해준거에요 아아 맞맞/네요
//             // 그쵸그쵸 
//             // pop 해주는 이유는 위에 다 체크가 안됐으니
//             // 근데 생각해보니까
//             // 좀 다르게 구상해야될거 같아요
//             // 1 1 1 1 1 1
//             // 1 1 0 1 0 1 << 여기서 위로 쭉 올라가다가
//             // 1 1 0 1 0 1    결국 상 우 하 좌 다 돌아버리면
//             // 1 0 s 0 0 1    우 할 때 같이 겹칠거 같아서
//             // 1 1 1 1 1 1    차라리 direction을 진짜 방향으로 쓰거나
//             //                위에 if에서 peek으로 반대는 제거하는 방법으로 해야될거 같아요
//             //                개인적으로는 if에서 peek으로 반대도 체크하는게 좀 더 편해보이긴 하네요
//             // if 문이 else 이전에 나오는 if 문들 말씀하시는 거 맞죵???
//             // 넵 만약에 상 우 하 좌 다 돌 때 위로 쭉 가고 우 없고 다시 하 체크하게되면
//             // 진행한 방향 visit 체크를 안하기 때문에 그대로 갖고 갈거 같아서요
//             // 그래서 (위로가는 이프문)if (find 어쩌구 다음에 !peek(down 아닐 때))
//             // 이런식으로 다시 밑으로 안내려가게 만드는거죠
//             // 어떤식으로 하면 될까요??
//             // 갑자기 문득 든 생각인데, 탐색 가능한 모든 경로를 방문했다는 플래그 변수를 하나 쓰면 어떨까 싶어요!
//             // 재귀함수 ()
//             // {
//             //     result = TRUE;
//             //     while (result != FALSE)
//             //     {
//             //         if (위로 이동 가능)
//             //             재귀함수()
//             //         if (아래로 이동 가능)
//             //             재귀함수()
//             //         if (우로 이동 가능)
//             //             재귀함수()
//             //         if (좌로 이동 가능)
//             //             재귀함수()
//             //         else
//             //             result = FALSE
//             //     }
//             // }
//             // 정확한지는 모르겠는데 생각나는 구조는 이런 느낌이에요
//             // 그러면 러시 다녀오시는 동안 한번 틀 작성해보고 있겠습니다 ㅎㅎ
//             // 좋습니당 그러면 지금은 여기까지 하고, 점심식사 맛있게 드시고 오세욥 ㅎㅎ 러시 평가도 잘다녀오세요 ! 넵넵 ㅎㅎ 감사합니다 ~~ 수고 많으셨어요 !!
//             // 좋은거 같아요 OO로 이동 가능 함수들은 있는거 쓰고 재귀 구조들만 잘 들고가면 될거 같아요
//             // 넵 저도 계속 생각하면서 좋은 생각 떠오르면 한번 머릿속으로 구상해볼게요
//             // 넵 고생 너무 많으셨습니다 준한님도 점심 마ㅓㅅ있게 드시고 이따 다시 한번 봬용!!
//             else if (popstat->data == 'R')
//             {
//                 start_pos.x += 1;
//             }
//             else if (popstat->data == 'D')
//             {
//                 start_pos.y -= 1;
//             }
//             else if (popstat->data == 'L')
//             {
//                 start_pos.x -= 1;
//             }
//         }
//     }
//     // 이런식으로 하면 안되겠죠...?
//     // 그냥 이프문 4번 돌릴까요...?
//     // 함수를 하나로 통일시켜서 하면 좋을 것 같아요
//     // 넵 일단 고민 해보죠.......
//     // 아 그래서 direction 까지 받는거군요
//     // 저도 강한편은 아니라서..... 어떡하죠... 일단 고민 좀 해볼게요
//     // 재귀로 구현할 수 있는 방법이 있을까요...? 전 사실 재귀 구현하는 게 제일 약해서
//     // 좋은 방법이 바로 떠오르지 않습니다 흑흑 저도 머리르 ㄹ열심히 굴려보겠습니다
//     // ...아아 if 문이라면 상,우,하,좌 방향으로 마지막에 도달하기 전까지 재귀를 돌리면 될 것 같은데욥..!?
    
//     return (pathStack);
// }

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
        {-10, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 10}
    };
    
    // char        maze[WIDTH][HEIGHT] = 
    // {
    //     {'s', '0', '1', '1', '1', '1', '1', '1'},
    //     {'1', '0', '0', '0', '0', '0', '0', '1'},
    //     {'1', '1', '1', '0', '1', '1', '1', '1'},
    //     {'1', '1', '1', '0', '1', '1', '1', '1'},
    //     {'1', '0', '0', '0', '0', '0', '0', '1'},
    //     {'1', '0', '1', '1', '1', '1', '1', '1'},
    //     {'1', '0', '0', '0', '0', '0', '0', '0'},
    //     {'1', '1', '1', '1', '1', '1', '1', 'e'}
    // };
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