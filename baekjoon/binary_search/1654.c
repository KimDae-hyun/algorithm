#include <stdio.h>

int binary(int a[100000], int k, int n, unsigned int start, unsigned int end, int *len)
{
    int i;
    unsigned int piv; // start와 end가 int최대값일때 piv는 int범위 초과
    int count;
    
    if (start > end) // 앞의값이 더 크면 종료 // 같을 때도 확인
        return (*len);
    piv = (start + end) / 2;// 중간값
    i = -1;
    count = 0;
    while (++i < k)
        count += a[i] / piv; // 만들어진 랜선의 개수
    if (count >= n) // 만들어야 하는 랜선보다 크거나 같은 경우 
    {
        if (*len < piv) // 기준값이 만들어진 랜선보다 길면 더 적합한 길이
            *len = piv;
        return (binary(a, k, n, piv + 1, end, len)); // 더 길게 제작
    }
    else // 만들어야 하는 개수보다 부족하면 더 짧게 제작
        return (binary(a, k, n, start, piv - 1, len));    
}

int main(void)
{
    int k;
    int n;
    int a[10000] = {0}; // 주어진 랜선의 길이
    int i;
    unsigned int max; // 가장 긴 랜선
    int len; // 제작된 랜선의 길이
    
    scanf("%d %d", &k, &n);
    i = -1;
    max = 0;
    while (++i < k)
    {
         scanf("%d", &a[i]);
         if (max < a[i])// 기존의 랜선중 가장 긴 랜선의 길이 구하기
             max = a[i];
    }
    len = 0;
    printf("%d", binary(a, k, n, 1, max, &len)); // 이분탐색으로 랜선 제작
    return (0);
}
