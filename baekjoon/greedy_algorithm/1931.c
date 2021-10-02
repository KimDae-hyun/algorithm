#include <stdio.h>
#include <stdlib.h>

typedef struct s_time
{
    int start;
    int end;
}                t_time;

int cmp(const void *a, const void *b)
{
    if (((t_time *)a)->end != ((t_time *)b)->end)
    {
        if (((t_time *)a)->end > ((t_time *)b)->end)
            return (1);
        else if (((t_time *)a)->end == ((t_time *)b)->end)
            return (0);
        else
            return (-1);
    }
    else
    {
        if (((t_time *)a)->start > ((t_time *)b)->start)
            return (1);
        else if (((t_time *)a)->start == ((t_time *)b)->start)
            return (0);
        else
            return (-1);
    }
}

int main(void)
{
    t_time *t;
    int n;
    int i;
    int last;
    int count;
    
    scanf("%d", &n);
    t = (t_time *)malloc(sizeof(t_time) * n);
    i = -1;
    while (++i < n)
        scanf("%d %d", &t[i].start, &t[i].end);
    qsort(t, n, sizeof(t_time), cmp);
    // 끝나는 시간이 빠른 순으로 정렬, 같으면 시작 시간이 빠른 순으로 정렬
    i = -1;
    last = 0;
    count = 0;
    while (++i < n)
    {
        if (t[i].start >= last) // 이전 종료시간 이후 시작되는 회의
        {
            last = t[i].end; // 끝나는 시간 저장
            count++; // 회의 개수
        }
    }
    printf("%d", count);
    free(t);
    return (0);
}