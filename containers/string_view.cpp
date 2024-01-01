#include <iostream>
#include <string_view>
#include <string>

int main(void)
{
    std::string_view sv = "abcdef";
    for (char c : sv) {
    // for (char &c : sv) { // error: binding reference of type ‘char&’ to ‘const value_type’
        std::cout << c << std::endl;
        ++c;
    }
    std::string s = "abcdef";
    for (char &c : s) {
        std::cout << c << std::endl;
        ++c;
    }
    std::cout << s << std::endl;
    return 0;
}
