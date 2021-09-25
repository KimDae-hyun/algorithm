#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr[1000] = {0};
    int count[1000] = {0};
    int a;
    int i;
    int j;
    int min;
    int max;
    
    scanf("%d", &a);
    i = -1;
    max = 0;
    while (++i < a)
    {
        scanf("%d", &arr[i]);
        count[i] = 1;
        min = 0;
        j = -1;
        while (++j < i)
            if (arr[i] > arr[j] && min < count[j])
                min = count[j];
        count[i] = min + 1;
        if (max < count[i])
            max = count[i];
    }
    printf("%d", max);
    return (0);
}
