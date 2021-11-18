#include <iostream>

int main(void)
{
    int x;
    int y;
    int day;
    int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    std::cin >> x;
    std::cin >> y;
    day = y;
    for (int i = 0; i < (x - 1); i++)
        day += month[i];
    day %= 7;
    if (day == 1)
        std::cout << "MON" << std::endl;
    else if (day == 2)
        std::cout << "TUE" << std::endl;
    else if (day == 3)
        std::cout << "WED" << std::endl;
    else if (day == 4)
        std::cout << "THU" << std::endl;
    else if (day == 5)
        std::cout << "FRI" << std::endl;
    else if (day == 6)
        std::cout << "SAT" << std::endl;
    else if (day == 0)
        std::cout << "SUN" << std::endl;
    return (0);
}