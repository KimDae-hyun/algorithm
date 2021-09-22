#include <stdio.h>
#include <stdlib.h>

int check(int *board, int n, int q)
{
    int i;
    
    i = -1;
    while (++i < q)
    {
        if (board[q] == board[i] || abs(board[q] - board[i]) == abs(q - i))
            return (0);
    }
    return (1);
}

void rec(int *board, int n, int *count, int q)
{
    int i;
    
    if (q == n)
    {
        (*count)++;
        return ;
    }
    else
    {
        i = -1;
        while (++i < n)
        {
            board[q] = i;
            if (check(board, n, q) == 1)
                rec(board, n, count, q + 1);
        }
    }   
}

int main()
{
    int board[15] = {0};
    int n;
    int count;
    
    scanf("%d", &n);
    count = 0;
    rec(board, n, &count, 0);
    printf("%d", count);
    return (0);
}
