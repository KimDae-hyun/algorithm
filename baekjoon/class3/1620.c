#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_pock
{
    char name[21];
    int idx;
}        t_pock;

int cmp(const void *a, const void *b) // name기준 오름차순 정렬
{
    if (strcmp(((t_pock *)a)->name, ((t_pock *)b)->name) > 0)
        return (1);
    return (-1);
}

int binary(t_pock *pock, char *pro, int start, int end) // 이분 탐색
{
    int mid;

    mid = (start + end) / 2; // 중간값
    if (strcmp(pock[mid].name, pro) == 0)
        return (pock[mid].idx); // 중간값과 같으면 인덱스리턴
    else if (strcmp(pock[mid].name, pro) < 0) // 첫값을 중간값으로 변경
        return (binary(pock, pro, mid + 1, end));
    else // 끝값을 중간값으로 변경
        return (binary(pock, pro, start, mid - 1));
}

int main(void)
{
    t_pock *pock; // 포켓몬 정보가 담길 구조체
    t_pock *sort; // 정보를 정렬할 구조체
    char *pro; // 문제를 담을 문자열
    int n;
    int m;
    int num;
    int i;
    int j;

    scanf("%d %d", &n, &m);
    pock = (t_pock *)calloc(n, sizeof(t_pock));
    sort = (t_pock *)calloc(n, sizeof(t_pock));
    pro = (char *)calloc (21, sizeof(char));
    i = -1;
    while (++i < n)
    {
        scanf("%s", pock[i].name); // 이름 입력
        pock[i].idx = i + 1; // 받아온 순서 입력
        sort[i] = pock[i]; // 정렬하기 위한 정보 입력
    }
    qsort(sort, n, sizeof(t_pock), cmp); // 정렬
    i = -1;
    while (++i < m)
    {
        num = 0;
        scanf("%s", pro);
        if (pro[0] >= '0' && pro[0] <= '9') // 숫자이면
        {
            num = atoi(pro);
            printf("%s\n", pock[num - 1].name); // 이름출력
        }
        else // 이름이면
        {
            printf("%d\n", binary(sort, pro, 0, n - 1)); // 인덱스 출력
        }
    }
    free(pro);
    free(pock);
    free(sort);
    return (0);
}
