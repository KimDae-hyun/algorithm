#include <stdio.h>
#include <stdlib.h>

int cmp(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}

int main(void)
{
    int **sum;
    int w[101] = {0};
    int v[101] = {0};
    int n;
    int k;
    int i;
    int j;

    scanf("%d %d", &n, &k);
    sum = (int **)calloc(n + 1, sizeof(int *));
    i = -1;
    while (++i <= n)
        sum[i] = (int *)calloc(100001, sizeof(int));
    i = 0;
    while (++i <= n)
        scanf("%d %d", &w[i], &v[i]);
    i = 0;
    while (++i <= n)
    {
        j = 0;
        while (++j <= k)
        {
            if (j - w[i] >= 0)
                sum[i][j] = cmp(sum[i - 1][j], sum[i - 1][j - w[i]] + v[i]);
            else
                sum[i][j] = sum[i - 1][j];
        	printf("%d %d %d \n", sum[i][j], w[i], v[i]);
		}
    }
    printf("%d", sum[n][k]);
    return (0);
}
