#include <vector>
#include <set>
#include <iterator>

using namespace std;

template <typename InputIterator, typename T>
InputIterator myFind(InputIterator first, InputIterator last, const T &val)
{
    while (first != last)
    {
        if (*first == val)
            return first;
        ++first;
    }
    return last;
}

template <typename InputIerator, typename T>
T myAccumulate(InputIerator first, InputIerator last, T &init)
{
    while (first != last)
    {
        init = init + *first;
        first++;
    }
    return init;
}

template <typename T>
T sum(T val)
{
    return val;
}

template <typename T, typename... Params>
T sum(T first, Params... params)
{
    return first + sum(params...);
}

int main(void)
{
    vector<int> nums = {2, 3, 1, 6, 5};
    set<int> nums2 = {3, 5, 2, 1, 7};
    vector<int>::const_iterator two = myFind(nums.cbegin(), nums.cend(), 2);
    set<int>::const_iterator two2 = myFind(nums2.cbegin(), nums2.cend(), 2);
    int acc = 0, acc2 = 0;
    myAccumulate(nums.begin(), nums.end(), acc);
    myAccumulate(nums2.begin(), nums2.end(), acc2);
    int sum1 = sum(1, 2, 3);
    int sum2 = sum(0);
    int sum3 = sum(1, 1);

    return 0;
}
