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
/* 규칙 참고
(x+1)^1        1  1
(x+1)^2       1  2  1
(x+1)^3     1 3  3  1
(x+1)^4    1 4  6  4  1
(x+1)^5   1 5 10 10  5 1
(x+1)^6  1 6 15 20 15 6 1
(x+1)^7 1 7 21 35 35 21 7 1
*/
