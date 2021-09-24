#include <stdio.h>

int main(void)
{
    int n;
    int i;
    int a;
    int b;
    int c;
    
    a = 1;
    b = 1;
    scanf("%d", &n);
    i = 0;
    while (++i < n)
    {
        c = (a + b) % 15746;
        a = b;
        b = c;
    }
    printf("%d", b);
    return (0);
}
