#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_dress
{
    char *name;
    char *type;
}            t_dress;

int cmp(const void *a, const void *b)
{
    return (strcmp(((t_dress *)a)->type, ((t_dress *)b)->type));
}

int main(void)
{
    t_dress *d;
    int t;
    int n;
    int i;
    int j;
    int *many;
    int sum;
    int count;
    
    scanf("%d", &t);
    i = -1;
    while (++i < t)
    {
        scanf("%d", &n);
        d = (t_dress *)calloc(n + 1, sizeof(t_dress));
        many = (int *)calloc(n, sizeof(int));
        j = -1;
        while (++j < n)
        {
            d[j].name = (char *)calloc(21, sizeof(char));
            d[j].type = (char *)calloc(21, sizeof(char));
            scanf("%s %s", d[j].name, d[j].type);
        }
        qsort(d, n, sizeof(t_dress), cmp);// 의상의 종류별로 정렬
        j = -1;
        count = 1;
        while (++j < n) // 의상 종류별 개수 파악
        {
            many[count - 1]++; 
            if (d[j + 1].type == 0)
                break ;
            if (strcmp(d[j].type, d[j + 1].type))
                count++;
        }
        j = -1;
        sum = 1;
        while (++j < count) // 의상의 조합 확인(입지 않은 경우 추가)
            sum *= (many[j] + 1);
        printf("%d\n", sum - 1); // 아무것도 입지 않은 경우는 제외
        j = -1;
        while (++j < n)
        {
            free(d[j].name);
            free(d[j].type);
        }
        free(d);
        free(many);
    }
    return (0);
}
