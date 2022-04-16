#include <msgpack.hpp>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Book final
{
public:
    int id;
    string title;
    // set<string> tags;
    vector<string> tags;
public:
    MSGPACK_DEFINE(id, title, tags);
};

int main(void) {
    vector<int> v = {1, 0, 2, 4};
    msgpack::sbuffer sbuf;
    msgpack::pack(sbuf, v);

    cout << sbuf.size() << endl;

    auto handle = msgpack::unpack(sbuf.data(), sbuf.size());
    auto obj = handle.get();
    vector<int> v2;
    obj.convert(v2);
    assert(equal(v.begin(), v.end(), v2.begin()));

    msgpack::packer<decltype(sbuf)> packer(sbuf);
    packer.pack(1024).pack(v2).pack("hello"s);

    for (decltype(sbuf.size()) offset = 0; offset != sbuf.size();) {
        auto handle = msgpack::unpack(sbuf.data(), sbuf.size(), offset);
        auto obj2 = handle.get();
    }

    Book book = {1, "1984", {"dystopian", "political fiction"}};
    msgpack::sbuffer bookbuf;
    msgpack::pack(bookbuf, book);
    auto bookobj = msgpack::unpack(bookbuf.data(), bookbuf.size()).get();

    Book book2;
    bookobj.convert(book2);

    assert(book.id == book2.id);
    cout << book2.title << endl;

    return 0;
}
