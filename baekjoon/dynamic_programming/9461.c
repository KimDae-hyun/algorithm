#include <stdio.h>

int main(void)
{
    long long int tri[100] = {0};
    int t;
    int n;
    int i;
    int k;
    
    tri[0] = 1;
    tri[1] = 1;
    tri[2] = 1;
    tri[3] = 2;
    tri[4] = 2;
    scanf("%d", &t);
    i = -1;
    while (++i < t)
    {
        scanf("%d", &n);
        k = 4;
        while (++k < n)
            tri[k] = tri[k - 5] + tri[k - 1];
        printf("%lld\n", tri[n - 1]);
    }
    return (0);
}
