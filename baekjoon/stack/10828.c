#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[10] = {0};
    int stack[10000] = {0};
    int n;
    int i;
    int p;
    
    scanf("%d", &n);
    i = -1;
    p = 0;
    while (++i < n)
    {
        scanf("%s", str);
        if (!strcmp(str, "push")) //입력 값이 push이면 숫자를 입력
            scanf("%d", &stack[p++]);
        else if (!strcmp(str, "pop")) // pop일 때
        {
            if (p == 0) // 위치가 0이면 값이 없는 상태로 -1출력
                printf("-1\n");
            else // 가장 위에 있는 값을 출력해주고 p의 위치를 이전으로 이동
            {
                printf("%d\n", stack[p - 1]);
                p--;
            }
        }
        else if (!strcmp(str, "size")) //p의 위치가 스택에 쌓인 크기
        {
            printf("%d\n", p);
        }
        else if (!strcmp(str, "empty")) // empty일 때 
        {
            if (p == 0)  // 비어있으면 1
                printf("1\n");
            else		// 비어있지 않으면 0 출력
                printf("0\n");
        }
        else if (!strcmp(str, "top")) // top일 때
        {
            if (p == 0) // 비어있으면 -1
                printf("-1\n");
            else	// 아니면 첫번째 값 출력
                printf("%d\n", stack[p - 1]);
        }
    }
    return (0);
}
