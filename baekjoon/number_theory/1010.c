#include <stdio.h>

int main(void)
{
    int arr[31][31] = {0};
    int t;
    int n;
    int m;
    int k;
    int i;
    int j;
    
    scanf("%d", &t);
    k = -1;
    while (++k < t)
    {
        scanf("%d %d", &n, &m);
        i = -1;
        while (++i < n)
        {
            j = i - 1;
            while (++j < m)
            {
                if (i == j)
                    arr[i][j] = 1;
                else if (i == 0)
                    arr[i][j] = j + 1;
                else
                    arr[i][j] = arr[i - 1][j - 1] + arr[i][j - 1];
            }
        }
        printf("%d\n", arr[n - 1][m - 1]);
    }
    return (0);
}
