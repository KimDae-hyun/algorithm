#include <stdio.h>

int euclid(int a, int b)
{
    int n;
    
    while (42)
    {
        n = a % b;
        if (n == 0)
            return (b);
        a = b;
        b = n;
    }
    return (n);
}

int main(void)
{
    int t;
    int a;
    int b;
    int i;
    int j;
    int n;
    int sum;
    
    scanf("%d", &t);
    i = -1;
    while (++i < t)
    {
        scanf("%d %d", &a, &b);
        if (a < b) // 오름차순 정렬
        {
            n = a;
            a = b;
            b = n;
        }
        n = euclid(a, b); // 유클리드 - 최대공약수 구하기
        printf("%d\n", a * b / n);
		// 두 수의 곱을 최대공약수로 나누면 최소공배수
    }
    return (0);
}
