#include <stdio.h>
#include <stdlib.h>

int cmp(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}

int main(void)
{
    int **sum;
    int w[101] = {0};
    int v[101] = {0};
    int n;
    int k;
    int i;
    int j;

    scanf("%d %d", &n, &k);
    sum = (int **)calloc(n + 1, sizeof(int *));
    i = -1;
    while (++i <= n)
        sum[i] = (int *)calloc(100001, sizeof(int));
    i = 0;
    while (++i <= n)
        scanf("%d %d", &w[i], &v[i]);
    i = 0;
    while (++i <= n)
    {
        j = 0;
        while (++j <= k)
        {
            if (j - w[i] >= 0)
                sum[i][j] = cmp(sum[i - 1][j], sum[i - 1][j - w[i]] + v[i]);
            else
                sum[i][j] = sum[i - 1][j];
		}
    }
    printf("%d", sum[n][k]);
    return (0);
}
/* 참고

4 7
6 13
4 8
3 6
5 12

  sum
w   0 1 2 3 4 5  6  7
    0 0 0 0 0 0  0  0
6   0         0  13 13   6
4   0     0 8 8  13 14   4 + 3
3   0   0 6 8 8  13 14   3 + 4
5   0   0 6 8 12 13 14   3 + 4 (5는 12이지만, 위의 값보다 작기 때문에 사용 불가)
    위의 값과 
*/
