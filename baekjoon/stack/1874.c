#include <stdio.h>

int main(void)
{
    int in;
    int p[100001] = {0}; // push, pop에 의해 담길 숫자 배열. 스택 
    char sig[200001] = {0};
	// '+', '-'가 담길 배열 // push, pop은 짝을 이룸 -> 입력 개수의 2배
    int n; // 입력할 개수
    int i; // 입력된 개수 카운트
    int j; // p의 인덱스
    int k; // 스택에 입력될 1 ~ n 까지의 숫자
    int l; // sig의 인덱스
    int error; // 스택으로 표현 불가능한 경우 처리
    
    scanf("%d", &n);
    i = -1;
    j = 0;
    k = 0;
    l = 0;
    error = 0;
    while (++i < n)
    {
        scanf("%d", &in);
        while (error == 0 && k < in)  // 입력값과 같아질 때까지 push
        {
            sig[l++] = '+';
            p[++j] = ++k;
        }
        if (p[j] == in) // 입력값과 같으면 pop
        {
            sig[l++] = '-';
            p[j--] = 0;
        }
        else // 불가능한 경우 에러처리 // 입력값을 끝까지 받기 위해 루프진행
            error = 1;
    }
    if (error == 1) // 에러인 경우
    {
        printf("NO");
        return (0);
    }
    i = -1;
    while (sig[++i]) // + - 출력
        printf("%c\n", sig[i]);
    return (0);
}
