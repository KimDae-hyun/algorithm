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
    if (j == 0)
        arr[i][j] += arr[i - 1][j];
    else if (j == i)
        arr[i][j] += arr[i - 1][j - 1];
    else
        arr[i][j] += cmp_sum(arr[i - 1][j - 1], arr[i - 1][j]);
    if (max < arr[i][j])
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
            max = sum_tri(arr, i, j, max);
    }
    printf("%d", max);
    return (0);
}
