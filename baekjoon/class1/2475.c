#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    int i;
    int sum;
    
    i = -1;
    sum = 0;
    while(++i < 5)
    {
        scanf ("%d", &n);
        sum += pow(n, 2);
    }
    printf("%d", sum % 10);
    return (0);
}

