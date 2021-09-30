#include <stdio.h>

int main(void)
{
    int a;
    int b;
    
    while (42)
    {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0)
            return (0);
        if (b % a == 0)
            printf("factor\n");
        else if (a % b == 0)
            printf("multiple\n");
        else
            printf("neither\n");
    }
    return (0);
}
