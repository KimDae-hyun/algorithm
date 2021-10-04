#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
    int              num;
    struct s_list    *next;
    struct s_list    *pre;
}            t_list;

void init(t_list **lst)
{
    *lst = (t_list *)calloc(1, sizeof(t_list));
    (*lst)->next = 0;
    (*lst)->pre = 0;
}

int main(void)
{
    char str[15] = {0};
    t_list *tmp;
    t_list *front; // lst head
    t_list *back; // lst tail
    int n; // 명령어 수
    int i; // 카운트
    int in; // 입력 값
    int size; // 덱 크기
    
    scanf("%d", &n);
    init(&front); // 초기화
    init(&back);
    front = 0;
    back = 0;
    i = -1;
    size = 0;
    while (++i < n)
    {
        scanf("%s", str);
        if (strcmp(str, "push_back") == 0)
        {
            init(&tmp); // 새 리스트 초기화
            scanf("%d", &tmp->num);
            size++;
            if (front == 0 || back == 0) // 비어있는 경우
            {
                front = tmp;
                back = tmp;
            }
            else // lst의 끝에 추가
            {
                tmp->pre = back;
                back->next = tmp;
                back = tmp;
            }
        }
        else if (strcmp(str, "push_front") == 0)
        {
            init(&tmp); // 새 리스트 초기화
            scanf("%d", &tmp->num);
            size++;
            if (front == 0 || back == 0) // 비어있는 경우
            {
                front = tmp;
                back = tmp;
            }
            else // lst의 처음에 추가
            {
                tmp->next = front;
                front->pre = tmp;
                front = tmp;
            }
        }
        else if (strcmp(str, "pop_front") == 0)
        {
            if (front == 0 || back == 0) // 비어있는 경우
                printf("-1\n");
            else
            {
                printf("%d\n", front->num); // 처음 값을 출력
                tmp = front;
                front = tmp->next;
                free(tmp); // lst head 제거
                if (front == 0) // lst가 비어있는 경우
                    back = 0;
                else
                    front->pre = 0;
                size--;
            }
        }
        else if (strcmp(str, "pop_back") == 0)
        {   
            if (front == 0 || back == 0) // 비어있는 경우
                printf("-1\n");
            else
            {
                printf("%d\n", back->num); // 마지막값 출력
                tmp = back;
                back = tmp->pre;
                free(tmp); // lst tail 제거
                if (back == 0) // 비어있는 경우
                    front = 0;
                else
                    back->next = 0;
                size--;
            }
        }
        else if (strcmp(str, "size") == 0)
        {
            printf("%d\n", size); // size는 push에서 +1 pop에서 -1 연산
        }
        else if (strcmp(str, "empty") == 0)
        {
            if (size == 0) // 비어있는 경우
                printf("1\n");
            else
                printf("0\n");
        }
        else if (strcmp(str, "front") == 0)
        {
            if (front == 0) // front가 없는 경우
                printf("-1\n");
            else
                printf("%d\n", front->num); 
        }
        else if (strcmp(str, "back") == 0)
        {
            if (back == 0) // back이 없는 경우
                printf("-1\n");
            else
                printf("%d\n", back->num);
        }
    }
    return (0);
}
