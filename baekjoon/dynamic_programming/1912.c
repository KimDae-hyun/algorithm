#include <stdio.h>

int cmp(int a, int b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

int main(void)
{
    int arr[100000] = {0};
    int n;
    int i;
    int min;
    int max;
    int sum;
    
    scanf("%d", &n);
    i = -1;
    sum = 0;
    max = -1000;
    while (++i < n)
    {
        scanf("%d", &arr[i]); 
        if (arr[i] > 0)
        {
            if (sum < 0)
                sum = 0;
            sum = sum + arr[i];
        }
        else
        {
            if (sum < 0)
                sum = cmp(sum, arr[i]);
            else
                sum += arr[i];
        }
        if (max < sum)
            max = sum;
    }
    printf("%d", max);
    return (0);
}
