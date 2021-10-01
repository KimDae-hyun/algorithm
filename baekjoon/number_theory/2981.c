#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return (1);
    return (-1);
}

int euclid(int a, int b)
{
    int n;
    
    while (42)
    {
        n = a % b;
        if (n == 0)
            break ;
        a = b;
        b = n;
    }
    return (b);
}

int main(void)
{
    int n;
    int a[102] = {0};
    int m[102] = {0};
    int ans[100000] = {0};
    int i;
    int j;
    int count;
    
    scanf("%d", &n);
    i = -1;
    while (++i < n)
    {
        scanf("%d", &a[i]);
        if (i > 0)
            m[i] = abs(a[i] - a[i - 1]);
    }
    qsort(m, n, sizeof(int), cmp);
   i = 0;
    while (++i < n)
    {
        j = 0;
        while (++j < n - i)
            m[j] = euclid(m[j], m[j + 1]);
    }
    i = 1;
    j = 0;
    count = 0;
    while (i * i < m[1])
    {
        if (m[1] % i == 0)
        {
            ans[j++] = i;
            ans[j++] = m[1] / i;
            count += 2;
        }
        i++;
    }
    if (i * i == m[1])
    {
        ans[j] = i;
        count++;
    }
    qsort(ans, count, sizeof(int), cmp);
    i = 0;
    while (ans[++i])
        printf("%d ", ans[i]);
    return (0);
}
