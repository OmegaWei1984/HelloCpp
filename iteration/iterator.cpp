#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

using namespace std;

class istream_line_reader
{
public:
    class iterator
    {
        typedef ptrdiff_t difference_type;
        typedef string value_type;
        typedef const value_type *pointer;
        typedef const value_type &reference;
        typedef input_iterator_tag iterator_category;
    };
};

int main(void)
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2;
    copy(v1.begin(), v1.end(), back_inserter(v2));
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));

    for (const string &line : istream_line_reader(is))
    {
        cout << line << endl;
    }

    return 0;
}
