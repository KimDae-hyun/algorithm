#include <stdio.h>

int main(void)
{
    int a;
    int b;
    
    while (42)
    {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0) // 종료 조건
            return (0);
        if (b % a == 0) // a가 약수
            printf("factor\n");
        else if (a % b == 0) // b가 약수
            printf("multiple\n");
        else // 서로 약수가 아닌 수
            printf("neither\n");
    }
    return (0);
}
