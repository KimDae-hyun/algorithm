#include <stdio.h>

int cmp_cost(int a, int b)
{
    if (a > b)
        return (b);
    else
        return (a);
}

int main()
{
    int r[1000] = {0};
    int g[1000] = {0};
    int b[1000] = {0};
    int sum[1000][3] = {0};
    int n;
    int i;
    int min;
    
    scanf("%d", &n);
    i = -1;
    while (++i < n)
        scanf("%d %d %d", &r[i], &g[i], &b[i]);
    sum[0][0] = r[0];
    sum[0][1] = g[0];
    sum[0][2] = b[0];
    i = 0;
    while (++i < n)
    {
        sum[i][0] = r[i] + cmp_cost(sum[i - 1][1], sum[i - 1][2]);
        sum[i][1] = g[i] + cmp_cost(sum[i - 1][0], sum[i - 1][2]);
        sum[i][2] = b[i] + cmp_cost(sum[i - 1][0], sum[i - 1][1]);
    }
    min = 1000000;
    i = -1;
    while (++i < 3)
        if (sum[n - 1][i] < min)
            min = sum[n - 1][i];
    printf("%d", min);
    return (0);
}
