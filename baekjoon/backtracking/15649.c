#include <stdio.h>

void rec(int *num, int *check, int n, int m, int first)
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
            if (check[i - 1] == 0)
            {
                num[first] = i;
                check[i - 1] = 1;
                rec(num, check, n, m, first + 1);
                check[i - 1] = 0;
            }
        }
    }
}

int main()
{
    int num[8] = {0};
    int check[8] = {0};
    int n;
    int m;
    
    scanf("%d %d", &n, &m);
    rec(num, check, n, m, 0);
    return (0);
}
