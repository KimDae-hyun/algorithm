#include <stdio.h>

int main(void)
{
    char str[51] = {0};
    char cal[50] ={0};
    int num[50] = {0};
    int i;
    int j;
    int flag;
    int sum;
    
    scanf("%s", str);
    i = -1;
    j = 0;
    while (str[++i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            num[j] = num[j] * 10 + str[i] - 48;
        else
        {
            if (str[i] == '+')
                cal[j] = '+';
            else if (str[i] == '-')
                cal[j] = '-';
            j++;
        }
    }
    i = 0;
    flag = 0;
    sum = num[0];
    while (++i <= j)
    {
        if (cal[i - 1] == '-')
        {
            flag = 1;
            sum -= num[i];
        }
        else if (cal[i - 1] == '+' && flag == 0)
            sum += num[i];
        else if (cal[i - 1] == '+' && flag == 1)
            sum -= num[i];
    }
    printf("%d", sum);
    return (0);
}
