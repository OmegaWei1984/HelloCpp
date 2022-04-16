#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cassert>

using namespace std;

int main(void) {
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

    return 0;
}