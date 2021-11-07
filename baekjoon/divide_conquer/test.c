#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_point
{
	int x;
	int y;
}            t_point;

int find(t_point *t, int start, int end, int *min, int flag);

int cmp(const void *a, const void *b)
{
	return ((*(t_point *)a).x - (*(t_point *)b).x);
}

int dist(t_point *t, int start, int end)
{
	return ((t[end].x - t[start].x) * (t[end].x - t[start].x) \
			+ (t[end].y - t[start].y) * (t[end].y - t[start].y));
}

int y_find(t_point *t, int start, int end, int *min)
{
	int i;
	int size;
	t_point *y;

	size = end - start + 1;
	if (size <= 3 || *min == 0)
		return (*min);
	y = (t_point *)calloc(size, sizeof(t_point));
	i = -1;
	while (++i < size)
	{
		y[i].y = t[start].x;
		y[i].x = t[start++].y;
	}
	qsort(y, size, sizeof(t_point), cmp);
	*min = find(y, 0, size - 1, min, 1);
    free(y);
	return (*min);
}

int find(t_point *t, int start, int end, int *min, int flag)
{
	int i;
	int j;
	int d;
	int mid;

	if (*min == 0)
		return (0);
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
	d = find(t, start, mid, min, flag);
	if (d < *min)
		*min = d;
	d = find(t, mid, end, min, flag);
	if (d < *min)
		*min = d;
	if (*min == 0)
		return (0);

	if (flag == 1)
	{
		if (((t[mid].x - t[start].x) * (t[mid].x - t[start].x) <= *min) && \
		 ((t[end].x - t[mid].x) * (t[end].x - t[mid].x) <= *min))
		{
			i = start - 1;
			while (++i < mid + 1)
			{
				j = mid;
				while (++j <= end)
				{
					d = dist(t, i, j);
					if (d < *min)
						*min = d;
				}
			}
			return (*min);
		}
		if ((t[mid].x - t[start].x) * (t[mid].x - t[start].x) <= *min)
		{
			i = start - 1;
			while (++i < mid + 1)
			{
				j = mid + 1;
				while ((t[j].x - t[mid].x) * (t[j].x - t[mid].x) <= *min)
				{
					d = dist(t, i, j);
					if (d < *min)
						*min = d;
					if (j++ == end)
						break ;
				}
			}
		}
		if ((t[end].x - t[mid].x) * (t[end].x - t[mid].x) <= *min)
		{
			i = mid - 1;
			while ((t[mid].x - t[i].x) * (t[mid].x - t[i].x) <= *min)
			{
				j = mid - 1;
				while (++j <= end)
				{
					d = dist(t, i, j);
					if (d < *min)
						*min = d;
				}
				if (i-- == start)
					break ;
			}
		}
		return (*min);
	}
	if (((t[mid].x - t[start].x) <= *min) && \
		 ((t[end].x - t[mid].x) <= *min))
	{
		d = y_find(t, start, end, min);
		if (d < *min)
			*min = d;
		if (*min == 0)
			return (0);
	}
	else
	{
		if ((t[mid].x - t[start].x) * (t[mid].x - t[start].x)  <= *min)
		{
			i = mid + 1;
			while ((t[i].x - t[mid].x) * (t[i].x - t[mid].x) <= *min)
				if (i++ == end)
					break ;
			d = y_find(t, start, i, min);
			if (d < *min)
				*min = d;
			if (*min == 0)
				return (0);
		}
		if ((t[end].x - t[mid].x) * (t[end].x - t[mid].x) <= *min)
		{
			i = mid - 1;
			while ((t[mid].x - t[i].x) * (t[mid].x - t[i].x) <= *min)
				if (i-- == start)
					break ;
			d = y_find(t, i, end, min);
			if (d < *min)
				*min = d;
			if (*min == 0)
				return (0);
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
	min = dist(t, 0, n - 1);
	printf("%d\n", find(t, 0, n - 1, &min, 0));
	return (0);
}
