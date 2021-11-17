#include <iostream>

int main(void)
{
    int x;
    int y;
    int day;

    std::cin >> x;
    std::cin >> y;
    day = 0;
    if (x > 1)
        day = 3;
    if (x > 3)
    {
        for (int i = 3; i < 13; i++)
        {
            if (x > i && i % 2 == 1)
                day += 2;
            else
                day += 3;
        }
    }
    day += y;
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