#include <stdio.h>

int main(void)
{
    int coin[11] = {0};
    int n;
    int k;
    int i;
    int count;
    
    scanf("%d %d", &n, &k);
    i = -1;
    while (++i < n)
        scanf("%d", &coin[i]);
    i = n - 1;
    count = 0;
    while (k > 0 && i >= 0) 
    {
        if (coin[i] > k)
            i--;
        else
        {
            count++;
            k -= coin[i];
        }
    }
    printf("%d", count);
    return (0);
}
