#include <stdio.h>
#include <math.h>

size_t rec(int a, int b, int c)
{
    size_t ret;
    
    if (b > 1)
    {
        ret = rec(a, b / 2, c); // 지수를 절반으로 나눠가며 깊이 탐색
        if (b % 2 != 0)
            return (((ret * ret) % c * a) % c); // 지수가 홀수인 경우 
        else
            return ((ret * ret) % c); // 지수가 짝수인 경우
    }
    else
        return (a);
}

int main(void)
{
    int a;
    int b;
    int c;
    size_t ret;
    
    scanf("%d %d %d", &a, &b, &c);
    if (b == 1)
            printf("%d", (int)(a % c));// 1은 제곱 없이 바로 나머지 출력
    else
    {
        ret = rec(a % c, b, c); // 지수를 절반으로 나눠가며 빠른 결과 도출
        printf("%d", (int)(ret % c));
    }
    return (0);
}
