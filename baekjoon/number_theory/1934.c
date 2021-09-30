#include <stdio.h>

int euclid(int a, int b)
{
    int n;
    
    while (42)
    {
        n = a % b;
        if (n == 0)
            return (b);
        a = b;
        b = n;
    }
    return (n);
}

int main(void)
{
    int t;
    int a;
    int b;
    int i;
    int j;
    int n;
    int sum;
    
    scanf("%d", &t);
    i = -1;
    while (++i < t)
    {
        scanf("%d %d", &a, &b);
        if (a < b)
        {
            n = a;
            a = b;
            b = n;
        }
        n = euclid(a, b);
        printf("%d\n", a * b / n);
    }
    return (0);
}
