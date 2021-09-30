#include <stdio.h>

int main(void)
{
    int arr[10000] = {0};
    int a;
    int b;
    int i;
    int n;
    
    scanf("%d %d", &a, &b);
    i = 0;
    n = 2;
    while (42)
    {
        if (a % n == 0 && b % n == 0)
        {
            a /= n;
            b /= n;
            arr[i++] = n;
        }
        else
            n++;
        if (n > a || n > b)
            break ;
    }
    i = - 1;
    n = 1;
    while (arr[++i])
        n *= arr[i];
    printf("%d\n%d", n, a * b * n);
    return (0);
}
