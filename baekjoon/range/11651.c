#include <stdio.h>
#include <stdlib.h>

typedef struct s_num
{
    int x;
    int y;
}            t_num;

int compare(const void *a, const void *b)
{   
    if (((t_num *)a)->y == ((t_num *)b)->y)
        return (((t_num *)a)->x - ((t_num *)b)->x);
    return (((t_num *)a)->y - ((t_num *)b)->y);
}

int main()
{
    t_num num[100000];
    int n;
    int x;
    int y;
    int i;
    
    scanf("%d", &n);
    i = -1;
    while (++i < n)
        scanf("%d %d", &num[i].x, &num[i].y);
    qsort(num, n, sizeof(t_num), compare);
    i = -1;
    while (++i < n)
        printf("%d %d\n", num[i].x, num[i].y);
    return (0);
}
