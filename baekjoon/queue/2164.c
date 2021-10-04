#include <stdio.h>

int main(void)
{
    int n;
    int que[500001] = {0}; // 카드를 담아줄 큐
    int i; // 큐 인덱스
    int front; // 큐 끝에서부터 담길 인덱스
    
    scanf("%d", &n);
    if (n == 1 || n == 2) // 1과 2인 경우 빠른 출력
    {
        if (n == 1)
            printf("1");
        else
            printf("2");
        return (0);
    }
    i = 2;
    while (i <= n) // 처음 큐에는 짝수만 입력
    {
        que[i / 2 - 1] = i;
        i += 2;
    }
    if (n % 2 == 0) // 입력값이 짝수이면 담겨져 있는 처음 카드는 버리고 시작
        i = 1;
    else // 입력값이 홀수이면 담겨져있는 카드를 뒤로 넘기면서 시작
        i = 0;
    front = n / 2; // 넘어오는 카드는 큐의 마지막 위치로
    while (i <= n - 2) // 최대 위치의 -1 의 인덱스까지 진행
    {
        que[front++] = que[i];
        i += 2;
    }
    if (que[front] == 0)
        printf("%d", que[front - 1]);
    else
        printf("%d", que[front]);
    return (0);
}
