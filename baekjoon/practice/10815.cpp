#include <iostream>

// cin, cout 은 scanf, printf보다 속도가 현저히 느리다!
// cin, cout 사용하면 시간초과 발생!!

int main(void)
{
	int n, m, num;
	int *arr;

	scanf("%d", &n);
	arr = new int[20000001];
	for(int i = 0; i < n; i++)
	{ 
		scanf("%d", &num);
		if (num != 0)
		    arr[num + 10000000] = 1;
		else
			arr[num + 10000000] = -1;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d", &num);
		if (num != 0)
		{
			if (arr[num + 10000000] == 1)
				printf("1 ");
			else
				printf("0 ");
		}
		else
		{
			if (arr[num + 10000000] == -1)
				printf("1 ");
			else
				printf("0 ");
		}
	}
	delete arr;
	return (0);
}
