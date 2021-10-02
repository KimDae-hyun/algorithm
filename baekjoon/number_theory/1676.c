#include <stdio.h>

int main(void)
{
    int n;
    int i;
    int count;
    
    scanf("%d", &n);
    i = 5;
    count = 0;
    while (i <= n)
    {
        count += (n / i);
        i *= 5; // 5의 배수마다 0이 늘어난다
    }
    printf("%d", count);
    return (0);
}
