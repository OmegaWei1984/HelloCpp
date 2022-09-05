// https://docs.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-shared-ptr-instances

// shared_ptr-examples.cpp
// The following examples assume these declarations:
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <cassert>

struct MediaAsset
{
    virtual ~MediaAsset() = default; // make it polymorphic
};

struct Song : public MediaAsset
{
    std::wstring artist;
    std::wstring title;
    Song(const std::wstring &artist_, const std::wstring &title_) : artist{artist_}, title{title_} {}
};

struct Photo : public MediaAsset
{
    std::wstring date;
    std::wstring location;
    std::wstring subject;
    Photo(
        const std::wstring &date_,
        const std::wstring &location_,
        const std::wstring &subject_) : date{date_}, location{location_}, subject{subject_} {}
};

using namespace std;

int main()
{
    // The examples go here, in order:
    // Example 1
    auto sp1 = make_shared<Song>(L"The Beatles", L"Im Happy Just to Dance With You");
    shared_ptr<Song> sp2(new Song(L"Lady Gaga", L"Just Dance"));
    shared_ptr<Song> sp5(nullptr);
    assert(sp2->title.compare(L"Just Dance") == 0);

    // Example 2
    auto sp3(sp2);
    assert(sp2.use_count() == 2);
    auto sp4 = sp3;
    assert(sp2.use_count() == 3);
    shared_ptr<Song> sp7(nullptr);
    sp1.swap(sp2);
    assert(sp1->title.compare(L"Just Dance") == 0);
    assert(sp2->title.compare(L"Im Happy Just to Dance With You") == 0);
    assert(sp3->title.compare(L"Just Dance") == 0);

    // Example 3
    vector<shared_ptr<Song>> v{
        make_shared<Song>(L"Bob Dylan", L"The Times They Are A Changing"),
        make_shared<Song>(L"Aretha Franklin", L"Bridge Over Troubled Water"),
        make_shared<Song>(L"Thalía", L"Entre El Mar y Una Estrella")};

    vector<shared_ptr<Song>> v2;
    remove_copy_if(v.begin(), v.end(), back_inserter(v2), [](shared_ptr<Song> s){
        return s->artist.compare(L"Bob Dylan") == 0;
    });
    for (const auto& s : v2) {
        std::wcout << s->title << std::endl;
    }
    // Example 4
    // Example 6
}
