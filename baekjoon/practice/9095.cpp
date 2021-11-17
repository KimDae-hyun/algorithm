#include <iostream>

int main(void)
{
    int t;
    int n;
    int sum[11];
    int count;

    sum[0] = 1;
    sum[1] = 2;
    sum[2] = 4;
    for (int i = 3; i <= 11; i++)
    {
        sum[i] = sum[i - 1] + sum[i - 2] + sum[i - 3];
    }
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        std::cout << sum[n - 1] << std::endl;
    }
    return (0);
}

/*
1 = 1
2 = 2
3 = 4
4 = 7
5 = 13
6 = 24
7 = 44
.
.
.
*/