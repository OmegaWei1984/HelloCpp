#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <regex>

using namespace std;

// before C++11
void split(const string& s, vector<string>& tokens, const string& delimiters = " ")
{
    string::size_type lastPos = s.find_first_not_of(delimiters, 0);
    string::size_type pos = s.find_first_of(delimiters, lastPos);
    while (string::npos != pos || string::npos != lastPos) {
        tokens.push_back(s.substr(lastPos, pos - lastPos)); //use emplace_back after C++11
        lastPos = s.find_first_not_of(delimiters, pos);
        pos = s.find_first_of(delimiters, lastPos);
    }
}

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
    float f_pi = 3.1415926;
    assert(stof("3.1415926") == f_pi);
    // assert(stof("3.1415926") == 3.1415926);
    assert(to_string(42) == "42");

    string sentence = "the quick brown fox jumps over the lazy dog";
    vector<string> tokens;
    split(sentence, tokens);
    for (auto &v : tokens)
        cout << v << endl;

    regex ws_re("\\s+");
    vector<string> v(sregex_token_iterator(sentence.begin(), sentence.end(), ws_re, -1), 
    sregex_token_iterator());
    for (auto &&s : v)
        cout << s << endl;

    return 0;
}
