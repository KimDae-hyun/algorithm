#include <stdio.h>

int main(void)
{
    char n[6] = {0};
    int i;
    int len;
    
    while (42)
    {
        scanf("%s", n);
        if (n[0] == '0')
            return (0);
        i = -1;
        len = 0;
        while (n[++i])
            len++;
        i = -1;
        while (++i < len)
        {
            if (n[i] != n[len - i - 1])
            {
                printf("no\n");
                break ;
            }
        }
        if (i == len)
            printf("yes\n");
    }
    return (0);
}
