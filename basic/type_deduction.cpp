#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    auto i = 1;
    auto d = 1.0;
    auto s = "hello";
    map<int, string> m = {{1, "hello"}, {2, "world"}};
    auto it = m.begin();

    auto x = 0L;        // long
    auto y = &x;        // long*
    auto z{&x};         // long*
    auto &x1 = x;       // long&
    auto *x2 = &x;      // long*
    const auto &x3 = x; // const long&
    auto x4 = &x3;      // const long*

    return 0;
}