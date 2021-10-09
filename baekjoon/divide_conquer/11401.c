#include <stdio.h>
#include <stdlib.h>

size_t rec(size_t b, int p, int mod)
{// b의 p 제곱 구하기
    size_t ret;
    
    if (p > 1)
	{
        ret = rec(b, p / 2, mod) % mod;
        if (p % 2 != 0)
            return ((((ret * ret) % mod) * b) % mod);
        else
            return ((ret * ret) % mod);
    }
    else
        return (b);
}

int main(void) //조합을 통한 이항계수 + 페르마 정리를 통한 나머지
{
    int n;
    int k;
    size_t a;
    size_t b;
    int mod;
    int i;
    
    scanf("%d %d", &n, &k);
    i = 0;
    a = 1;
    mod = 1000000007;
    while (++i <= n) // n!
    {
        a *= i;
        a %= mod;
    }
    i = 0;
    b = 1;
    while (++i <= k) // k!
    {
        b *= i;
        b %= mod;
    }
    i = 0;
    while (++i <= n - k) // (n-k)!
    {
        b *= i;
        b %= mod;
    }
    b = rec(b, mod - 2, mod) % mod; // 페르마 정리를 통한 나머지 구하기
    printf("%zu\n", (a * b) % mod);
    return (0);
}

/* 참고 사항
 1. 이항계수와 조합
	- n, k 의 이항계수 
	  => nCk = C(n, k) = n!/(k! * (n - k)!)
 2. 페르마의 소정리 
 	- p가 소수이고 a가 p의 배수가 아니면 a^(p - 1) == 1 (mod p)
	  => a^(p-1) 과 1을 p로 나눈 나머지는 같다.

	  정리
	  a^(p - 2) == a^-1 (mod p)

 3. 이항계수 + 페르마
	- A = n!
	- B = 1/(k! * (n - k)!) 이라고 하면

	A*B^-1 % R = A*B^(p - 2) % R = (A % R)(B^(p - 2) % P) % P 
	
	1)
	// B^-1은 분수로 나머지를 구할 수 없기 때문에
	// 페르마의 소정리를 통해 정수 형태인 B^(p - 2)로 변형
	2)
	// 나머지는 모든수의 나머지의 곱과 같다.
	// ex) A * B % P == (A % P) * (B % P)
*/
