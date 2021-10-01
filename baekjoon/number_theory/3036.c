#include <stdio.h>
#include <math.h>

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
    int r[102] = {0};
    int div[102] = {0};
    int i;
    
    scanf("%d", &n);
    i = -1;
    while (++i < n)
    {
        scanf("%d", &r[i]);
        if (i != 0)
           div[i] = euclid(r[0], r[i]);
    }
    i = 0;
    while (r[++i])
        printf("%d/%d\n", (int)(r[0] / div[i]), (int)(r[i] / div[i]));
    return (0);
}
