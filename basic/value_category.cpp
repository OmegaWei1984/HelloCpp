/**
 *                    expression
 *                        │  │
 *                        │  │
 *           glvalue ◄────┘  └────► rvalue
 *             │ │                     │ │
 *             │ │                     │ │
 * lvalue ◄────┘ └─────► xvalue ◄──────┘ └────► prvalue
 *
 */

#include <iostream>
#include <utility>

using namespace std;

class shape
{
public:
    virtual ~shape() {}
};

class circle : public shape
{
public:
    circle() { cout << "circle()" << endl; }
    ~circle() { cout << "~circle()" << endl; }
};

class triangle : public shape
{
public:
    triangle() { cout << "triangle()" << endl; }
    ~triangle() { cout << "~triangle()" << endl; }
};

class result
{
public:
    result() { cout << "result()" << endl; }
    ~result() { cout << "~result()" << endl; }
};

result
process_shape(const shape &shape1,
              const shape &shape2)
{
    cout << "process_shape()" << endl;
    return result();
}

class Obj
{
public:
    Obj() { cout << "Obj()" << endl; }

    Obj(const Obj &) { cout << "Obj(const Obj&)" << endl; }

    Obj(Obj &&) { cout << "Obj(Obj&&)" << endl; }
};

Obj simple()
{
    Obj tmp;
    // 一般 named return value optimization
    return tmp;
}

Obj simple_with_move()
{
    Obj tmp;
    // move 禁止 named return value optimization
    return move(tmp);
}

Obj complicated(int n)
{
    Obj tmp1, tmp2;
    // 分支一般没有 named return value optimization
    if (n % 2 == 0)
    {
        return tmp1;
    }
    else
    {
        return tmp2;
    }
}

void foo(const shape &)
{
    puts("foo(const shape&)");
}

void foo(shape &&)
{
    puts("foo(shape&&)");
}

void bar(const shape &s)
{
    puts("bar(const shape&)");
    foo(s);
}

void bar(shape &&s)
{
    puts("bar(shape&&)");
    foo(s);
}

template <typename T>
void bar(T &&s)
{
    foo(forward<T>(s));
}

int main(void)
{
    // int i, j, k = 0, *p = &k;
    // int i, j, *p;
    int i, j, *p = new int;
    i = 42;

    // error: expression is not assignable
    // 7 = i;

    // error: expression is not assignable
    // By overloading operators, you can make an expression such as j * 4 an lvalue.
    // j * 4 = 7;

    *p = i;
    cout << "*p: " << *p << endl;

    // the conditional operator returns an lvalue.
    (i > 3 ? i : j) = 1;

    // the constant ci is a non-modifiable lvalue
    const int ci = 42;
    // cannot assign to variable 'ci' with const-qualified type 'const int'
    // ci = 1;

    cout << "test 1" << endl;
    process_shape(circle(), triangle());

    cout << "test 2" << endl;
    result &&r = process_shape(circle(), triangle());

    delete p;

    cout << "test 3" << endl;
    simple();

    cout << "test 4" << endl;
    simple_with_move();

    cout << "test 5" << endl;
    complicated(42);

    cout << "test 6" << endl;
    bar(circle());

    cout << "test 7" << endl;
    circle temp;
    bar(temp);
    bar(circle());

    return 0;
}