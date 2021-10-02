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
            //교차되는 위치에서 앞의 값과 위의 값 중 큰 값 입력 
            if (s1[j] == s2[i]) // 주어진 문자가 같으면 왼쪽 위의 값 + 1;
                count[i + 1][j + 1] = count[i][j] + 1;
        }
    }
    printf("%d", count[i][j]);
    return (0);
}

/* 참고
  0 A C A Y K P
0 0 0 0 0 0 0 0
C 0 0 1 1 1 1 1 
A 0 1 1 2 2 2 2
P 0 1 1 2 2 2 3
C 0 1 2 2 2 2 3
A 0 1 2 3 3 3 3
K 0 1 2 3 3 4 4
*/