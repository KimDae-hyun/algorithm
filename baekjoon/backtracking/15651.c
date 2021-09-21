#include <stdio.h>

void rec(int *num, int n, int m, int first)
{
    int i;
    
    if (first == m)
    {
        i = -1;
        while (++i < m)
            printf("%d ", num[i]);
        printf("\n");
    }
    else
    {
        i = 0;
        while (++i <= n)
        {
            num[first] = i;
            rec(num, n, m, first + 1);
        }
    }
}

int main()
{
    int num[8];
    int n;
    int m;
    
    scanf("%d %d", &n, &m);
    rec(num, n, m, 0);
    return(0);
}
