#include <stdio.h>

size_t max(size_t a, size_t b)
{// 더 큰값 리턴
    if (a > b)
        return (a);
    return (b);
}

size_t min(size_t a, size_t b)
{// 더 작은값 리턴
    if (a < b)
        return (a);
    return (b);
}

size_t rec(int h[100000], int left, int right)
{
    int mid; // 중간 값
    int mid_l;// 중간부터 왼쪽으로
    int mid_r; // 중간부터 오른쪽으로
    size_t hei; // 높이
    size_t ret; // 넓이 반환 값
    
    if (left == right) // 마지막 비교 범위가 1칸일 때 리턴
        return (h[left]);
    mid = (left + right) / 2; // 분할 비교할 기준
    mid_l = mid; // 기준부터 왼쪽으로 갈 인덱스
    mid_r = mid; // 기준부터 오른쪽으로 갈 인덱스
    hei = h[mid]; // 기준위치의 높이
    ret = max(rec(h, left, mid), rec(h, mid + 1, right));
	// 분할된 왼쪽과 오른쪽 넓이 중 더 큰 값을 반환 받음
    while (left < mid_l || mid_r < right)
    { // 왼쪽과 오른쪽 중 하나라도 비교할 범위가 남아있을 때
        if (left < mid_l && (mid_r == right || h[mid_l - 1] > h[mid_r + 1]))
        {// 왼쪽의 비교 범위가 남아있고,  왼쪽의 기준 높이가 더 높을 때
            mid_l--; // 기준을 왼쪽으로 옮겨서 다시 비교
            hei = min(hei, h[mid_l]); // 높이가 더 낮은 것을 기준
        }
        else // 오른쪽 비교 범위가 남아있을 때
        {
            mid_r++;
            hei = min(hei, h[mid_r]);
        }
        ret = max(ret, hei * (mid_r - mid_l + 1));
		// 기존 넓이와 새로 구해진 넓이중 더 넓은 것을 반환
    }
    return (ret);
}

int main(void)
{
    int n;
    int h[100000] = {0};
    int i;
    
    while (42)
    {
        scanf("%d", &n);
        if (n == 0)
            break ;
        i = -1;
        while (++i < n)
            scanf("%d", &h[i]);
        printf("%zu\n", rec(h, 0, n - 1));
		// 절반씩 나누어가며 양쪽을 비교하여 넓이를 구함
    }
    return (0);
}
