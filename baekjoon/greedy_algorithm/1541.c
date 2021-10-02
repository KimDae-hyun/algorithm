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
    while (str[++i]) // 숫자와 기호 구분
    {
        if (str[i] >= '0' && str[i] <= '9')// 숫자는 int배열
            num[j] = num[j] * 10 + str[i] - 48;
        else // '+', '-'는 char 배열
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
        if (cal[i - 1] == '-') // '-'가 나오면 뒤의 값은 빼기
        {
            flag = 1;
            sum -= num[i];
        }
        else if (cal[i - 1] == '+' && flag == 0)
            sum += num[i]; // '-'가 나오지 않은 경우 항상 더하기
        else if (cal[i - 1] == '+' && flag == 1) 
            sum -= num[i]; // 한번이라도 -가 나온 경우 빼기
    }
    printf("%d", sum);
    return (0);
}
/* 참고
입력값
 1 + 2 - 3 + 4 - 5 + 6 - 7 + 8 + 9 - 10
최소값
 1 + 2 - (3 + 4) - (5 + 6) - (7 + 8 + 9) - 10
*/