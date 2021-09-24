#include <stdio.h>

int main()
{
	int arr[21][21][21] = {0};
    int a;
    int b;
    int c;
    int n;

	a = -1;
	while (++a < 21)
	{
		b = -1;
		while (++b < 21)
		{
			c = -1;
			while (++c < 21)
			{
				if (a == 0 || b == 0 || c == 0)
					arr[a][b][c] = 1;
				else if (a < b && b < c)
					arr[a][b][c] = arr[a][b][c - 1] + arr[a][b - 1][c - 1] - arr[a][b - 1][c];
				else
					arr[a][b][c] = arr[a - 1][b][c] + arr[a - 1][b - 1][c] + arr[a - 1][b][c - 1] - arr[a - 1][b - 1][c - 1];
			}
		}
	}
    while (42)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1)
            break ;
        else
        {
            if (a <= 0 || b <= 0 || c <= 0)
				n = arr[0][0][0];
			else if (a > 20 || b > 20 || c > 20)
				n = arr[20][20][20];
			else
				n = arr[a][b][c];
            printf("w(%d, %d, %d) = %d\n", a, b, c, n);
        }
    }
    return (0);
}
