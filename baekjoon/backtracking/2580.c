#include <stdio.h>
#include <stdlib.h>

int sq_check(int ***su, int i, int j, int n)
{ // 3 * 3 네모칸에서 n이 존재하는지 파악
    int k;
    int l;
    
    k = i - 1;
    while (++k < i + 3) // n이 있으면 0을 리턴하고 다음 값 확인
    {
        l = j - 1;
        while (++l < j + 3)
            if ((*su)[k][l] == n)
                return (0); 
    }
    return (1); //찾고 있는 n이 없는 경우
}

int ver_check(int ***su, int j, int n)
{ // 세로줄에서 n이 존재하는지 파악
    int k;
    
    k = -1;
    while (++k < 9) // n이 있으면 0을 리턴하고 다음 값 확인
        if ((*su)[k][j] == n)
            return (0);
    return (1); //찾고 있는 n이 없는 경우
}

int ho_check(int ***su, int i, int n)
{ // 가로줄에서 n이 존재하는지 파악
    int k;
    
    k = -1;
    while (++k < 9) // n이 있으면 0을 리턴하고 다음 값 확인
        if ((*su)[i][k] == n)
            return (0);
    return (1); //찾고 있는 n이 없는 경우
}

int rec(int ***su)
{
    int i;
    int j;
    int n;
    int zero;
    
    zero = 0;
    i = -1;
    while (++i < 9) // 0(빈칸)의 위치 파악
    {
        j = -1;
        while (++j < 9)
        {
            if ((*su)[i][j] == 0)
            {
                zero = 1; // 0의 위치 i, j
                break ;
            }
        }
        if (zero == 1)
            break ;
    }
    if (zero == 0) // 0이 없으면 완료
        return (1);
    n = 0;
    while (++n < 10)
    {
        if (!ho_check(su, i, n) || !ver_check(su, j, n) ||
            !sq_check(su, i - i % 3, j - j % 3, n))
            continue ; // 0의 위치에서 가로, 세로, 3 * 3내에 존재하지 않는 숫자 확인
        (*su)[i][j] = n;// 가로, 세로, 3 * 3 칸에 n이 없으면 0의 위치에 n 입력
        if (rec(su))
            return (1); //0이 없고 문제가 없으면 1반환
        (*su)[i][j] = 0; // n이 잘못된 숫자인 경우 초기화 
    }
    return (0);
}

int main()
{
    int **su;
    int i;
    int j;
    
    su = (int **)calloc(9, sizeof(int *));
    i = -1;
    while (++i < 9)
        su[i] = (int *)calloc(9, sizeof(int));
    i = -1;
    while (++i < 9) // 9 * 9 값 입력
    {
        j = -1;
        while (++j < 9)
            scanf("%d", &su[i][j]);
    }
    rec(&su); // 빈칸(0) 채우기
    i = -1;
    while (++i < 9) // 빈칸 채워진 9 * 9 출력
    {
        j = -1;
        while (++j < 9)
            printf("%d ", su[i][j]);
        printf("\n");
    }
    return (0);
}
