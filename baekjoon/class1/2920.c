#include <stdio.h>

int main()
{
    int scale[8] = {0};
    int check[7] = {0};
    int flag;
    int i;
    
    i = -1;
    while (++i < 8)
    {
        scanf("%d", &scale[i]);
        if (i >= 1)
        {
            if (scale[i] > scale [i - 1])
                check[i - 1] = 1;
            else if (scale[i] < scale [i - 1])
                check[i - 1] = -1;
        }
    }
    i = -1;
    flag = 0;
    while (++i < 6)
        if (check[i] != check[i + 1])
            flag++;
    if (flag == 0)
    {
        if (check[i] == 1)
            printf("ascending");
        else if (check[i] == -1)
            printf("descending");
    }
    else
        printf("mixed");
    return (0);
}
