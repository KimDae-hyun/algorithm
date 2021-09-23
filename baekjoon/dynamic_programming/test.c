#include <stdio.h>

int check(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return (1);
    if (a > 20 || b > 20 || c > 20)
        return (check(20, 20, 20));
    if (a < b && b < c)
        return (check(a, b, c - 1) + check(a, b - 1, c - 1) - check(a, b - 1, c));
    else
        return (check(a - 1, b, c) + check(a - 1, b - 1, c) + check(a - 1, b, c - 1) - check(a - 1, b - 1, c - 1));
}

int main()
{
    int a;
    int b;
    int c;
    int n;
    
    while (42)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a == b == c && a == -1)
            break ;
        else
        {
            n = check(a, b, c);
            printf("w(%d, %d, %d) = %d\n", a, b, c, n);
        }
    }
    return (0);
}
