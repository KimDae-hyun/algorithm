#include <stdio.h>

int main(void)
{
    int arr[10000] = {0};
    int a;
    int b;
    int i;
    int n;
    
    scanf("%d %d", &a, &b);
    i = 0;
    n = 2;
    while (42) //n을 증가시키며 최대공약수 구하기
    {
        if (a % n == 0 && b % n == 0)// 소인수분해
        {
            a /= n;
            b /= n;
            arr[i++] = n;
        }
        else
            n++;
        if (n > a || n > b)
            break ;
    }
    i = - 1;
    n = 1;
    while (arr[++i])
        n *= arr[i]; // 소인수들의 곱 구하기
    printf("%d\n%d", n, a * b * n);
	// 소인수분해 후 남은  두 수와 n을 곱하면 최소 공배수
    return (0);
}

/* 소인수분해 참고

2 | 24 18
3 | 12 9
    4  3

2 * 3 = 6 (최대공약수)
2 * 3 * 4 * 3 = 72 (최소 공배수)

*/
