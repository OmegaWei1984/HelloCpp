#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cassert>
#include <iostream>
#include <complex>
#include "output_container.h"

using namespace std;

namespace std
{
    template <typename T>
    struct hash<complex<T>>
    {
        size_t operator()(const complex<T> &v) const noexcept
        {
            hash<T> h;
            return h(v.real()) + h(v.imag());
        }
    };
}

int main(void)
{
    set<int> s;
    s.insert(0);
    s.insert(1);
    s.insert(1);
    s.insert(2);
    assert(s.size() == 3);

    set<string> s1 = {"hello", "set", "just test"};
    assert(s1.size() == 3);

    map<string, int> m = {{"a", 0}, {"b", 1}, {"c", 2}};
    assert(m.size() == 3);
    m["d"] = 3;
    assert(m.size() == 4);
    m.erase("d");
    assert(m.size() == 3);

    unordered_set<int> us = {0, 1, 2};
    assert(us.size() == 3);

    unordered_map<string, int> um = {{"a", 0}, {"b", 1}, {"c", 2}};
    assert(um.size() == 3);

    for (auto &[key, value] : um)
        if (value > 1)
            value *= 2;

    multiset<int, greater<int>> ms = {1, 2, 5, 1, 3, 4};
    cout << ms << endl;

    unordered_set<int> us2 = {1, 1, 8, 2, 3, 2, 1, 6, 7, 9};
    cout << us2 << endl;

    unordered_map<complex<double>, double> umc {
        {{1.0, 1.1}, 1.1919},
        {{1.5, 1.0}, 1.2345}
    };

    cout << umc << endl;

    return 0;
}