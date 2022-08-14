#include <algorithm>
#include <vector>
#include <array>
#include <set>
#include <iostream>

using namespace std;

int main(void) {
    vector<int> v = {1, 2, 3};
    auto n1 = count(begin(v), end(v), 1);
    auto n2 = count_if(begin(v), end(v),
        [](auto x) {
            return x > 2;
        }
    );

    vector<int> v2 = {1, 2, 3, 4, 5};
    auto iter1 = v2.begin();
    auto iter2 = v2.end();
    auto iter3 = begin(v2);
    auto iter4 = end(v2);
    assert(iter1 == iter3);
    assert(iter2 == iter4);

    array<int, 5> arr = {0, 1, 2, 3, 4};
    auto b = arr.begin();
    auto e = arr.end();
    assert(distance(b, e) == 5);
    auto n = next(b);
    assert(distance(b, n) == 1);
    assert(distance(n, b) == -1);
    advance(n, 2);
    assert(*n == 3);
    assert(n == prev(e, 2));

    vector<int> v3 = {3, 5, 1, 7, 10};
    for (const auto &x : v3) {
        cout << x << ",";
    }
    cout << endl;
    auto print = [](const auto &x) {
        cout << x << ",";
    };
    for_each(v3.cbegin(), v3.cend(), print);
    cout << endl;

    sort(v3.begin(), v3.end());
    for_each(v3.cbegin(), v3.cend(), print);
    cout << endl;

    vector<int> v4 = {3, 5, 1, 7, 10};
    partial_sort(v4.begin(), next(v4.begin(), 3), v4.end());
    for_each(v4.cbegin(), v4.cend(), print);
    cout << endl;

    vector<int> v5 = {3, 5, 1, 7, 10};
    nth_element(v5.begin(), next(v5.begin(), 3), v5.end());
    for_each(v5.cbegin(), v5.cend(), print);
    cout << endl;

    vector<int> v6 = {3, 5, 1, 7, 10};
    for_each(v6.cbegin(), v6.cend(), print);
    cout << endl;
    auto mid_iter = next(v6.begin(), v6.size()/2);
    cout << *mid_iter << endl; 

    vector<int> v7 = {3, 5, 1, 7, 10};
    auto pos = partition(v7.begin(), v7.end(), 
        [](const auto &x) {
            return x > 9;
        }
    );
    for_each(v7.begin(), pos, print);
    cout << endl;

    auto value = minmax_element(v7.cbegin(), v7.cend());
    cout << *value.first << ", " << *value.second << endl;

    vector<int> v8 = {3, 5, 1, 7, 10, 99, 42};
    decltype(v8.cend()) pos2;
    pos2 = lower_bound(v8.cbegin(), v8.cend(), 7);
    auto found = (pos2 != v8.cend() && (*pos2 == 7));

    pos2 = upper_bound(v8.cbegin(), v8.cend(), 9);
    if (pos2 != v8.cend())
        cout << *pos2 << endl;

    multiset<int> set1 = {3, 5, 1, 7, 7, 7, 7, 10, 99, 42};
    auto pos3 = set1.find(7);
    auto low_pos = set1.lower_bound(7);
    auto up_pos = set1.upper_bound(7);
    for_each(low_pos, up_pos, print);

    vector<int> v9 = {1, 9, 11, 3, 5, 7};
    decltype(v.end()) pos4;
    pos4 = find(v9.begin(), v9.end(), 3);

    pos4 = find_if(v9.begin(), v9.end(),
        [](auto x) {
            return x % 2 == 0;
        }
    );
    cout << *pos4 << endl;

    array<int, 2> arr = {3, 5};
    decltype(v9.end()) pos5;
    pos5 = find_first_of(v9.begin(), v9.end(), arr.begin(), arr.end());

    return 0;
}