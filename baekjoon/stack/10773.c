#include <stdio.h>

int main(void)
{
    int k;
    size_t stack[100001] = {0};
    int i;
    int p;
    size_t sum;
    
    scanf("%d", &k);
    i = -1;
    p = 0;
    while (++i < k)
    {
        scanf("%zu", &stack[p]);
        if (stack[p] == 0)// 입력 값이 0이면 
        {
            stack[p - 1] = 0; // 이전 값을 지우고
            p -= 1;			// 위치를 이전으로 보낸다
        }
        else	// 아니면 다음 위치로 이동
            p++;
    }
    if (p == 0) // 위치가 0이면 값이 하나도 없다
    {
        printf("0");
        return (0);
    }
    i = -1;
    sum = 0;
    while (++i < p) // 마지막 위치까지의 숫자들을 합한다
        sum += stack[i];
    printf("%zu", sum);
    return (0);
}
