#include <stdio.h>
#include <stdlib.h>

void insert(int *heap, int x, int j)
{
    while ((j != 1) && heap[j / 2] < x) // 입력값이 부모 노드보다 크면
    {
        heap[j] = heap[j / 2]; // 부모 노드를 자식 노드로 내린다.
        j /= 2;
    }
    heap[j] = x;
}

void delete(int *heap, int j)
{
    int first;
    int tmp;
    int parent;
    int child;

    first = heap[1]; // 우선 순위가 가장 높은 값 = 출력될 값
    tmp = heap[--j]; // 가장 마지막에 입력 된 값
    parent = 1;
    child = 2;
    while (child <= j)
    {
        if ((child < j) && heap[child] < heap[child + 1]) // 왼쪽 및 오른쪽 자식 노드를 비교 하여 더 큰 자식 노드 구하기
            child++;
        if (tmp >= heap[child]) // 마지막 값과 동일 숫자 => 부모를 제외하고 현재 자식 노드부터 끝까지 모두 작거나 같은 숫자 
            break ;
        
        heap[parent] = heap[child]; // 부모위치에 자식노드 입력
        parent = child; 
        child *= 2; 
    }
    heap[parent] = tmp; // 마지막 인덱스 위치 값 수정
    heap[j] = 0; // 마지막 위치 0 초기화
    printf("%d\n", first);
}

int main(void)
{
    int *heap; // 힙 = 완전 이진트리, 최대힙 구현
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
            delete(heap, j); // 최대 값 출력 및 제거
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