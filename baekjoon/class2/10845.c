#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[10] = {0};
    int *que;
    int n;
    int i;
    int in;
    int out;
    
    scanf("%d", &n);
    que = (int *)calloc(n, sizeof(int));
    i = -1;
    in = 0;
    out = 0;
    while (++i < n)
    {
        scanf("%s", str);
        if (!strcmp(str, "push"))
            scanf("%d", &que[in++]);
        else if (!strcmp(str, "pop"))
        {
            if (in <= out)
                printf("-1\n");
            else
            {
                printf("%d\n", que[out]);
                out++;
            }
        }
        else if (!strcmp(str, "size"))
            printf("%d\n", in - out);
        else if (!strcmp(str, "empty"))
        {
            if (in <= out)
                printf("1\n");
            else
                printf("0\n");
        }
        else if (!strcmp(str, "front"))
        {
            if (in <= out)
                printf("-1\n");
            else
                printf("%d\n", que[out]);
        }
        else if (!strcmp(str, "back"))
        {
            if (in <= out)
                printf("-1\n");
            else
                printf("%d\n", que[in - 1]);
        }
    }
    return (0);
}
