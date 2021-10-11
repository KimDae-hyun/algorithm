#include <stdio.h>
#include <stdlib.h>

int binary(int *tree, int n, int m, int low, int high, int *len)
{
    int piv;
    int i;
    size_t sum; // 가져가는 나무의 합
    
    if (low > high)
        return (*len);
    piv = (low + high) / 2; 
    i = -1;
    sum = 0;
    while (++i < n)
        if(tree[i] > piv) // 나무가 자르는 길이보다 긴 경우만 자름 
            sum += tree[i] - piv;
    if (sum >= m) // 필요한 길이보다 길거나 같은 경우
    {
        *len = piv; // 가져갈 길이 저장
        return (binary(tree, n, m, piv + 1, high, len)); // 더 높은 위치 절단
    }
    else // 필요한 길이보다 짧은 경우
        return (binary(tree, n, m, low, piv - 1, len)); // 더 낮은 위치 절단
}

int main(void)
{
    int n;
    int m;
    int *tree;
    int i;
    int max;
    int len;
    
    scanf("%d %d", &n, &m);
    tree = (int *)calloc(n, sizeof(int));
    i = -1;
    max = 0;
    while (++i < n)
    {
        scanf("%d", &tree[i]);
        if (max < tree[i]) // 나무 중에서 최대값
            max = tree[i];
    }
    len = 0;
    printf("%d", binary(tree, n, m, 0, max, &len));
	//이분탐색으로 자를 높이 구하기
	free(tree);
    return (0);
}
