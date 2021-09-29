#include <stdio.h>

int main(void)
{
    int arr[11][12];
    int n;
    int k;
    int i;
    int j;
    
    scanf("%d %d", &n, &k);
    i = -1;
    while (++i < 11)
    {
        j = -1;
        while (++j < 12)
            arr[i][j] = 1;
    }
    i = 0;
    while (++i < n)
    {
        j = 0;
        while (++j <= i)
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
    }
    printf("%d", arr[i - 1][k]);
}
