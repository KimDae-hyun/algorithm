#include <stdio.h>

int cmp(int a, int b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

int main(void)
{
    char s1[1001] = {0};
    char s2[1001] = {0};
    int i;
    int j;
    int count[1001][1001] = {0};
    
    scanf("%s", s1);
    scanf("%s", s2);
    i = -1;
    while (s2[++i])
    {
        j = -1;
        while (s1[++j])
        {
            count[i + 1][j + 1] = cmp(count[i][j + 1], count[i + 1][j]);
            if (s1[j] == s2[i])
                count[i + 1][j + 1] = count[i][j] + 1;
        }
    }
    printf("%d", count[i][j]);
    return (0);
}
