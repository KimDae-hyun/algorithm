#include <stdio.h>

int main(void)
{
    int num[3];
    int tmp;

    scanf("%d %d %d", &num[0], &num[1], &num[2]);
    if (num[0] > num[1])
    {
        tmp = num[0];
        num[0] = num[1];
        num[1] = tmp;
    }
    if (num [0] > num [2])
    {
        tmp = num[0];
        num[0] = num[2];
        num[2] = tmp;
    }
    if (num [1] > num [2])
    {
        tmp = num[1];
        num[1] = num[2];
        num[2] = tmp;
    }
    printf("%d", num[1]);
    return (0);
}