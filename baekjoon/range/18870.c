#include <stdio.h>
#include <stdlib.h>

typedef struct s_num
{
    int num;
    int idx;
}            t_num;

int num_cmp(const void *a, const void *b)
{
	return (((t_num *)a)->num - ((t_num *)b)->num);
}
            
int idx_cmp(const void *a, const void *b)
{
	return (((t_num *)a)->idx - ((t_num *)b)->idx);
}
            
void rem(t_num *num, int **tmp, int n)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < n - 1)
	{
		if (num[i].num < num[i + 1].num)
		{
			j++;
			(*tmp)[j] = num[i].num;
            num[i].num = j;
		}
        else if (num[i].num == num[i + 1].num)
        {
            num[i].num = j + 1;
        }
		if (i + 1 == n - 1)
        {
			(*tmp)[++j] = num[++i].num;
            num[i].num = j;
        }
	}
	return ;
}

int main()
{
    t_num num[1000000];
    int *sort;   
	int n;
	int i;
	int j;
	int count;

	scanf("%d", &n);
	sort = (int *)malloc(sizeof(int) * n);
	i = -1;
	while (++i < n)
	{
		scanf("%d", &(num[i].num));
		num[i].idx = i;
	}
    if (n == 1)
    {
        printf("0");
        return (0);
    }
	qsort(num, n, sizeof(t_num), num_cmp);
    rem(num, &sort, n);
    qsort(num, n, sizeof(t_num), idx_cmp);
	i = -1;
	while (++i < n)
    {
        printf("%d", num[i].num);
        if (i < n -1)
            printf(" ");
    }
	return (0);
}
