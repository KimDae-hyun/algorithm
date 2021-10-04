#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[10] = {0}; //  명령어를 입력 받을 문자열. 넉넉하게 10
    int *que; // 숫자를 담아줄 큐. 최대 2백만이라 포인터로
    int n; // 입력받을 명령어 개수
    int i; // 카운트
    int in; // 큐에 입력되는 인덱스
    int out; // 큐에서 출력되는 인덱스
    
    scanf("%d", &n);
    que = (int *)calloc(n, sizeof(int));
    i = -1;
    in = 0;
    out = 0;
    while (++i < n)
    {
        scanf("%s", str);
        if (!strcmp(str, "push")) // 명령어가 push이면 큐에 숫자 입력
            scanf("%d", &que[in++]);
        else if (!strcmp(str, "pop")) // pop이면 처음 숫자를 출력하고 제거
        {
            if (in <= out) // 입력 인덱스가 같으면 숫자가 없는 상태 
                printf("-1\n");
            else
            {
                printf("%d\n", que[out]);
                out++; // 출력된 숫자는 제거된 것이므로 인덱스++
            }
        }
        else if (!strcmp(str, "size")) // 입력, 출력 인덱스의 차이가 사이즈
            printf("%d\n", in - out);
        else if (!strcmp(str, "empty"))
        {
            if (in <= out) // 입력, 출력 인덱스가 같으면 비어있는 상태
                printf("1\n");
            else
                printf("0\n");
        }
        else if (!strcmp(str, "front")) // 가장 앞의 숫자 출력
        {
            if (in <= out)
                printf("-1\n");
            else
                printf("%d\n", que[out]);
        }
        else if (!strcmp(str, "back")) // 가장 뒤의 숫자 출력
        {
            if (in <= out)
                printf("-1\n");
            else
                printf("%d\n", que[in - 1]); // 입력받고 in++ 이므로 -1
        }
    }
    return (0);
}
