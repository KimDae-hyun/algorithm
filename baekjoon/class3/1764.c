#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    if (strcmp(*(char **)a, *(char **)b) > 0)
        return (1);
    return (0);
}

int main(void)
{
    char **listen;// 모든 문자열을 받아줄 배열
    char **sort; // 듣도 보도 못한 문자열
    int n; // 듣도 못한 사람 수
    int m; // 보도 못한 사람 수
    int i;
    int j;

    scanf("%d %d", &n, &m);
    listen = (char **)calloc(n + m + 1, sizeof(char *));
    sort = (char **)calloc(m + 1, sizeof(char *));
    i = -1;
    while (++i < n + m) // 듣도 보도 못한 모든 사람
    {
        listen[i] = (char *)calloc(21, sizeof(char));
        scanf("%s", listen[i]);
    }
    qsort(listen, n + m, sizeof(char *), cmp); // 정렬
    i = -1;
    j = 0;
    while (++i < n + m - 1)
    {
        if (strcmp(listen[i], listen[i + 1]) == 0)
        { //같다면 듣도 보도 못한 사람
            sort[j] = (char *)calloc(21, sizeof(char));
            sort[j++] = listen[i];
        }
    }
    printf("%d\n", j); // 듣보잡 수 출력
    qsort(sort, j, sizeof(char *), cmp);
    i = -1;
    while (++i < j)
        printf("%s\n", sort[i]);// 듣보잡 명단 출력
/*    i = -1;
    while (++i < n + m)
    {
        free(listen[i]);
        if (i < j)
            free(sort[i]);
    }
    free(sort);
    free(listen);*/
    return (0);
}

//gcc에서는 이중프리 에러가 없지만, 백준에서 이중프리로 런타임 에러 발생
