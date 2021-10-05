#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int num;
    struct s_list *next;
    struct s_list *pre;
}            t_list;

void init(t_list **lst)
{
    *lst = (t_list *)calloc(1, sizeof(t_list));
    (*lst)->next = 0;
    (*lst)->pre = 0;
}

void all_free(t_list **front, t_list **back, t_list **tmp, char **str, char **num)
{
    while ((*front)->next)
    {
        *tmp = (*front)->next;
        free(*front);
        *front = *tmp;
    }
    free(*front);
    free(*back);
    free(*tmp);
    free(*str);
    free(*num);
}

int main(void)
{
    t_list *front;
    t_list *back;
    t_list *tmp;
    char *str;
    char *num;
    int t;
    int n;
    int a;
    int i;
    int j;
    int check;
    int error;
    
    scanf("%d", &t);
    i = -1;
    while (++i < t)
    {
        init (&front);
        init(&back);
        front = 0;
        back = 0;
        scanf("%s", str);
        scanf("%d", &n);
        scanf("%s", num);
        str = (char *)calloc(100001, sizeof(char));
        num = (char *)calloc((n * 2 + 3), sizeof(char));
        j = 0;
        while (++j <= n)
        {
            init(&tmp);
            tmp->num = num[j * 2 - 1] - 48;
            if (front == 0)
            {
                front = tmp;
                back = tmp;
            }
            else
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
        while (str[++j])
        {    
            if (str[j++] == 'R' && check == 0)
                check = 1;
            else if (str[j++] == 'R' && check == 1)
                check = 0;
            if (check == 1)
            {
                if (back == 0)
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
            else
            {
                if (front == 0)
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
        if (error == 1)
            all_free(&front, &back, &tmp, &str, &num);
        else
        {
            if (check == 1)
            {
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
                        printf("]\n");                
                }
            }
            else
            {
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
                        printf("]\n");                
                }
            }
            all_free(&front, &back, &tmp, &str, &num);
        }
    }
}
