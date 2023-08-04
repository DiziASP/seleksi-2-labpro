#include <iostream>
#include <vector>
#include <random>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 1000000000);

    std::vector<int> randomArray(100);

    for (int i = 0; i < 100; ++i)
    {
        randomArray[i] = dist(gen);
    }

    // Printing the generated array
    for (int i = 0; i < 100; ++i)
    {
        std::cout << randomArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}