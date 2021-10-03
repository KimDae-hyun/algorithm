#include <stdio.h>

int main(void)
{
    char ps[51] = {0};
    int t;
    int check;
    int i;
    int j;
    
    scanf("%d", &t);
    i = -1;
    while (++i < t)
    {
        scanf("%s", ps);
        check = 0; // 괄호가 맞게 입력되었는지 확인
        j = -1;
        while (ps[++j])
        {
            if (ps[j] == '(') // 열리면 check++
                check++;
            else		// 닫히면 check--;
            {
                check--;
                if (check < 0)
					break ;
				// ')'가 먼저 들어오거나, '('보다 개수가 많은 경우
            }
        }
        if (check == 0) // 제대로 짝이 맞으면 YES
            printf("YES\n");
        else		// 아니면 0 출력
            printf("NO\n");
    }
    return (0);
}
