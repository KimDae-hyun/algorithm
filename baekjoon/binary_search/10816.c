#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)// 오름차순 정렬
        return (1);
    return (-1);
}

int now(int *a, int num, int n)
{// 현재 값의 처음 인덱스 찾는 함수
    int start;
    int end;
    int piv;
    int i;
    
    start = 0;
    end = n - 1;
    while (42)
    {
        piv = (start + end) / 2; // 기준위치
        if (a[piv] < num) // 기준위치보다 찾는 숫자가 크면 시작위치를 바꿈
            start = piv + 1; 
        else // 기준위치보다 찾는 숫자가 작거나 같으면 끝 위치를 바꿈
            end = piv;
        if (start >= end) // 종료 조건
            return (end);
    }
}

int next(int *a, int num, int n)
{// 현재값보다 큰 다음값의 인덱스를 찾는 함수
    int start;
    int end;
    int piv;
    int i;
    
    start = 0;
    end = n - 1;
    while (42)
    {
        piv = (start + end) / 2; // 기준위치
        if (a[piv] > num) // 기준위치보다 찾는 숫자가 작으면 끝위치를 바꿈
            end = piv;
        else // 기준위치보다 찾는 숫자가 크거나 같으면 시작위치를 바꿈
            start = piv + 1;
        if (start >= end)// 종료 조건
        {
            if (end == n - 1 && a[n - 1] == num)
                return (n); // 마지막 값과 찾는 숫자가 같으면 다음 인덱스 반환
            else
                return (end);
        }
    }
}

int main(void)
{
    int n;
    int *a;
    int m;
    int num;
    int i;
    
    scanf("%d", &n);
    a = (int *)calloc(n, sizeof(int));
    i = -1;
    while (++i < n)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp); //이분정렬을 위한 오름차순 정렬
    scanf("%d", &m);
    i = -1;
    while (++i < m)
    {
        scanf("%d", &num);
        printf("%d ", next(a, num, n) - now(a, num, n));
		// (다음숫자 인덱스) - (현재 숫자의 시작 인덱스) = (현재 숫자의 개수)
    }
    free(a);
    return (0);
}
