#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_point
{
    int x;
    int y;
}            t_point;

int cmp(const void *a, const void *b)
{
    if ((*(t_point *)a).x > (*(t_point *)b).x)
        return (1);
    else if ((*(t_point *)a).x == (*(t_point *)b).x)
    {
        if ((*(t_point *)a).y > (*(t_point *)b).y)
            return (1);
    }
    return (0);
}

int dist(t_point *t, int start, int end)
{
    return ((t[end].x - t[start].x) * (t[end].x - t[start].x) \
     + (t[end].y - t[start].y) * (t[end].y - t[start].y));
}

int find(t_point *t, int start, int end, int *min)
{
    int i;
    int j;
    int d;
    int mid;
    
    if (end - start <= 2)
    {
        i = start - 1;
        while (++i < end)
        {
            j = i;
            while (++j <= end)
            {
                d = dist(t, i, j);
                if (d < *min)
                    *min = d;
            }
        }
        return (*min);
    }
    mid = (start + end) / 2;
    find(t, start, mid, min);
    find(t, mid, end, min);
    if (end - start >= 2)
    {
        i = mid - 2;
        while (++i < mid + 1)
        {
            j = i;
            while (++j <= mid + 1)
            {
                d = dist(t, i, j);
                if (d < *min)
                    *min = d;
            }
        }
    }
    return (*min);
}

int main(void)
{
    t_point *t;
    int n;
    int i;
    int min;
    
    scanf("%d", &n);
    t = (t_point *)calloc(n, sizeof(t_point));
    i = -1;
    while (++i < n)
        scanf("%d %d", &(t[i].x), &(t[i].y));
    qsort(t, n, sizeof(t_point), cmp);
        i = -1;
    while (++i < n)
        printf("%d %d\n", t[i].x, t[i].y);
    min = dist(t, 0, 1);
    printf("%d\n", find(t, 0, n - 1, &min));
    return (0);
}