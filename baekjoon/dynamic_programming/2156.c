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
    i = 2;
    while (++i < n)
        sum[i] = cmp_sum(step[i] + sum[i - 2], cmp_sum(step[i] + step[i - 1] + sum[i - 3], sum[i -1]));
    printf("%d", sum[n - 1]);
    return (0);
}
