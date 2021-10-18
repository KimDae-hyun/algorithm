#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    if (strcmp((char *)a, (char *)b) < 0)
        return (1);
    else if (strcmp((char *)a, (char *)b) > 0)
    	return (-1);
    else
	    return(0);
}

int main(void)
{
    char **listen;
    char **sort;
    int n;
    int m;
    int i;
    int j;
    int check;
    
    scanf("%d %d", &n, &m);
    listen = (char **)calloc(n + m + 1, sizeof(char *));
    sort = (char **)calloc(m + 1, sizeof(char *));
    i = -1;
    while (++i < n + m)
    {
        listen[i] = (char *)calloc(21, sizeof(char));
        if (i < m)
            sort[i] = (char *)calloc(21, sizeof(char));
        scanf("%s", listen[i]);
    }
    j = n + m;
    qsort(listen, j, sizeof(char *), cmp);
i = -1;
while (++i < n + m)
	printf("s %s\n", listen[i]);
    i = -1;
    j = 0;
    check = 0;
    while (++i < n + m - 1)
    {
        if (strcmp(listen[i], listen[i + 1]) == 0)
           sort[j++] = listen[i];
    }
    printf("%d\n", j);
    i = -1;
    while (++i < j)
        printf("%s\n", sort[i]);
    i = -1;
    while (++i < n)
    {
        free(listen[i]);
        if (i < m)
            free(sort[i]);
    }
    free(listen);
    free(sort);
    return (0);
}
