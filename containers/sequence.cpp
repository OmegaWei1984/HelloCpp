#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <queue>
#include <forward_list>
#include <list>
#include <cassert>
#include "output_container.h"

using namespace std;

class Obj1
{
public:
    Obj1() { cout << "Obj1()" << endl; }

    Obj1(const Obj1 &) { cout << "Obj1(const Obj1&)" << endl; }

    Obj1(Obj1 &&) { cout << "Obj1(Obj1&&)" << endl; }
};

class Obj2
{
public:
    Obj2() { cout << "Obj2()" << endl; }

    Obj2(const Obj2 &) { cout << "Obj2(const Obj2&)" << endl; }

    Obj2(Obj2 &&) noexcept { cout << "Obj2(Obj2&&)" << endl; }
};

int main(void)
{
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
    for (int i = 0; i < 5; ++i)
    {
        fl.push_front(i);
    }

    list<int> l(1);
    l.push_front(-1);
    l.push_back(2);
    auto lit = find(l.cbegin(), l.cend(), 2);
    l.insert(lit, 1);
    assert(l.size() == 4);

    vector<Obj1> v1;
    v1.reserve(2);
    v1.emplace_back();
    v1.emplace_back();
    v1.emplace_back();

    vector<Obj2> v2;
    v2.reserve(2);
    v2.emplace_back();
    v2.emplace_back();
    v2.emplace_back();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({1, 1});
    pq.push({2, 2});
    pq.push({0, 7});
    pq.push({4, 3});
    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}