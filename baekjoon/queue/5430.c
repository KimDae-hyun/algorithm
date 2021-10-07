#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int num;
    struct s_list *next;
    struct s_list *pre;
}            t_list;

void init(t_list **lst) //list 초기화
{
    *lst = (t_list *)calloc(1, sizeof(t_list));
    (*lst)->next = 0;
    (*lst)->pre = 0;
}

void all_free(t_list **front, t_list **back, t_list **tmp, char **str, char **num)
{ // 할당 해제
    while (*front && (*front)->next)
    {
        *tmp = (*front)->next;
        free(*front);
        *front = *tmp;
    }
    free(*front);
    free(*str);
    free(*num);
}

int main(void)
{
    t_list *front; // 리스트 처음
    t_list *back; // 리스트 마지막
    t_list *tmp; // 추가, 제거를 위한 임시 리스트
    char *str; // 받아줄 명령어
    char *num; // 받아줄 숫자
    int t; // 테스트케이스 개수
    int n; // 받을 숫자 개수
    int a; // ??
    int i; // 카운트
    int j; // n 번만큼 반복
    int k; // num배열 인덱스
    int check; // R이 되었는지 판단
    int error; // 에러 파악

    scanf("%d", &t);
    i = -1;
    while (++i < t)
    {
        init (&front);
        init(&back);
        front = 0;
        back = 0;
        str = (char *)calloc(100001, sizeof(char));
        scanf("%s", str);
        scanf("%d\n", &n);
        num = (char *)calloc((n * 4 + 3), sizeof(char));
		// n==0 일때 +3 // *4 는 숫자가 3자리수가 입력될 경우
        scanf("%s", num);
        j = 0;
        k = 0;
        while (++j <= n)
        {
            init(&tmp);
            k++;
            while (num[k] >= '0' && num[k] <= '9') // str숫자를 int로 변경
                tmp->num = (tmp->num * 10 + num[k++] - 48);
            if (front == 0)
            {
                front = tmp;
                back = tmp;
            }
            else // add_back;
            {
                while (back->next)
                    back = back->next;
                tmp->next = back->next;
                back->next = tmp;
                tmp->pre = back;
                back = tmp;
            }
        }
        j = -1;
        error = 0;
        check = 0;
        while (str[++j])
        {
            if (str[j] == 'R' && check == 0) //R 체크
            {
                check = 1; // 뒤에서부터
                continue ;
            }
            else if (str[j] == 'R' && check == 1)
            {
                check = 0; // 앞에서부터
                continue ;
            }
            if (check == 1) // 뒤에서부터 제거
            {
                if (back == 0) // 비어있을 때 D이면 에러
                {
                    printf("error\n");
                    error = 1;
                    break ;
                }
                else
                {
                    tmp = back;
                    back = tmp->pre;
                    free(tmp);
                    if (back == 0)
                        front = 0;
                    else
                        back->next = 0;
                }
            }
            else // 앞에서부터 제거
            {
                if (front == 0) // 비어있을 때 D이면 에러
                {
                    printf("error\n");
                    error = 1;
                    break ;
                }
                else
                {
                    tmp = front;
                    front = front->next;
                    free(tmp);
                    if (front == 0)
                        back = 0;
                    else
                        front->pre = 0;
                }
            }
        }
        if (error == 1) // 에러일때 할당 해제
            all_free(&front, &back, &tmp, &str, &num);
        else // 정상적으로 명령 수행 후 출력
        {
            if (check == 1) // 뒤에서 부터 출력
            {
                if (back == 0) //인자가 없을때
                {
                    printf("[]\n");
                    continue ; // 종료
                }
                printf("[");
                while(back->num)
                {
                    printf("%d", back->num);
                    if (back->pre)
                    {
                        printf(",");
                        back = back->pre;
                    }
                    else
                    {
                        printf("]\n");
                        break ;
                    }
                }
            }
            else // 앞에서부터 출력
            {
                if (front == 0) // 인자가 없을 때
                {
                    printf("[]\n");
                    continue ; // 종료
                }
                printf("[");
                while(front->num)
                {
                    printf("%d", front->num);
                    if (front->next)
                    {
                        printf(",");
                        front = front->next;
                    }
                    else
                    {
                        printf("]\n");
                        break ;
                    }
                }
            }
            all_free(&front, &back, &tmp, &str, &num);// 할당 해제
        }
    }
}
