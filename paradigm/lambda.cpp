#include <algorithm>
#include <array>
#include <cassert>
#include <functional>
#include <iostream>
#include <ranges>
#include <vector>
#include <map>
#include <numeric>

using namespace std:: placeholders;

// C++ 98 function object
struct adder
{
    adder(int n) : n_(n) {}
    int operator()(int x) const
    {
        return x + n_;
    }

private:
    int n_;
};

int add_1(int x)
{
    return x + 1;
}

template <typename T>
auto test1(T fn)
{
    return fn(2);
}

template <typename T>
auto test2(T &fn)
{
    return fn(2);
}

template <typename T>
auto test3(T *fn)
{
    return (*fn)(2);
}

int main(void)
{
    adder add_2(2);
    assert(add_2(5) == 7);
    assert(test1(add_1) == 3);
    assert(test2(add_1) == 3);
    assert(test3(add_1) == 3);
    auto add_3 = [](int x) {
        return x + 3;
    };
    assert(add_3(1) == 4);
    auto add_n = [](int n) {
        return [n](int x) {
            return x + n;
        };
    };
    auto add_4 = add_n(4);
    assert(add_4(1) == 5);
    assert(add_n(2)(5) == 7);
    std::vector<int> v = {1, 2, 3};
    transform(v.begin(), v.end(), v.begin(), [](int e) {
        return e * e;
    });
    assert(v[2] == 9);
    auto const ints = {0,1,2,3,4,5};
    auto even = [](int i) { return 0 == i % 2; };
    auto square = [](int i) { return i * i; };
    // "pipe" syntax of composing the views:
    for (int i : ints | std::views::filter(even) | std::views::transform(square)) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    // a traditional "functional" composing syntax:
    for (int i : std::views::transform(std::views::filter(ints, even), square)) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    std::array arr{1, 2, 3, 4, 5};
    auto sum = std::accumulate(arr.begin(), arr.end(), 0, [](auto x, auto y) {
            return x + y;
        });
    std::cout << sum << std::endl;
    std::vector<int> v2 = {0, 1, 2, 3};
    transform(v2.begin(), v2.end(), v2.begin(), std::bind(std::plus<>(), _1, 2));
    for (const int &i : v2) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    std::map<std::string, std::function<int(int, int)>> op_dict {
        { "+", [](int x, int y) { return x + y; }},
        { "-", [](int x, int y) { return x - y; }}
    };
    std::cout << op_dict.at("+")(2, 2) << " " << op_dict.at("-")(142, 100) << std::endl;
    return 0;
}
