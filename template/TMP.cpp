#include <iostream>

template <int n>
struct factorial
{
    static_assert(n >= 0, "Arg must be non-negative");
    static const int value = n * factorial<n - 1>::value;
};

template <>
struct factorial<0>
{
    static const int value = 1;
};

template <bool cond, typename Then, typename Else>
struct If;

template <typename Then, typename Else>
struct If<true, Then, Else>
{
    typedef Then type;
};

template <typename Then, typename Else>
struct If<false, Then, Else>
{
    typedef Else type;
};

template <bool condition, typename Body>
struct WhileLoop;

template <typename Body>
struct WhileLoop<true, Body>
{
    typedef typename WhileLoop<
        Body::cond_value, typename Body::next_type>::type type;
};

template <typename Body>
struct WhileLoop<false, Body>
{
    typedef typename Body::res_type type;
};

template <typename Body>
struct While
{
    typedef typename WhileLoop<Body::cond_value, Body>::type type;
};

template <class T, T v>
struct integral_constant
{
    static const T value = v;
    typedef T value_type;
    typedef integral_constant type;
};

template <int result, int n>
struct SumLoop
{
    static const bool cond_value = n != 0;
    static const int res_value = result;
    typedef integral_constant<int, res_value> res_type;
    typedef SumLoop<result + n, n - 1> next_type;
};

template <int n>
struct Sum
{
    typedef SumLoop<0, n> type;
};

int main(void)
{
    std::cout << factorial<10>::value << std::endl;

    std::cout <<  While<Sum<10>::type>::type::value << std::endl;

    return 0;
}
