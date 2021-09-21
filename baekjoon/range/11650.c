#include <stdio.h>
#include <stdlib.h>

typedef struct s_num
{
    int x;
    int y;
}            t_num;

int compare(const void *a, const void *b)
{   
    t_num *num1;
    t_num *num2;
    
    num1 = (t_num *)a;
    num2 = (t_num *)b;
    if (num1->x == num2->x)
        return (num1->y - num2->y);
    return (num1->x - num2->x);
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
