#include <iostream>

int main(void)
{
    int a;

    std::cin >> a;
    for (int i = a; i > 0; i--)
    {
        for(int j = i; j > 0; j--)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    return (0);
}