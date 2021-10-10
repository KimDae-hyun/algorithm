#include <stdio.h>

void result(long long pow[2][2], long long a[2][2], int mod)
{
    long long tmp[2][2] = {0}; // 곱해줄 값을 담아줄 임시 행렬
    int i;
    int j;
    int k;
    long long sum;
    
    i = -1;
    while (++i < 2)
    {
        j = -1;
        while (++j < 2)
        {
            sum = 0;
            k = -1;
            while (++k < 2)
                sum += ((pow[i][k] * a[k][j]) % mod); // 행렬의 곱셈
            tmp[i][j] = (sum % mod); // mod로 나눈 나머지값만 필요
        }
    }
    i = -1;
    while (++i < 2)
    {
        j = -1;
        while (++j < 2)
            pow[i][j] = tmp[i][j]; // 곱셈의 결과를 기존 행렬에 담아줌
    }
}

void rec(long long pow[2][2], long long a[2][2], long long b, int mod)
{ // 행렬 a를 b만큼 거듭제곱하는 재귀함수
    if (b == 1)
        return;
    if (b % 2 != 0)
    {
        rec(pow, a, (b - 1) / 2, mod); // 지수가 홀수이면 짝수로 만든 후 재귀 
        result(pow, pow, mod); // 지수가 하나 빠진 상태로 행렬 제곱
        result(pow, a, mod); // 빼주었던 하나를 추가적으로 곱함
    }
    else
    {
        rec(pow, a, b / 2, mod); //지수가 짝수인 경우 지수의 절반으로 재귀
        result(pow, pow, mod); // 행렬 제곱
    }
    return ;
}


int main(void)
{
    long long n; // 주어지는 제곱수
    long long fiv[2][1] = {{1}, {0}}; // 초기값, u0 + 거듭제곱 후 결과 행렬
    long long a[2][2] = {{1, 1}, {1, 0}};  // 초기 행렬 A
    long long pow[2][2] = {{1, 1}, {1, 0}}; // 거듭제곱 될 행렬 초기값은 A
    int mod; // 나머지를 구할 값 1000000007
    
    scanf("%lld", &n);
    if (n == 1 || n == 2) // 피보나치의 1, 2번째 값은 1
    {
        printf("1");
        return (0);
    }
    mod = 1000000007;
    rec(pow, a, n - 1, mod); // Un = A^n * U0에서 행렬 A의 거듭제곱 구하는 재귀
    fiv[0][0] = pow[0][0] * fiv[0][0] + pow[0][1] * fiv[1][0];
    fiv[1][0] = pow[1][0] * fiv[0][0] % n + pow[1][1] * fiv[1][0];
	// 거듭제곱된 행렬 A와 초기값 U0를 곱한 결과
    printf("%d", (int)fiv[0][0]);
    return (0);
}
/* fibonacci 행렬 거듭제곱  정리 참고

https://seen-crime-5eb.notion.site/60d300692b43428daf98cec4281294ba

*/
