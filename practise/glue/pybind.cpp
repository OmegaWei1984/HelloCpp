// g++ practise/glue/pybind.cpp -std=c++14 -shared -fPIC `python3 -m pybind11 --includes` -o ./bin/pydemo`python3-config --extension-suffix`

#include <pybind11/pybind11.h>
#include <iostream>

using namespace std;

PYBIND11_MODULE(pydemo, m)
{
    m.doc() = "pybind11 demo doc";

    m.def("info", [](){
        pybind11::print("c++ version =", __cplusplus);
        pybind11::print("gcc version =", __VERSION__);
        pybind11::print("libstd++ =", __GLIBCXX__);
    });

    m.def("add", [](int a, int b){
        return a + b;
    });
}

int main(void) {
    cout << "pybind pydemo" << endl;
    return 0;
}
