#include <stdio.h>

int main(void)
{
    int arr[1001] = {0};
    int front[1001] = {0};
    int back[1001] = {0};
    int max;
    int n;
    int i;
    int j;
    
    scanf("%d", &n);
    i = -1;
    while (++i < n)
        scanf("%d", &arr[i]);
    i = 0;
    while (++i < n)
    {
        j = -1;
        while (++j < i)
            if (arr[i] > arr[j] && front[i] <= front[j])
                front[i] = front[j] + 1;
    }
    i = n - 1;
    while (--i >= 0)
    {
        j = n;
        while (--j > i)
            if (arr[i] > arr[j] && back[i] <= back[j])
                back[i] = back[j] + 1;
    }
    i = -1;
    max = 0;
    while (++i < n)
        if (max < front[i] + back[i] + 1)
            max = front[i] + back[i] + 1;
    printf("%d", max);
    return (0);
}
