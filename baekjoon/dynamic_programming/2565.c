#include <stdio.h>
#include <stdlib.h>

typedef struct s_line
{
    int a;
    int b;
}            t_line;

int cmp(const void *a, const void *b)
{
    if (((t_line *)a)->a > ((t_line *)b)->a)
        return (1);
    return (-1);
}

int main(void)
{
    t_line l[101];
    int n;
    int i;
    int j;
    int check;
    int count[101] = {0};

    scanf("%d", &n);
    i = -1;
    while (++i < n)
        scanf("%d %d", &l[i].a, &l[i].b);
    qsort(l, n, sizeof(t_line), cmp);
	printf("--------------\n");
	i = -1;
	while (++i < n)
		printf("%d %d\n", l[i].a, l[i].b);
	printf("--------------\n");
    i = -1;
    check = 0;
    while (++i < n)
    {
        count[i] = 1;
        j = -1;
        while (++j < i)
            if (l[i].b > l[j].b && count[i] <= count[j])
                count[i] = count[j] + 1;
        if (check <= count[i])
            check = count[i];
    }
    printf("%d", n - check);
    return (0);
}
