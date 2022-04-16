#include <thread>
#include <iostream>

using namespace std;
using atomic_int = atomic<int>;

static atomic_flag flag2 {false};
static atomic_int n3;

int main(void) {
    auto func = []() {
        cout << "tid: " << this_thread::get_id() << endl;
    };

    thread t(func);

    static once_flag flag;
    auto func2 = []() {
        call_once(flag, []() {
            cout << "tid: " << this_thread::get_id() << endl;
            cout << "only once\n" << endl;
        });
    };

    thread t1(func2);
    thread t2(func2);

    thread_local int n = 0;
    auto func3 = [&](int x) {
        n += x;
        cout << "this is n " << n << " in " << this_thread::get_id() << endl; 
    };

    thread t3(func3, 10);
    thread t4(func3, 20);

    static int n2 = 0;
    auto func4 = [&](int x) {
        n2 += x;
        cout << "this is n2 " << n2 << " in " << this_thread::get_id() << endl; 
    };
    thread t5(func4, 10);
    thread t6(func4, 20);

    atomic_int atomic_x {0};
    atomic_long atomic_y {1000L};
    assert(++atomic_x == 1);
    atomic_y += 200;
    assert(atomic_y < 2000);

    auto func5 = [&](int x) {
        atomic_x += x;
        cout << "func5 " << atomic_x << endl;
    };
    auto func6 = [&](int x) {
        atomic_x -= x;
        cout << "func6 " << atomic_x << endl;
    };

    thread t7(func5, 10);
    thread t8(func5, 10);
    thread t9(func6, 20);
    thread t10(func5, 10);

    auto func7 = [&]() {
        auto value = flag2.test_and_set();
        if (value) {
            cout << "flag has been set." << endl;
        } else {
            cout << "set flag by" << this_thread::get_id() << endl;
        }

        n3 += 100;

        this_thread::sleep_for(n3.load() * 10ms);
        cout << n3 << endl;
    };

    thread t11(func7);
    thread t12(func7);

    t1.join();
    t2.join();

    while(true) {}

    return 0;
}
