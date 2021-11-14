#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void insert(int *heap, int x, int j)
{
    int tmp;

    heap[j] = x;
    while ((j != 1) && abs(heap[j / 2]) >= abs(heap[j])) // 입력된 절댓값이 부모 노드보다 작으면
    {
        if (abs(heap[j / 2]) == abs(heap[j]) && heap[j / 2] <= heap[j]) // 절댓값은 같으나 부호의 차이가 있을 수 있다.
            break ;
        tmp = heap[j];
        heap[j] = heap[j / 2]; // 부모 노드를 자식 노드로 내린다.
        heap[j / 2] = tmp;
        j /= 2;
    }
}

void delete(int *heap, int j)
{
    int first;
    int tmp;
    int parent;
    int child;

    first = heap[1]; // 우선 순위가 가장 높은 값 = 출력될 값
    heap[1] = heap[--j]; // 가장 마지막에 입력 된 값
    parent = 1;
    child = 2;
    while (child <= j)
    {
        if ((child < j) && (abs(heap[child]) > abs(heap[child + 1]) || \
        (abs(heap[child]) == abs(heap[child + 1]) && heap[child] > heap[child + 1]))) // 왼쪽 및 오른쪽 자식 노드를 비교 하여 더 작은 자식 노드 구하기
            child++;
        if (abs(heap[parent]) < abs(heap[child])) //자식 노드가 더 크면 중단
            break ;
        if (abs(heap[parent]) == abs(heap[child]) && heap[parent] < heap[child]) // 부호가 다른 경우
            break ;
        tmp = heap[parent];
        heap[parent] = heap[child]; // 부모위치에 자식노드 입력
        heap[child] = tmp;
        parent = child; 
        child *= 2; 
    }
    heap[j] = 0; // 마지막 위치 0 초기화
    printf("%d\n", first);
}

int main(void)
{
    int *heap; // 힙 = 완전 이진트리
    int n; // 입력 개수
    int x; // 입력 값
    int i; // 입력 카운트
    int j; // 힙 인덱스

    scanf("%d", &n);
    heap = (int *)calloc(n + 1, sizeof(int));
    i = 0;
    j = 1;
    while (++i <= n)
    {
        scanf("%d", &x);
        if (x == 0) // 입력 값이 0이면 출력
        {
            delete(heap, j); // 최소 값 출력 및 제거
            if (j > 1) // 인덱스 --
                j--;
        }
        else
        {
            insert(heap, x, j); // 값 입력
            j++; // 인덱스 ++
        }
    }
    return (0);
}