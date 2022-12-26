#include <array>
#include <iostream>
#include <vector>

constexpr int sqr(int n)
{
    return n * n;
}

constexpr int factorial(int n)
{
    if (n < 0)
    {
        throw std::invalid_argument(
            "Arg must be non-negative");
    }

    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

struct magic
{
    static constexpr int number = 42;
};

int main()
{
    constexpr int n = sqr(3);
    std::array<int, n> a;
    int b[n];
    constexpr int m = factorial(10);
    std::cout << m << std::endl;
    std::vector<int> v;
    v.push_back(magic::number);
    constexpr static int i = 42;
    constexpr const int& j = i;
}