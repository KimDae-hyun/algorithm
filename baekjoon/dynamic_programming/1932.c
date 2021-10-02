#include <stdio.h>

int cmp_sum(int a, int b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

int sum_tri(int arr[500][500], int i, int j, int max)
{
    if (j == 0) //현재 열의 첫번째 숫자와 이전 열의 첫번째 숫자의 합
        arr[i][j] += arr[i - 1][j];
    else if (j == i) // 현재 열의 마지막 숫자와 이전 열의 마지막 숫자의 합
        arr[i][j] += arr[i - 1][j - 1];
    else // 이전 열의 현재 위치와 다음 위치 중 큰 수와 현재 위치 숫자의 합 
        arr[i][j] += cmp_sum(arr[i - 1][j - 1], arr[i - 1][j]);
    if (max < arr[i][j]) // 최대값 확인
        max = arr[i][j];
    return (max);
}

int main(void)
{
    int arr[500][500] = {0};
    int n;
    int i;
    int j;
    int max;
    
    scanf("%d", &n);
    i = 0;
    while (++i <= n)
    {
        j = 0;
        while (++j <= i)
            scanf ("%d", &arr[i - 1][j - 1]);
    }
    max = arr[0][0];
    i = 0;
    while (++i < n)
    {
        j = -1;
        while (++j <= i)
            max = sum_tri(arr, i, j, max); // 깊이 탐색
    }
    printf("%d", max);
    return (0);
}

/* 참고
입력
    7
   3 8
  8 1 0
 2 7 4 4 
4 5 2 6 5

합
     7
   10 15
  18 16 15
 20 25 20 19
24 30 27 26 24  최대값 30
*/