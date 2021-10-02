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
    int n;
    int p[1001] = {0};
    int i;
    int sum;
    
    scanf("%d", &n);
    i = -1;
    while (++i < n)
        scanf("%d", &p[i]);
    qsort(p, n, sizeof(int), cmp); //오름차순 정렬
    i = -1;
    sum = 0;
    while (++i < n)
        sum = sum + p[i] * (n - i); //합계 구하기
    printf("%d", sum);
    return (0);
}
/* 참고
5
3 1 4 3 2

1  1                 = 1
2  1 + 2             = 3
3  1 + 2 + 3         = 6
3  1 + 2 + 3 + 3     = 9
4  1 + 2 + 3 + 3 + 4 = 13

-> 1 + 3 + 6 + 9 + 13 = 32 

or

1*5 + 2*4 + 3*3 + 3*2 + 4*1 = 32
*/