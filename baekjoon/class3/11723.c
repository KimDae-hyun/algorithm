#include <stdio.h>
#include <string.h>

int main(void)
{
    char ord[10] = {0};
    int s[20] = {0};
    int m;
    int x;
    int i;
    int j;
    
    scanf("%d", &m);
    i = -1;
    while (++i < m)
    {
        scanf("%s", ord);
        if (strcmp("add", ord) == 0)
        {
            scanf("%d", &x);
            s[x - 1] = x;
        }
        else if (strcmp("remove", ord) == 0)
        {
            scanf("%d", &x);
            s[x - 1] = 0;
        }
        else if (strcmp("check", ord) == 0)
        {
            scanf("%d", &x);
            if (s[x - 1] != 0)
                printf("1\n");
            else
                printf("0\n");
        }
        else if (strcmp("toggle", ord) == 0)
        {
            scanf("%d", &x);
            if (s[x - 1] != 0)
                s[x - 1] = 0;
            else
                s[x - 1] = x;
        }
        else if (strcmp("all", ord) == 0)
        {
            j = -1;
            while (++j < 20)
                s[j] = j + 1;
        }
        else if (strcmp("empty", ord) == 0)
        {
            j = -1;
            while (++j < 20)
                s[j] = 0;
        }
    }
    return (0);
}
