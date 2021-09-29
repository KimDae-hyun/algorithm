#include <stdio.h>

int main(void)
{
    size_t len[100000] = {0};
    size_t price[100001] = {0};
    int n;
    int i;
    size_t small;
    size_t sum;
    
    scanf("%d", &n);
    i = -1;
    while (++i < n - 1)
        scanf("%zu", &len[i]);
    i = -1;
    sum = 0;
    while (++i < n - 1)
    {
        scanf("%zu", &price[i]);
        if (i == 0 || small > price[i])
            small = price[i];
        sum += small * len[i];
    }
    printf("%zu", sum);
    return (0);
}
