#include <stdio.h>

int rec(char arr[101], int n, int i, int count)
{
    int k;
    
    if (n == i && arr[i - 1] != 0)
        return (count + 1);
    k = -1;
    while (i < n && ++k < 10)
    {
        if (arr[i - 1] - 1 == k + 48)
        {
            arr[i] = k + 48;
            count = rec(arr, n, i + 1, count) % 1000000000;
            continue ;
        }
        if (arr[i - 1] + 1 == k + 48)
        {
            arr[i] = k + 48;
            count = rec(arr, n, i + 1, count) % 1000000000;
            break ;
        }
    }
    return (count);
}

int main(void)
{
    char arr[101] = {0};
    int n;
    int i;
    int count;
    
    scanf("%d", &n);
    i = 0;
    count = 0;
    while (++i < 10)
    {
        arr[0] = i + 48;
        count = rec(arr, n, 1, count) % 1000000000;
    }
    printf("%d", count);
    return (0);
}
