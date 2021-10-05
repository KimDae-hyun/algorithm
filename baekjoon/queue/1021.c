#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_list
{
    int num;
    struct s_list *next;
    struct s_list *pre;
}            t_list;

void init(t_list **lst) // list 할당 및 초기화
{
    *lst = (t_list *)calloc(1, sizeof(t_list));
    (*lst)->next = 0;
    (*lst)->pre = 0;
}

void btof(t_list **front, t_list **back)// back을 front로 가져오는 함수
{
    (*front)->pre = *back;
    (*back)->next = *front;
    *front = *back;
    *back = (*back)->pre;
    (*back)->next = 0;
    (*front)->pre = 0;
}

void ftob(t_list **front, t_list **back) // front를 back으로 보내는 함수
{
    (*back)->next = *front;
    (*front)->pre = *back;
    *back = *front;
    *front = (*front)->next;
    (*front)->pre = 0;
    (*back)->next = 0;
}

int cmp(t_list *front, int c, int size)
{ // 찾는 값(c = cir)이 front에 가까우면 -1, back에 가까우면 1 반환
    int i;
    int j;
    
    i = 0;
    while (front->num != c)
    {
        front = front->next;
        i++;
    }
    if (i > size - i)
        return (1);
    else
        return (-1);
}

int main(void)
{
    t_list *front; // list 처음
    t_list *back; // list 마지막
    t_list *tmp;
    int cir[50] = {0}; //입력 값을 받을 배열
    int n; // 주어진 크기
    int m; // 출력해줄 숫자 개수
    int i; // 카운트 및 cir인덱스
    int size; // 남은 큐 크기
    int check; // 찾는 값의 거리 확인
    int count; // 연산 횟수

    scanf("%d %d", &n, &m);
    init(&front);
    init(&back);
    front = 0;
    back = 0;
    size = 0;
    i = -1;
    while (++i < n) // 리스트에 1 ~ n번째까지 숫자 담아주기
    {
        init(&tmp);
        size++;
        tmp->num = size;
        if (front == 0) // 아무것도 없을 때 초기화
        {
            front = tmp;
            back = tmp;
        }
        else // list의 back에 추가
        {
            while (front->next)
                front = front->next;
            tmp->next = front->next;
            front->next = tmp;
            tmp->pre = front;
            back = tmp;
        }
    }
    while (front->pre) // 뒤로 밀려간 front를 맨 앞으로
        front = front->pre;
    i = -1;
    count = 0;
    while (++i < m) // 숫자 m개를 출력할 때까지 while
    {
        scanf("%d", &cir[i]); // 찾을 값 입력받기
        while (42)
        {
            if (front->num == cir[i]) // 찾는 값이 제일 앞에 있을때 제거
            {
                tmp = front;
                front = tmp->next;
                free(tmp);
                size--;
                break ;
            }
            check = cmp(front, cir[i], size); // 찾는 값의 위치 확인
            if (check == 1) // 찾는 값이 back에 더 가까운 경우
            {
                while (front->num != cir[i])
                {// 찾는값이 front에 있을 때까지 back을 front로 이동
                    btof(&front, &back);
                    count++;
                }
            }
            else // 찾는값이 front에 더 까까울 때
            {
                while (front->num != cir[i])
                {// 찾는 값이 front에 있을 때까지 front를 back으로 이동
                    ftob(&front, &back);
                    count++;
                }
            }
        }
    }
    printf("%d", count);
    return (0);
}
