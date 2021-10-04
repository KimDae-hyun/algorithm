#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return (-1); // 내림차순 정렬
    return (1);
}

int main(void)
{
    int *que; // 큐
    int *max; // 최대값 배열
    int t; // 테스트케이스
    int n; // 문서개수
    int m; // 궁금한 문서 위치
    int i; // 카운트
    int j; // 큐의 마지막 인덱스 (입력될 위치)
    int k; // 큐의 첫 인덱스(뒤로 보내줄 위치)
    int a; // 최대값 인덱스
    
    scanf("%d", &t);
    i = -1;
    while (++i < t)
    {
        a = 0;
        scanf("%d %d", &n, &m);
        que = (int *)calloc(5050, sizeof(int));// 100 ~ 1번까지 최대 사이즈
        max = (int *)calloc(100, sizeof(int)); // 최대 100개 중요도 저장
        j = -1;
        while (++j < n)
        {
            scanf("%d", &que[j]);
            max[j] = que[j];
        }
        qsort(max, n, sizeof(int), cmp); // 중요도 내림차순 저장
        k = 0;
        while (k <= j) // 시작과 끝의 인덱스가 같아지면 종료
        {
            if (que[k] < max[a]) // 현재의 중요도가 최대값 보다 작으면 
            {
                if (k == m) // 찾을 문서가 중요도가 낮은 경우 위치 파악
                    m += (n - a);
                que[j++] = que[k++]; // 큐의 마지막으로 이동
            }
            else // 현재 중요도가 최대값인 경우 
            {
                if (k == m) // 찾는 문서인 경우 출력
                {
                    printf("%d\n", a + 1);
                    break ;
                }
                que[k++] = 0; // 찾는 문서가 아닌경우 다음 최대값과 비교
                max[a++] = 0;
            }
        }
        free(que);
        free(max);
    }
    return (0);
}
