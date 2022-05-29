#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str = "abc";

    assert(str.length() == 3);
    assert(str < "xyz");
    assert(str.substr(0, 1) == "a");
    assert(str[0] == 'a');
    assert(str.find("b") == 1);
    assert(str.find("x") == string::npos);
    assert(str + "xyz" == "abcxyz");
    str.push_back('x');
    assert(str == "abcx");
    str.append("yz");
    assert(str == "abcxyz");

    auto str2 = "hello string"s;
    cout << str2 << endl;
    string str3 = R"(/n/n/n/n)";
    cout << str3 << endl;
    auto str4 = R"++(R"(/n/n/n/n)")++";
    cout << str4 << endl;

    assert(stoi("42") == 42);
    assert(stof("3.1415926") == 3.1415926);
    assert(to_string(42) == "42");

    return 0;
}
