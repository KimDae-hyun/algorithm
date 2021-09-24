#include <stdio.h>

int cmp_calc(int a, int b)
{
    if (a > b)
        return (b);
    else
        return (a);
}

int main(void)
{
    int sum[1000001] = {0};
    int n;
    int i;
    int count;
    
    scanf("%d", &n);
    i = 1;
    sum[1] = 0;
    while (++i <= n)
    {
        sum[i] = sum[i - 1] + 1;
        if (i % 2 == 0)
            sum[i] = cmp_calc(sum[i / 2] + 1, sum[i]);
        if (i % 3 == 0)
            sum[i] = cmp_calc(sum[i / 3] + 1, sum[i]);
    }
    printf("%d", sum[n]);
    return (0);
}
