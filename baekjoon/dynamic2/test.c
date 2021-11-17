#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    if (*(int *)a < *(int *)b)
        return (1);
    return (-1);
}

int main(void)
{
	int *num;
    int t;
    int k;
    int i;
    int j;

    scanf("%d", &t);
    i = -1;
    while (++i < t)
    {
        scanf("%d", &k);
        num = (int *)calloc(k, sizeof(int));
        j = -1;
        while (++j < k)
            scanf("%d", &num[j]);
        qsort(num, k, sizeof(int), cmp);
        j = -1;
        while (++j < k)
            printf("%d ", num[j]);
        printf("\n");
    }
}

133 53 38 19 10 8 6 1
186 57 18 7
243 25 268
= 1072

4 7 9 10 31 42 67 98
11 19 73 165
30 238 268
= 1072

99 38 35 25 25 22 19 5
137 60 47 24
197 71 268
= 1072

4 7 9 10
11 19
30
44 38 53 133
82 186 268
= 894

4 7 11 15 20 25 30
44 61 83 104 136 171 269
= 980

4 7 9
11 14 19 38 53 133
25 57
82 186 268
= 906

4 7 9 10
11 19
30 31 42 67
61 109 170 268
= 838

22 7 40 9 8   35 49
29 49 106 84
78 190 268
= 974
7 9 8
22 12   17  35 49
42 52  84
94 182 276
= 865