#include <stdio.h>

int main()
{
    char str[11] = {0};
    char tmp;
    int i;
    int j;
    int len;
    
    scanf("%s", str);
    len = -1;
    while (str[++len])
        ;
    i = -1;
    while (++i < len)
    {
        j = i;
        while (++j < len)
        {
            if (str[i] < str[j])
            {
                tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }
    i = -1;
    while (++i < len)
        printf("%d", str[i] - 48);
    return (0);
}
