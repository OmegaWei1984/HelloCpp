#include <chrono>
#include <complex>
#include <iostream>
#include <string>
#include <thread>
#include <bitset>

using namespace std;

struct length
{
    double value;
    enum unit
    {
        metre,
        centimetre
    };
    static constexpr double factors[] = {1.0, 1e-2};
    explicit length(double v, unit u = metre)
    {
        value = v * factors[u];
    }
};

length operator+(length lhs, length rhs)
{
    return length(lhs.value + rhs.value);
}

length operator"" _m(long double v)
{
    return length(v, length::metre);
}

length operator"" _cm(long double v)
{
    return length(v, length::centimetre);
}

int main(void)
{
    cout << "i * i = " << 1i * 1i << endl;
    cout << "Waiting for 500ms" << endl;
    this_thread::sleep_for(500ms);
    cout << "Hello world"s.substr(0, 5) << endl;

    length l = 1.0_m + 1.0_cm;
    cout << l.value << endl;

    unsigned mask = 0b111000000;
    cout << bitset<9>(mask) << endl;

    unsigned mask2 = 0b111'000'000;
    long r_earth_equatorial = 6'378'137;
    double pi = 3.14159'26535'89793;
    const unsigned magic = 0x44'42'47'4E;

    return 0;
}
