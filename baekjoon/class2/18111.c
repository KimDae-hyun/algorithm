#include <stdio.h>

int main(void)
{
    int map[500][500];
    int n; // 세로
    int m; // 가로
    int b; // 가지고 있는 블록
    int i; 
    int j;
    int k; // 높이 인덱스
    int h; // 저장될 높이 값
    int min; // 입력되는 높이 최소값
    int max; // 입력되는 높이 최대값
    int sum; // 같은 높이로 만드는데 걸리는 시간
	int inv; // 높이를 만들고 나서 인벤토리가 -인지 확인
    int time; // 시간 저장값
    
    scanf("%d %d %d", &n, &m, &b);
    i = -1;
    max = 0;
    min = 2147483647;
    while (++i < n)
    {
        j = -1;
        while (++j < m)
        {
            scanf("%d", &map[i][j]);
            if (max < map[i][j]) // 높이 최대값
                max = map[i][j];
            if (min > map[i][j]) // 높이 최소값
                min = map[i][j];
        }
    }
    k = min - 1; // 높이 최소값부터 확인
    h = 0;
    time = 2147483647; // 제일 적게 걸리는 시간을 찾기 위해
    while (++k <= max) // 현재 높이부터 최대 높이까지 모든 경우를 파악
    { // 땅을 현재 높이로 맞추는 과정
        sum = 0;
        inv = b;
        i = -1;
        while (++i < n)
        {
            j = -1;
            while (++j < m)
            {
                if(map[i][j] < k) // 현재 높이가 기준 높이보다 낮으면 블록 추가
                {
                    sum += k - map[i][j]; 
                    inv -= k - map[i][j];
                }
                else if (map[i][j] > k) // 블록 제거
                {
                    sum += (map[i][j] - k) * 2;
                    inv += map[i][j] - k;
                }
            }
        }
        if (inv >= 0 && sum <= time) // 인벤토리가 음수이면 에러
        {
            time = sum;
            h = k;
        }
    }
    printf("%d %d", time, h);
    return (0);
}

/* 참고
   - 60라인에서 sum < time으로 했다가 오류. 같은 시간일때 높이가 더 높아야 하기 때문에 <=으로 해주어야 한다
   */
