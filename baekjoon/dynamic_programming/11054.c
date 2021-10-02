#include <stdio.h>

int main(void)
{
    int arr[1001] = {0};
    int front[1001] = {0};
    int back[1001] = {0};
    int max;
    int n;
    int i;
    int j;
    
    scanf("%d", &n);
    i = -1;
    while (++i < n)
        scanf("%d", &arr[i]);
    i = 0;
    while (++i < n) // 앞에서 부터 뒤로 오름차순 확인
    {
        j = -1;
        while (++j < i)
            if (arr[i] > arr[j] && front[i] <= front[j])
                front[i] = front[j] + 1;
                //현재 값이 이전값보다 크고 오름 차순인 경우
    }
    i = n - 1;
    while (--i >= 0) // 뒤에서 부터 앞으로 오름차순 확인
    {
        j = n;
        while (--j > i)
            if (arr[i] > arr[j] && back[i] <= back[j])
                back[i] = back[j] + 1;
                // 현재 값이 뒤의 값보다 크고 내림 차순인 경우
    }
    i = -1;
    max = 0;
    while (++i < n) // 앞과 뒤에서 시작하여 만나는 지점의 최대값 확인
        if (max < front[i] + back[i] + 1)
            max = front[i] + back[i] + 1;
    printf("%d", max);
    return (0);
}
