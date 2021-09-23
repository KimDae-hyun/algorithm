#include <stdio.h>

void fibonacci(int n, int arr[40], int *zero, int *one)
{
    int i;
    
    if (n == 0)
    {
        (*zero)++;
        return ;
    }
    else if (n == 1)
    {
        (*one)++;
        return ;
    }
    else if (n == 2)
    {
        (*zero)++;
        (*one)++;
        return ;
    }
    else
    {
        i = 1;
        while (++i <= n)
        {
            arr[i] = arr[i - 1] + arr[i - 2];
            if (i == n)
            {
                (*zero) = arr[i - 1];
                (*one) = arr[i];
            }
        }
    }
}

int main()
{
    int t;
    int n;
    int arr[40];
    int i;
    int zero;
    int one;

    scanf("%d", &t);
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    i = -1;
    while (++i < t)
    {
        scanf("%d", &n);
        zero = 0;
        one = 0;
        fibonacci(n, arr, &zero, &one);
        printf("%d %d\n", zero, one);
    }
    return (0);
}
