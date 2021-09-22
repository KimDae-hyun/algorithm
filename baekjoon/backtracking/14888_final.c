#include <stdio.h>

void rec(int *arr, int n, int a, int b, int c, int d, int *min, int *max, int result, int count)
{
    if (count == n - 1)
    {
        if (result > *max)
            *max = result;
        if (result < *min)
            *min = result;
        return ;
    }
    if (a > 0)
        rec(arr + 1, n, a - 1, b, c, d, min, max, result + arr[0], count + 1);
    if (b > 0)
        rec(arr + 1, n, a, b - 1, c, d, min, max, result - arr[0], count + 1);
    if (c > 0)
        rec(arr + 1, n, a, b, c - 1, d, min, max, result * arr[0], count + 1);
    if (d > 0)
        rec(arr + 1, n, a, b, c, d - 1, min, max, result / arr[0], count + 1);
}

int main()
{
    int arr[11];
    int min;
    int max;
    int n;
    int i;
    int a, b, c, d;
    
    scanf("%d", &n);
    i = -1;
    while (++i < n)
        scanf("%d", &arr[i]);
    scanf("%d %d %d %d", &a, &b, &c, &d);
    min = 1000000000;
    max = -1000000000;
    rec(arr + 1, n, a, b, c, d, &min, &max, arr[0], 0);
    printf("%d\n%d", max, min);
    return (0);
}
