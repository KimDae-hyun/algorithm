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
/* 규칙 참고
0 1 2 3 4 5  6  7  8  9
1 1 2 3 4 5  6  7  8  9
2   1 3 6 10 15 21 28 36
3     1 4 10 20 35 56 84
4       1 5  15 35 70 126
5         1  6  21 56 126
6            1  7  28 84
*/
