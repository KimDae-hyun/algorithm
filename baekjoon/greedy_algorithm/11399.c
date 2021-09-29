#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return (1);
    return (-1);
}

int main(void)
{
    int n;
    int p[1001] = {0};
    int i;
    int sum;
    
    scanf("%d", &n);
    i = -1;
    while (++i < n)
        scanf("%d", &p[i]);
    qsort(p, n, sizeof(int), cmp);
    i = -1;
    sum = 0;
    while (++i < n)
        sum = sum + p[i] * (n - i);
    printf("%d", sum);
    return (0);
}
