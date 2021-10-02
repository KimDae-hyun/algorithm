#include <stdio.h>

int main(void)
{
    int coin[11] = {0};
    int n;
    int k;
    int i;
    int count;
    
    scanf("%d %d", &n, &k);
    i = -1;
    while (++i < n)
        scanf("%d", &coin[i]);
    i = n - 1; // 큰 값부터 시작
    count = 0;
    while (k > 0 && i >= 0) // k에서 동전의 값을 빼면서 확인 
    {
        if (coin[i] > k) // 필요한 값보다 동전의 값이 더 크면 더 작은 동전
            i--;
        else 
        {
            count++; // 동전 개수 추가
            k -= coin[i]; // 필요한 값에서 동전 값을 빼기
        }
    }
    printf("%d", count);
    return (0);
}
