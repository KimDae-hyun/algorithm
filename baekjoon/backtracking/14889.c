#include <stdio.h>
#include <stdlib.h>

int calc(int s[20][20], int n, int **idx)
{
    int i;
    int j;
    int sum;
    int jdx[n / 2];
    int tmp[20] = {0};
    
    i = -1;
    while (++i < n / 2)
        tmp[(*idx)[i] - 1] = (*idx)[i];
    i = -1;
    j = -1;
    while (++i < n)
    {
        if (tmp[i] == 0)
        {
            jdx[++j] = i + 1;
            if (j == n / 2 - 1)
                break ;
        }
    }
    i = -1;
    sum = 0;
    while (++i < n / 2)
    {
        j = -1;
        while (++j < n / 2)
            sum += s[(*idx)[i] - 1][(*idx)[j] - 1];
    }
    i = -1;
    while (++i < n / 2)
    {
        j = -1;
        while (++j < n / 2)
            sum -= s[jdx[i] - 1][jdx[j] - 1];
    }
    return (sum);       
}

void rec(int s[20][20], int n, int **idx, int *min, int count, int check)
{
    int i;
    int j;
    int sum;
    
    if (count == n / 2)
    {
        sum = abs(calc(s, n, idx));
        if (sum < *min)
            *min = sum;
    }
    else
    {
        i = check;
        while (++i <= n)
        {
            if ((*idx)[count] == 0)
            {
                if (count != 0 && (*idx)[count - 1] == i)
                    continue ;
                (*idx)[count] = i;
                check = i;
                rec(s, n, idx, min, count + 1, check);
                (*idx)[count] = 0;
            }
        }
    }
}

int main()
{
    int s[20][20] = {0};
    int *idx;
    int n;
    int min;
    int i;
    int j;
    
    scanf("%d", &n);
    idx = (int *)calloc(n / 2, sizeof(int));
    i = -1;
    while (++i < n)
    {
        j = -1;
        while (++j < n)
            scanf("%d", &s[i][j]);
    }
    min = 10000;
    rec(s, n, &idx, &min, 0, 0);
    printf("%d", min);
    return (0);
}
