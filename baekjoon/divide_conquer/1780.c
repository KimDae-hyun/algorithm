#include <stdio.h>
#include <stdlib.h>

void rec(int **paper, int x, int y, int n, int count[3])
{
    int check;
    int i;
    int j;

    check = paper[x][y];//첫 칸의 숫자
    i = x - 1;
    while (++i < x + n) // 나눠진 세로만큼
    {
        j = y - 1;
        while (++j < y + n) // 나눠진 가로만큼
        {
            if (paper[i][j] != check) // 첫 칸과 숫자가 다르면 분할
            {
                check = 2;
                break;
            }
        }
        if (check == 2)
            break ;
    }
    if (check == 2) // 첫칸과 다른 숫자가 있는 경우 분할
    {
        rec(paper, x, y, n / 3, count); // 9등분 중 왼쪽 위
        rec(paper, x, y + n / 3, n / 3, count); // 중간 위
        rec(paper, x, y + n * 2 / 3, n / 3, count); // 오른쪽 위
        rec(paper, x + n / 3, y, n / 3, count); // 중간 왼쪽
        rec(paper, x + n / 3, y + n / 3, n / 3, count); // 중간의 중간
        rec(paper, x + n / 3, y + n * 2 / 3, n / 3, count); // 중간의 오른쪽
        rec(paper, x + n * 2 / 3, y, n / 3, count); // 아래의 왼쪽
        rec(paper, x + n * 2 / 3, y + n / 3, n / 3, count); // 아래의 중간
        rec(paper, x + n * 2 / 3, y + n * 2 / 3, n / 3, count); // 아래의 오른쪽
    }
    else
        count[check + 1]++; //같은 숫자로 이루어진 경우 각 숫자 카운트 ++
    return ;
}

int main(void)
{
    int **paper;
    int count[3] = {0};
    int n;
    int i;
    int j;

    scanf("%d", &n);
    paper = (int **)calloc(n, sizeof(int *));
    i = -1;
    while (++i < n)
    {
        paper[i] = (int *)calloc(n, sizeof(int));
        j = -1;
        while (++j < n)
            scanf("%d", &paper[i][j]);
    }
    rec(paper, 0, 0, n, count); // 같은 숫자이면 카운트, 다른 숫자이면 분할
    printf("%d\n%d\n%d", count[0], count[1], count[2]);
    return (0);
}
