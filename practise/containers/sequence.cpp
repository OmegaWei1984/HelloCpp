#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>

using namespace std;

int main(void) {
    array<int, 2> arr;
    assert(arr.size() == 2);

    vector<int> vec(2);
    assert(vec.size() == 2);
    vec.push_back(0);
    assert(vec.size() == 3);

    deque<int> deq;
    deq.emplace_front(0);
    deq.emplace_back(1);
    assert(deq.size() == 2);

    forward_list<int> fl(5);
    for (int i = 0; i < 5; ++i) {
        fl.push_front(i);
    }
    
    list<int> l(1);
    l.push_front(-1);
    l.push_back(2);
    auto lit = find(l.cbegin(), l.cend(), 2);
    l.insert(lit, 1);
    assert(l.size() == 4);

    return 0;
}