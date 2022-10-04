#include <iostream>
#include <map>
#include <string>

using namespace std;

auto get_a_map()
{
    map<int, string> m = {{1, "hello"}, {2, "world"}};
    return m;
}

class Foo
{
public:
    using map_type = map<int, string>;

private:
    map_type m;
    using it_type = decltype(m.begin());
    it_type pos;
};

template <typename T>
void foo(const T &c)
{
    using std::begin;
    using std::end;

    for (auto it = begin(c), ite = end(c); it != ite; ++it)
    {
        // do something
    }
}

template <typename T>
struct Obj
{
    T v;
    Obj(T value) : v(value){};
};

template <typename T>
struct Obj2
{
    T v;
    Obj2(T value) : v(value){};
};
Obj2(const char *)->Obj2<string>;

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

    int xx = 0;
    decltype(xx) xx1;        // int
    decltype(xx) &xx2 = xx;  // int&
    decltype(xx) *xx3;       // int*
    decltype(&xx) xx4;       // int*
    decltype(&xx) *xx5;      // int**
    decltype(xx2) xx6 = xx2; // int&

    using int_ptr = decltype(&xx);
    using int_ref = decltype(xx) &;
    int_ref xx7 = xx;

    int xxx = 0;
    decltype(auto) xxx1 = (xxx); // int&
    decltype(auto) xxx2 = &xxx;  // int*
    decltype(auto) xxx3 = xxx1;

    auto m2 = get_a_map();
    auto pr = make_pair(1, 42);

    pair pr2{1, 42};
    array arr{1, 2, 3};
    Obj obj1{string("hello")}; // struct Obj<std::string>
    cout << obj1.v << endl;
    Obj obj2{"hello"}; // struct Obj<const char *>
    const char *p = obj2.v;
    while (*p != '\0')
    {
        cout << *p;
        ++p;
    }
    cout << endl;
    Obj2 obj3{"hello"}; // struct Obj2<std::string>
    cout << obj3.v << endl;

    return 0;
}