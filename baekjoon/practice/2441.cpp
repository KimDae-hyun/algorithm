#include <iostream>

int main(void)
{
    int a;

    std::cin >> a;
    for (int i = a; i > 0; i--)
    {
        for(int j = i; j < a; j++)
        {
            std::cout << " ";
        }
        for(int k = a - i; k < a; k++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    return (0);
}