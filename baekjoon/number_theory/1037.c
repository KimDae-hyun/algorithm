#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return (1);
    return (-1);
}
int main(void)
{
    int num[50] = {0};
    int n;
    int i;
    
    scanf("%d", &n);
    i = -1;
    while (++i < n)
        scanf("%d", &num[i]);
    qsort(num, n, sizeof(int), cmp);// 주어진 약수들의 오름차순 정렬
    printf("%d", num[0] * num[n - 1]);
	// 가장 작은 약수와 가장 큰 약수의 곱은 주어진 수
    return (0);
}
