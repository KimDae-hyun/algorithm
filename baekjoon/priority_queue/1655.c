#include <stdio.h>
#include <stdlib.h>

void swap(int *heap, int a, int b)
{
    int tmp;

    tmp = heap[a];
    heap[a] = heap[b];
    heap[b] = tmp;
}

void min_insert(int *heap, int x, int j)
{
    heap[j] = x;
    while (j > 1 && heap[j / 2] > heap[j]) // 입력값이 부모 노드보다 작으면
    {
        swap(heap, j, j / 2); // 부모 노드를 자식 노드로 내린다.
        j /= 2;
    }
}

void max_insert(int *heap, int x, int j)
{
    heap[j] = x;
    while (j > 1 && heap[j / 2] < heap[j]) // 입력값이 부모 노드보다 작으면
    {
        swap(heap, j, j / 2); // 부모 노드를 자식 노드로 내린다.
        j /= 2;
    }
}

void min_sort(int *heap, int size)
{
    int parent;
    int child;

    parent = 1;
    child = 2;
    while (child <= size)
    {
        if ((child < size) && heap[child] > heap[child + 1]) // 자식 노드 중 더 작은 값을 기준
            child++;
        if (heap[parent] <= heap[child]) // 자식이 부모 노드 보다 크거나 같으면 종료
            break ;

        swap(heap, parent, child); // 부모 자식 노드 교체
        parent = child;
        child *= 2;
    }
}

void max_sort(int *heap, int size)
{
    int parent;
    int child;

    parent = 1;
    child = 2;
    while (child <= size)
    {
        if ((child < size) && heap[child] < heap[child + 1]) // 자식 노드 중 더 큰 값을 기준
            child++;
        if (heap[parent] >= heap[child]) // 자식이 부모 노드 보다 작거나 같으면 종료
            break ;

        swap(heap, parent, child); // 부모 자식 노드 교체
        parent = child;
        child *= 2;
    }
}

int main(void)
{
    int *min_h; // 최소힙
    int *max_h; // 최대힙
    int n; // 입력 개수
    int x; // 입력 값
    int i; // 입력 카운트
    int tmp;
    int min; // 작은 값 인덱스
    int max; // 큰 값 인덱스

    scanf("%d", &n);
    min_h = (int *)calloc(n + 1, sizeof(int));
    max_h = (int *)calloc(n + 1, sizeof(int));
    i = 0;
    min = 1;
    max = 1;
    while (++i <= n)
    {
        scanf("%d", &x);
        if (min == max) // 최소 힙, 최대 힙 개수가 같으면 최대힙에 추가
            max_insert(max_h, x, max++);
        else
            min_insert(min_h, x, min++); // 값 입력

        if (min > 1 && max > 1 && max_h[1] > min_h[1]) 
        {// 최대, 최소힙 최상위 값을 비교, max_h가 크면 min_h와 교체
            tmp = max_h[1];
            max_h[1] = min_h[1];
            min_h[1] = tmp;

            min_sort(min_h, min - 1); // 최소힙 재정ls렬
            max_sort(max_h, max - 1); // 최대힙 재정렬
        }
        printf("%d\n", max_h[1]); // 최대힙 최상위 값 출력
    }
    return (0);
}