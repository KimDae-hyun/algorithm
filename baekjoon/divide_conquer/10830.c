#include <stdio.h>

void result(long long pow[5][5], long long mat[5][5], int n)
{
    long long tmp[5][5] = {0};// 행렬의 곱셈을 담아줄 임시배열
    int i;
    int j;
    int a; //곱해지는 행렬 가로 세로 인덱스
    long long sum; // 임시 배열에 담아질 합
    
    i = -1;
    while (++i < n)
    {
        j = -1;
        while (++j < n)
        {
            sum = 0;
            a = -1;
            while (++a < n)
                sum += ((pow[i][a] * mat[a][j]) % 1000);
            tmp[i][j] = (sum % 1000); // pow에 담기면 값이 변하기때문에 임시배열
        }
    }
    i = -1;
    while (++i < n)
    {
        j = -1;
        while (++j < n)
            pow[i][j] = tmp[i][j];
    }
}

void rec(long long pow[5][5], long long mat[5][5], int n, long long b)
{
    if (b == 1) // 제곱 없이 리턴
        return;
    if (b == 2) // 제곱
    {
        result(pow, mat, n);
        return ;
    }
    if (b % 2 != 0) // 지수가 홀수면 하나 빼고 제곱
    {
        rec(pow, mat, n, (b - 1) / 2);
        result(pow, pow, n);
        result(pow, mat, n);
    }
    else // 지수가 짝수일때 제곱
    {
        rec(pow, mat, n, b / 2);
        result(pow, pow, n);
    }
    return ;
}

int main(void)
{
    long long mat[5][5] = {0}; // 주어진 행렬
    long long pow[5][5] = {0}; // 거듭제곱 된  행렬
    int n; // 행렬이 크기
    long long b; // 거듭제곱수
    int i;
    int j;
    
    scanf("%d %lld", &n, &b);
    i = -1;
    while (++i < n)
    {
        j = -1;
        while (++j < n)
        {
            scanf("%lld", &mat[i][j]); 
            pow[i][j] = mat[i][j]; // 곱해주기 위해 처음의 값을 담는다
        }
    }
    rec(pow, mat, n, b); // 지수를 나눠가며 행렬 거듭제곱(분할정복)
    i = -1;
    while (++i < n)
    {
        j = -1;
        while (++j < n)
            printf("%lld ", pow[i][j] % 1000); // 출력값 % 1000
        printf("\n");
    }
    return (0);
}
