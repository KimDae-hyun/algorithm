#include <stdio.h>

int main(void)
{
	int cir[500500] = {0}; // 큐 배열, 1000 ~ 1까지의 합
	int ans[1000] = {0}; // 요세푸스 배열 
	int n; // 입력 값
	int k; // 제거 위치
	int i; // 저장되는 인덱스
	int j; // 입력되는 인덱스
	int a; // 배열 인덱스
	int check; // 제거될 값 저장

	scanf("%d %d", &n, &k);
	i = -1;
	while (++i < n)
		cir[i] = i + 1; // 1 ~ n까지 큐에 입력
	a = 0;
	j = 0;
	check = cir[k - 1]; // 첫 제거값
	while (a < n - 1) // ans의 마지막 값이 하나 남을때까지
	{
		if (cir[j] == check) // 제거될 값이면
		{
			ans[a++] = cir[j]; // ans에 저장
			cir[j] = 0; // 제거 // 없어도 무방?
			if (cir[j + k] == 0)  // 제거될 위치가 입력 위치보다 뒤인 경우
            {
                if (k % (i - j - 1)) // 위치 차이의 나머지만큼이 제거될 위치
				    check = cir[j + (k % (i - j - 1))];
                else // 나누어 떨어지면 입력 위치 바로 앞이 제거될 위치
                    check = cir[i - 1];
            }
			else // 제거될 위치가 입력위치보다 앞인 경우
				check = cir[j + k];
			j++;
		}
        if (cir[j] != check) // 제거될 값이 아닐 때만 입력
		    cir[i++] = cir[j++];
	}
	ans[a++] = cir[j]; // 마지막 한칸 배열에 담아주기
	printf("<");
	i = -1;
	while (++i < n)
	{
		printf("%d", ans[i]);
		if (i < n - 1)
			printf(", ");
	}
	printf(">");
	return (0);
}
