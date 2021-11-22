#include <iostream>

int main(void)
{
    int i;
    int num;
    int sum;

    i = -1;
    sum = 0;
    while (++i < 5)
    {
        std::cin >> num;
        if (num < 40)
            sum += 40;
        else
            sum += num;
    }
    std::cout << sum / 5 << std::endl;
    return (0);
}