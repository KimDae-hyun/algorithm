#include <stdio.h>
#include <stdlib.h>

int sq_check(int ***su, int i, int j, int n)
{
    int k;
    int l;
    
    k = i - 1;
    while (++k < i + 3)
    {
        l = j - 1;
        while (++l < j + 3)
            if ((*su)[k][l] == n)
                return (0); 
    }
    return (1);
}

int ver_check(int ***su, int j, int n)
{
    int k;
    
    k = -1;
    while (++k < 9)
        if ((*su)[k][j] == n)
            return (0);
    return (1);
}

int ho_check(int ***su, int i, int n)
{
    int k;
    
    k = -1;
    while (++k < 9)
        if ((*su)[i][k] == n)
            return (0);
    return (1);
}

int rec(int ***su)
{
    int i;
    int j;
    int n;
    int zero;
    
    zero = 0;
    i = -1;
    while (++i < 9)
    {
        j = -1;
        while (++j < 9)
        {
            if ((*su)[i][j] == 0)
            {
                zero = 1;
                break ;
            }
        }
        if (zero == 1)
            break ;
    }
    if (zero == 0)
        return (1);
    n = 0;
    while (++n < 10)
    {
        if (!ho_check(su, i, n) || !ver_check(su, j, n) ||
            !sq_check(su, i - i % 3, j - j % 3, n))
            continue ;
        (*su)[i][j] = n;
        if (rec(su))
            return (1);
        (*su)[i][j] = 0;
    }
    return (0);
}

int main()
{
    int **su;
    int i;
    int j;
    
    su = (int **)calloc(9, sizeof(int *));
    i = -1;
    while (++i < 9)
        su[i] = (int *)calloc(9, sizeof(int));
    i = -1;
    while (++i < 9)
    {
        j = -1;
        while (++j < 9)
            scanf("%d", &su[i][j]);
    }
    rec(&su);
    i = -1;
    while (++i < 9)
    {
        j = -1;
        while (++j < 9)
            printf("%d ", su[i][j]);
        printf("\n");
    }
    return (0);
}
