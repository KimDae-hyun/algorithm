#include <stdio.h>
#include <stdlib.h>

void rec(int **paper, int x, int y, int n)
{
    int check;
    int i;
    int j;

    check = paper[x][y]; // 첫번째칸 숫자
    i = x - 1;
    while (++i < x + n)
    {
        j = y - 1;
        while (++j < y + n)
        {
            if (paper[i][j] != check) // 처음 칸의 숫자와 다른 경우 분할
            {
                check = 2;
                break;
            }
        }
        if (check == 2)
            break ;
    }
    if (check == 2)
    {
        printf("("); // 분할하게 되면 () 추가
        rec(paper, x, y, n / 2); // 4분할 왼쪽 위
        rec(paper, x, y + n / 2, n / 2); // 오른쪽 위
        rec(paper, x + n / 2, y, n / 2); // 왼쪽 아래
        rec(paper, x + n / 2, y + n / 2, n / 2); // 오른쪽 아래
        printf(")");
    }
    else
        printf("%d", check); // 해당 숫자 출력
    return ;
}

int main(void)
{
    char tmp[65] = {0}; // 문자열로 들어오는 숫자를 담아줄 임시배열 
    int **paper; // 숫자를 담아줄 이중배열
    int n; // 크기
    int i; // 세로인덱스
    int j; // 가로인덱스

    scanf("%d", &n);
    paper = (int **)calloc(n, sizeof(int *));
    i = -1;
    while (++i < n)
    {
        paper[i] = (int *)calloc(n, sizeof(int));
        scanf("%s", tmp); // 문자열로 숫자를 받은 후
        j = -1;
        while (++j < n)
            paper[i][j] = tmp[j] - 48; // 각 숫자를 이중배열에 담기
            
    }
    rec(paper, 0, 0, n); // 영상을 분할하며 같은 숫자로 이루어진 부분 찾기
    return (0);
}
