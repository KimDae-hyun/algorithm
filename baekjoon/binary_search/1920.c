#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) // 오름차순 정렬
{
    if (*(int *)a > *(int *)b)
        return (1);
    return (-1);
}

int binary(int a[100000], int n, int num)
{// 이분탐색 // 배열에 num이 존재하는지 확인
    int start; // 시작 인덱스
    int end; // 마지막 인덱스
    int piv; // 기준 인덱스
    
    start = 0;
    end = n - 1;
    while (42)
    {
        piv = (start + end) / 2; // 중간 인덱스를 기준 인덱스로 잡고
        if (a[piv] == num || a[start] == num || a[end] == num)
            return (1); // 시작, 끝, 기준 값이 숫자와 같으면 1 반환
        if (a[piv] < num) // 피봇값보다 크면 시작 인덱스를 피봇 다음 위치로
            start = piv + 1;
        else // 피봇값이 작으면 끝 인덱스를 피봇값 앞으로 이동
            end = piv - 1;
        if (start >= end) // 시작과 끝 인덱스가 만나면 0리턴
            return (0);
    }
}

int main(void)
{
    int n; // 주어진 숫자 개수
    int a[100000] = {0}; // 입력될 숫자 배열
    int m; // 확인할 숫자 개수
    int num; // 확인할 숫자
    int i; 
    
    scanf("%d", &n);
    i = -1;
    while (++i < n)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp); // 입력된 숫자들을 오름차순 정렬
	// 이분 탐색을 위한 사전 정렬
    scanf("%d", &m);
    i = -1;
    while (++i < m)
    {
        scanf("%d", &num);
        printf("%d\n", binary(a, n, num)); // 이분탐색을 통한 숫자 존재여부 확인
    }
    return (0);
}
