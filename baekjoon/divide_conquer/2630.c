#include <stdio.h>
#include <stdlib.h>

void rec(int **paper, int x, int y, int n, int count[2])
{
    int check;
    int i;
    int j;
    
    check = paper[x][y]; // 처음 칸의 색
    i = x - 1;
    while (++i < x + n) // 세로
    {
        j = y - 1;
        while (++j < y + n) // 가로
        {
            if (paper[i][j] != check) // 처음칸과 색이 다른 경우
            {
                check = 2; // 종이를 4등분 하는 경우
                break;
            }
        }
        if (check == 2)
            break ;
    }
    if (check == 2)
    {
        rec(paper, x, y, n / 2, count); // 4등분한 종이의  왼쪽 위
        rec(paper, x + n / 2, y, n / 2, count); // 왼쪽 아래
        rec(paper, x, y + n / 2, n / 2, count); // 오른쪽 위
        rec(paper, x + n / 2, y + n / 2, n / 2, count); // 오른쪽 아래
    }
    else // 종이의 색이 모두 같으면 카운트++
        count[check]++;
    return ;
}

int main(void)
{
    int **paper;// 입력받은 종이의 색
    int count[2] = {0}; // 흰색과 파란색의 개수 파악
    int n; // 크기
    int i; // 세로 인덱스 
    int j; // 가로 인덱스
    
    scanf("%d", &n);
    paper = (int **)calloc(n, sizeof(int *));
    i = -1;
    while (++i < n)
    {
        paper[i] = (int *)calloc(n, sizeof(int));
        j = -1;
        while (++j < n)
            scanf("%d", &paper[i][j]); // 각 위치에 색 입력
    }
    rec(paper, 0, 0, n, count); // 종이를 4등분하면서 개수파악
    printf("%d\n%d", count[0], count[1]);
    return (0);
}
