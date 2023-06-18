#include <cassert>

int foo(const int &num) {
    return num + 1;
}

int main(void) {
    int a = 0;
    // 修饰变量，说明该变量不可以被改变；
    const int b = 42;
    // 修饰指针，分为指向常量的指针（pointer to const）
    int const *pa = &b;
    const int *pa2 = &b;
    pa++;
    pa2++;
    // 自身是常量的指针（常量指针，const pointer）；
    int *const pb = &a;
    *pb = 42;
    assert(a == 42);
    // 指向常量的引用（reference to const）
    int c = foo(a);
    assert(c == 43);
    const int &bb = b;
    assert(bb == 42);
    return 0;
}

