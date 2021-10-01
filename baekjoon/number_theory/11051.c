#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int **arr;
    int n;
    int k;
    int i;
    int j;
    
    scanf("%d %d", &n, &k);
    arr = (int **)calloc(n, sizeof(int *));
    i = -1;
    while (++i < n)
        arr[i] = (int *)calloc(n + 1, sizeof (int));
    i = -1;
    while (++i < n)
    {
        j = -1;
        while (++j < n + 1)
            arr[i][j] = 1;
    }
    i = 0;
    while (++i < n)
    {
        j = 0;
        while (++j <= i)
            arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]) % 10007;
    }
    printf("%d", arr[i - 1][k]);
    return (0);
}
