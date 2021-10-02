#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return (1);
    return (-1);
}

int euclid(int a, int b)
{
    int n;
    
    while (42)
    {
        n = a % b;
        if (n == 0)
            break ;
        a = b;
        b = n;
    }
    return (b);
}

int main(void)
{
    int n;
    int a[102] = {0};
    int m[102] = {0};
    int ans[100000] = {0};
    int i;
    int j;
    int count;
    
    scanf("%d", &n);
    i = -1;
    while (++i < n)
    {
        scanf("%d", &a[i]);
        if (i > 0)
            m[i] = abs(a[i] - a[i - 1]); //이전 값과의 차이 저장
    }
    qsort(m, n, sizeof(int), cmp); //차이 값들의 오름차순 저장
    i = 0;
    while (++i < n)
    {
        j = 0;
        while (++j < n - i)
            m[j] = euclid(m[j], m[j + 1]);
			// 유클리드 알고리즘을 반복하여 모든 값의 최대공약수 구하기
    }
    i = 1;
    j = 0;
    count = 0;
    while (i * i < m[1])
    {
        if (m[1] % i == 0) // 최대공약수의 약수들 구하기
        {
            ans[j++] = i;
            ans[j++] = m[1] / i;
            count += 2;
        }
        i++;
    }
    if (i * i == m[1]) // 제곱 값이 있는 경우 약수 추가 
    {
        ans[j] = i;
        count++;
    }
    qsort(ans, count, sizeof(int), cmp); // 구한 약수를 오름차순 정렬
    i = 0;
    while (ans[++i])
        printf("%d ", ans[i]);
    return (0);
}
/* 참고
주어진 값 - 6 34 38
값의 차이 -  28  4
최대 공약수 -  4
공약수의 약수 - 2, 4

주어진 값 - 2  5  17
값의 차이 -  3  12
최대 공약수 -  3
공약수의 약수 - 3
*/
