#include <stdio.h>

size_t div(size_t n, size_t i)
{ //n!에서 i의 배수 개수 구하기
    size_t count;
    size_t j;

    j = i;
    count = 0;
    while (j <= n)
    {
        count += (n / j);
        j *= i;
    }
    return (count);
}

int main(void)
{
    size_t n;
    size_t m;
    size_t i;
    size_t five;
    size_t two;
    
    scanf("%zu %zu", &n, &m);
    five = div(n, 5) - div(m, 5) - div(n - m, 5);// 조합에서 5의 배수 카운트
    two = div(n, 2) - div(m, 2) - div(n - m, 2);// 2의 배수 카운트
    if (five > two) // 5와 2의 배수중 더 작은 수 출력
        printf("%zu", two);
    else
        printf("%zu", five);
    return (0);
}

/* 조합 참고
nCr = n!/(r!*(n-r)!);

7C4 = 7!/(4!*3!);

7!의 5의 배수 개수 - (4!에서 5의 배수 개수 + 3!에서 5의 배수 개수)
2의 배수도 구해서
둘중에 작은 수 출력

ex) 2의 배수 2개, 5의 배수 1개이면
2와 5가 곱해서 10을 만들기 때문에 0이 하나 생성


조합과 이항계수 관계

1Cr (x+1)^1     1 1      1!/1! 1!/1!
2Cr (x+1)^2    1 2 1     2!/2! 2!/1! 2!/2!
3Cr (x+1)^3   1 3 3 1    3!/3! 3!/2! 3!/2! 3!/3!
4Cr (x+1)^4  1 4 6 4 1   4!/(0!4!) 4!/(1!3!) 4!/(2!2!) 4!/(3!1!) 4!/(4!0!)
...
*/
