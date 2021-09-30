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
    int num[50] = {0};
    int n;
    int i;
    
    scanf("%d", &n);
    i = -1;
    while (++i < n)
        scanf("%d", &num[i]);
    qsort(num, n, sizeof(int), cmp);
    printf("%d", num[0] * num[n - 1]);
    return (0);
}
