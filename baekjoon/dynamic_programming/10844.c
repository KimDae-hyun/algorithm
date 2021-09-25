#include <stdio.h>

void rec(long long arr[101][10], int n, int i, int count)
{   
    int j;
    
    arr[i][0] = arr[i - 1][1];
    arr[i][9] = arr[i - 1][8];
    j = 0;
    while (++j < 9)
        arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000;
    return ;
}

int main(void)
{
    long long arr[101][10] = {0};
    int n;
    int i;
    long long count;
    
    scanf("%d", &n);
    i = 0;
    while (++i < 10)
        arr[0][i] = 1;
    i = 0;
    while (++i < n)
        rec(arr, n, i, count);
    i = -1;
    count = 0;
    while (++i < 10)
        count += arr[n - 1][i];
    printf("%lld", count % 1000000000);
    return (0);
}
