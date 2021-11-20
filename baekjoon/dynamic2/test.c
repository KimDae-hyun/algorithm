#include <stdio.h>
#include <stdlib.h>

int small(int a, int b)
{
    if (a > b)
        return (b);
    return(a);
}

int main(void)
{
    int res[501][501];
	int *num;
    int *sum;
    int t, k, i, j, idx, x, y, mid;

    scanf("%d", &t);
    i = -1;
    while (++i < t)
    {
        scanf("%d", &k);
        num = (int *)calloc(k + 1, sizeof(int));
        sum = (int *)calloc(k + 1, sizeof(int));
        j = 0;
        while (++j <= k)
        {
            scanf("%d", &num[j]);
            sum[j] = sum[j - 1] + num[j];
        }
        idx = 0;
        while (++idx < k)
        {
            x = 0;
            while (++x + idx <= k)
            {
                y = x + idx;
                res[x][y] = 100000000;

                mid = x - 1;
                while (++mid < y)
                    res[x][y] = small(res[x][y], res[x][mid] + res[mid + 1][y] + sum[y] - sum[x - 1]);
            }
        }
        printf("%d\n", res[1][k]);
    }
}