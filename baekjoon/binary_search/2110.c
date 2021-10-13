#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return (1);
    return (-1);
}

int rec(int *p, int min, int max, int n, int c, int *dis)
{
    int mid;
    int i;
    int piv;
    int count;
    
    if (min > max)// 최소거리가 최대거리를 넘어서면
        return (*dis); // 거리 반환
    mid = (min + max) / 2; // 최소거리와 최대거리의 중간 값
    piv = p[0]; // 공유기를 설치할 기준이 될 값
    count = 1; // 설치 카운트
    i = 0;
    while (++i < n)
        if (p[i] - piv >= mid)// 현재 위치와 기준의 거리가 중간값 보다 크면
        {
            piv = p[i]; // 기준값을 현재값으로 변경
            count++; // 공유기 추가 설치
        }
    if (count >= c)
    {
        *dis = mid; // 공유기를 충분히 설치할 수 있으므로 거리 조정
        min = mid + 1; // 공유기의 개수를 맞추기 위해 최소값 변경
        return (rec(p, min, max, n, c, dis));
    }
    else
    {
        max = mid - 1; // 공유기의 개수가 부족한 경우 최대값 축소
        return (rec(p, min, max, n, c, dis));
    }
}

int main(void)
{
    int *p; // 좌표
    int n; // 집의 개수
    int c; // 공유기 개수
    int min; // 제일 가까운 거리
    int max; // 제일 먼 거리
    int dis; // 구해야 할 공유기간 거리
    int i;
    
    scanf("%d %d", &n, &c);
    p = (int *)calloc(n, sizeof(int));
    i = -1;
    while (++i < n)
        scanf("%d", &p[i]);
    qsort(p, n, sizeof(int), cmp); // 좌표를 오름차순 정렬
    min = 1; // 공유기 간 가장 가까운 거리
    max = p[n - 1] - p[0]; // 공유기 간 가장 먼 거리
    dis = 0; // 구해야할 거리
    printf("%d", rec(p, min, max, n, c, &dis));
    // 최대 거리를 절반으로 나눠가며 적정거리 파악
    free(p);
    return (0);
}
