#include <stdio.h>
#include <stdlib.h>

int calc(int *a, int **oper, int i, int result)
{
    if ((*oper)[i] == 1)
        result += a[i + 1];
    else if ((*oper)[i] == 2)
        result -= a[i + 1];
    else if ((*oper)[i] == 3)
        result *= a[i + 1];
    else if ((*oper)[i] == 4)
        result /= a[i + 1];
    return (result);
}

void swap(int **oper, int i, int start)
{
    int tmp;
    
    tmp = (*oper)[i];
    (*oper)[i] = (*oper)[start];
    (*oper)[start] = tmp;
}

void rec(int *a, int **oper, int **m, int count, int start)
{
    int i;
    int cal;
    int result;
    
    if (count == start)
    {
        i = -1;
        result = a[0];
        while (++i < count)
            result = calc(a, oper, i, result);
        if (result > (*m)[1])
            (*m)[1] = result;
        if (result < (*m)[0])
            (*m)[0] = result;
    }
    else
    {
        i = start - 1;
        while (++i < count)
        {
            if (i != start && (*oper)[i] == (*oper)[start])
                continue ;
            swap(oper, i, start);
            rec(a, oper, m, count, start + 1);
            swap(oper, i, start);
        }
    }
}

int main()
{
    int n;
    int a[11] = {0};
    int *oper;
    int *m;
    int i;
    int j;
    int count;
    
    oper = (int *)calloc(10, sizeof(int));
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
    rec(a, &oper, &m, j, 0);
    printf("%d\n%d", m[1], m[0]);
    return (0);
}
