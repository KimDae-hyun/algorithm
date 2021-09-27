#include <stdio.h>

int main(void)
{
    int l;
    char a[51] = {0};
    int i;
    size_t pow;
    size_t sum;

    scanf("%d", &l);
    scanf("%s", a);
    i = -1;
    sum = 0;
    pow = 1;
    while (++i < l)
    {
        sum = (sum + (a[i] - 96) * pow) % 1234567891;
        pow = (pow * 31) % 1234567891;
    }
    printf("%zu", sum);
    return (0);
}
