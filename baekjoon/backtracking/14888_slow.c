#include <stdio.h>
#include <stdlib.h>

int calc(int *a, int *oper, int i, int result)
{
    if (oper[i] == 1)
        result += a[i + 1];
    else if (oper[i] == 2)
        result -= a[i + 1];
    else if (oper[i] == 3)
        result *= a[i + 1];
    else if (oper[i] == 4)
        result /= a[i + 1];
    return (result);
}

void rec(int *a, int *oper, int *range_oper, int *check, int **m, int count, int start, int result)
{
    int i;
    int cal;
    
    if (count == start)
    {
        i = -1;
        while (++i < count)
            result = calc(a, range_oper, i, result);
        if (result > (*m)[1])
            (*m)[1] = result;
        if (result < (*m)[0])
            (*m)[0] = result;
    }
    else
    {
        i = 0;
        while (++i <= count)
        {
            if (check[i - 1] == 0)
            {
                range_oper[start] = oper[i - 1];
                check[i - 1] = 1;
                rec(a, oper, range_oper, check, m, count, start + 1, result);
                check[i - 1] = 0;
            }
        }
    }
}

int main()
{
    int n;
    int a[11] = {0};
    int oper[10] = {0};
    int range_oper[10] = {0};
    int check[10] = {0};
    int *m;
    int i;
    int j;
    int count;
    
    m = (int *)malloc(sizeof(int) * 2);
    m[0] = 1000000000;
    m[1] = -1000000000;
    scanf("%d", &n);
    i = -1;
    while (++i < n)
        scanf("%d", &a[i]);
    i = -1;
    j = 0;
    while (++i < 4)
    {
        scanf("%d", &count);
        if (count != 0)
        {
            count = j + count;
            while (j < count)
                oper[j++] = i + 1;
        }
    }
    rec(a, oper, range_oper, check, &m, j, 0, a[0]);
    printf("%d\n%d", m[1], m[0]);
    return (0);
}
