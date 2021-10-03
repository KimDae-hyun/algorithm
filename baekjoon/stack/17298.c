#include <stdio.h>
#include <stdlib.h>
// top = 스택의 가장 위의 값, push = 스택 top 추가, pop = 스택 top 제거  
// 오른쪽의 큰수를 찾아주는 문제 => 마지막값부터 시작
int main(void)
{
    int n;
    int *in; // 입력값
    int *nge; // 오큰수
    int *stack; // 오큰수와 오큰수에 해당하는  입력값을 담아줄 스택
    int i; // 기준값 인덱스
    int j; // 기준값 이후 비교값 인덱스
    int k; // stack 인덱스
    
    scanf("%d", &n);
    in = (int *)calloc(n, sizeof(int));
    nge = (int *)calloc(n, sizeof(int));
    stack = (int *)calloc(n, sizeof(int));
    i = -1;
    while (++i < n)
        scanf("%d", &in[i]);
    k = 0;
    stack[k] = in[i - 1]; // 입력의 마지막값을 push
    i = n - 1; // 마지막 인덱스부터 시작
    nge[i] = -1; // 마지막 입력값의 오큰수는 없으므로 -1
    while (--i >= 0) 
    {
        j = i;
        while (++j < n)
        {
            if (in[i] > in[j])// 현재값이 큰 경우
            {
                if (in[i] < stack[k]) // 현재값보다 큰 오큰수인 경우
                {
                    nge[i] = stack[k++]; // 오큰수는 스택의 top
                    stack[k] = in[i]; // 현재값 push
                    break ;
                }
                else // 현재값이 다음 값의 오큰수보다 크면
                {
                    while (--k >= 0)
                    {//현재값보다 오큰수가 커질때까지 pop
                        if (in[i] < stack[k])
                        {
                            nge[i] = stack[k++];
                            stack[k] = in[i];
                            break ;
                        }
                    }
                    if (k > -1) //현재값보다 큰 오큰수를 찾은 경우
                        break ;
                    else // 더 큰 오큰수가 없는 경우 -1
                    {
                        nge[i] = -1; 
                        stack[++k] = in[i]; // push => 오른쪽의 가장 큰 값
                        break ;
                    }
                }
            }
            else
            {
                if (in[i] < in[j]) //현재값이 작은 경우
                {
                    nge[i] = in[j];
                    stack[++k] = in[i]; // push
                }
                else // 현재 값과 다음값이 같은 경우
                    nge[i] = nge[j];
                break ;
            }
        }
    }
    i = -1;
    while (++i < n)
        printf("%d ", nge[i]);
    free(in);
    free(nge);
    free(stack);
    return (0);
}
