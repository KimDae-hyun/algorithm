#include <stdio.h>

int main(void)
{
    size_t len[100000] = {0};
    size_t price[100001] = {0};
    int n;
    int i;
    size_t small;
    size_t sum;
    
    scanf("%d", &n);
    i = -1;
    while (++i < n - 1)
        scanf("%zu", &len[i]);//도시간 거리
    i = -1;
    sum = 0;
    while (++i < n - 1)
    {
        scanf("%zu", &price[i]); // 리터당 가격
        if (i == 0 || small > price[i])
            small = price[i];
		// i = 0일때 small 초기화, 뒤의 가격이 더 높은 경우 앞의 주유소에서 추가 주유
        sum += small * len[i];
    }
    printf("%zu", sum);
    return (0);
}
