#include <stdio.h>
#include <stdlib.h>

int check(int *board, int n, int q)
{
    int i;
    
    i = -1;
    while (++i < q) // 가로 위치가 같기 전까지 확인
    {
        if (board[q] == board[i] || abs(board[q] - board[i]) == abs(q - i))
            return (0);
            // 세로선상 또는 대각선상에 놓인 경우   대각선 -> (y2 - y1)/(x2 - x1) == 1
    }
    return (1); // 퀸이 놓인 위치에 문제가 없는 경우
}

void rec(int *board, int n, int *count, int q)
{
    int i;
    
    if (q == n) //문제 없이 퀸의 개수가 n이 되면 경우의 수를 추가하고 리턴
    {
        (*count)++;
        return ;
    }
    else
    {
        i = -1;
        while (++i < n)// 처음 퀸부터 i번째 퀸의 위치까지만 확인
        {
            board[q] = i;
            if (check(board, n, q) == 1)
                rec(board, n, count, q + 1);
                // 현재 위치에 문제가 없으면 다음 퀸 추가, 문제가 있으면 다음 위치 확인
        }
    }   
}

int main()
{
    int board[15] = {0}; // 체크판의 세로
    int n;
    int count;
    
    scanf("%d", &n);
    count = 0;
    rec(board, n, &count, 0);// 퀸의 위치를 확인하고 문제가 없으면 경우의 수 추가
    printf("%d", count);
    return (0);
}
