#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_pock
{
    char name[21];
    int idx;
}        t_pock;

int cmp(const void *a, const void *b)
{
    if (((t_pock *)a)->name > ((t_pock *)b)->name)
        return (1);
    return (-1);
}

int is_digit(char *str)
{
    int i;
    
    i = -1;
    while (str[++i])
        if (str[i] < '0' || str[i] > '9')
            return (0);
    return (1);
}

int binary(t_pock *pock, char *pro, int start, int end)
{
    int mid;
    
    mid = (start + end) / 2;
    if (strcmp(pock[mid].name, pro) == 0)
        return (pock[mid].idx);
    else if (strcmp(pock[mid].name, pro) < 0)
        return (binary(pock, pro, mid + 1, end));
    else
        return (binary(pock, pro, start, mid - 1));
}

int main(void)
{
    t_pock *pock;
    char *pro;
    int n;
    int m;
    int num;
    int i;
    int j;
    
    scanf("%d %d", &n, &m);
    pock = (t_pock *)calloc(n + 1, sizeof(t_pock));
    pro = (char *)calloc (21, sizeof(char));
    i = -1;
    while (++i < n)
    {
        scanf("%s", pock[i].name);
        pock[i].idx = i + 1;
    }
    qsort(pock, n, sizeof(t_pock), cmp);
    i = -1;
    while (++i < m)
    {
        num = 0;
        scanf("%s", pro);
        if (is_digit(pro) == 1)
        {
            j = -1;
            while (pro[++j])
                num = num * 10 + pro[j] - 48;
            j = -1;
            while (++j < n)
            {
                if (pock[j].idx == num)
                {
                    printf("%s\n", pock[j].name);
                    break ;
                }
            }
        }
        else
        {
            printf("%d\n", binary(pock, pro, 0, n - 1));
        }
    }
    free(pro);
    free(pock);
    return (0);
}
