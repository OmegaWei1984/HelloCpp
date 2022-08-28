#include <memory>
#include <cassert>

using namespace std;

int main(void)
{
    unique_ptr<int> ptr1(new int(10));
    assert(*ptr1 == 10);
    assert(ptr1 != nullptr);

    unique_ptr<string> ptr2(new string("hello"));
    assert(*ptr2 == "hello");
    assert(ptr2->size() == 5);

    auto ptr3 = make_unique<int>(42);
    assert(ptr3 && *ptr3 == 42);

    auto ptr4 = make_unique<string>("hello cpp");
    assert(!ptr4->empty());

    auto ptr5 = make_unique<int>(42);
    assert(ptr5 && *ptr5 == 42);

    auto ptr6 = move(ptr5);
    assert(ptr6 && !ptr5);

    shared_ptr<int> ptr7(new int(42));
    assert(ptr7 && *ptr7 == 42 && ptr7.unique());
    auto ptr8 = ptr7;
    assert(ptr8 && ptr7 && (ptr7 == ptr8));
    assert(!ptr7.unique() && !ptr8.unique());
    assert(ptr7.use_count() == 2 && ptr8.use_count() == 2);

    return 0;
}