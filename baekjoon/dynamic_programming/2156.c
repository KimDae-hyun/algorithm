#include <stdio.h>

int cmp_sum(int a, int b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

int main(void)
{
    int step[10000] = {0};
    int sum[10000] = {0};
    int n;
    int i;
    
    scanf("%d", &n);
    i = -1;
    while (++i < n)
        scanf("%d", &step[i]);
    sum[0] = step[0];
    sum[1] = step[0] + step[1];
    sum[2] = cmp_sum(step[0] + step[2], cmp_sum(step[1] + step[2], sum[1]));
    // 첫번째 세번째 합, 두번째 세번째 합, 첫번째 두번째 합 중 큰 값이 세번째 합계
    i = 2;
    while (++i < n)
        sum[i] = cmp_sum(step[i] + sum[i - 2], cmp_sum(step[i] + step[i - 1] + sum[i - 3], sum[i -1]));
        // 현재 위치의 합계
        // 전전 위치의 합과 현재 값의 합, 전전전 위치의 합과 현재 값과 이전 값의 합, 이전 위치의 합 중에서 가장 큰 값
    printf("%d", sum[n - 1]);
    return (0);
}

/* 참고     step[i]  sum[i-1]    step[i] step[i-1] sum[i-3]   sum[i-1]
    최대값  | 현재값 + 전전위치 합 or  현재 값 + 이전 값 + 전전전 합 or 이전 위치 합
6   | 6
10  | 16
13  | 19  |   13 + 6 = 25    or                          or   16  
9   | 28  |   9 + 19 = 28    or    9 + 13 + 6  = 28      or   19 
8   | 33  |   8 + 19 = 27    or    8 + 9  + 16 = 33      or   25 
1   | 33  |   1 + 28 = 29    or    1 + 8  + 19 = 28      or   33    
*/