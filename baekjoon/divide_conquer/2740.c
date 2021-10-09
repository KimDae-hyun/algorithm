#include <stdio.h>

int main(void)
{
    int mat1[100][100] = {0};// 첫번째 행렬
    int mat2[100][100] = {0}; // 두번째 행렬
    int n; 
    int m;
    int k;
    int i;
    int j;
    int a;
    int sum;
    
    scanf("%d %d", &n, &m);
    i = -1;
    while (++i < n)
    {
        j = -1;
        while (++j < m)
            scanf("%d", &mat1[i][j]); // 첫번째 행렬 n * m 크기
    }
    scanf("%d %d", &m, &k);
    i = -1;
    while (++i < m)
    {
        j = -1;
        while (++j < k)
            scanf("%d", &mat2[i][j]); // 두번째 행렬 m * k 크기
    }
    i = -1;
    while (++i < n) // 첫번째 행렬 세로
    {
        j = -1;
        while (++j < k) // 두번째 행렬 가로
        {
            sum = 0;
            a = -1;
            while (++a < m)
                sum += (mat1[i][a] * mat2[a][j]); // 결과값
            printf("%d ", sum);
        }
        printf("\n");
    }
    return (0);
}
