#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	if (*(int*)a > *(int*)b)
		return (1);
	else if (*(int*)a < *(int*)b)
		return (-1);
	else
		return (0);
}

int main()
{
	int num[8001] = {0};
	int arr[500000] = {0};
	int count[500000] = {0};
	int n;
	int i;
	int j;
	int sum;
	int lar;
	int tmp;
	int check;

	scanf("%d", &n);
	i = -1;
	sum = 0;
	while (++i < n)
	{
		scanf("%d", &arr[i]);
		num[arr[i] + 4000]++;
		sum += arr[i];
	}
    qsort(arr, n, sizeof(int), compare);
	i = -1;
	j = -1;
    lar = 0;
    tmp = 0;
	while (++i <= 8000)
    {
		if (num[i] != 0)
        {
            count[++j] = num[i];
    		if (count[j] > lar)
            {
                check = 0;
    			lar = count[j];
                tmp = i - 4000;
            }
            else if (count[j] == lar)
            {
                if (tmp != i - 4000 && check == 0)
                {
                    tmp = i - 4000;
                    check++;
                }
            }
        }
    }
	lar = tmp;
	printf("%.0lf\n", (double)sum / n);
	printf("%d\n", arr[n / 2]);
	printf("%d\n", lar);
	printf("%d", arr[n - 1] - arr[0]);
	return (0);
}
