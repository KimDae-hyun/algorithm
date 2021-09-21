#include <stdio.h>

void rec(int *num, int check, int n, int m, int first)
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
        i = check;
        while (++i <= n)
        {
            num[first] = i;
            check = i;
            rec(num, check, n, m, first + 1);
        }
    }
}

int main()
{
    int num[8] = {0};
    int check;
    int n;
    int m;
    
    scanf("%d %d", &n, &m);
    rec(num, check, n, m, 0);
    return (0);
}
