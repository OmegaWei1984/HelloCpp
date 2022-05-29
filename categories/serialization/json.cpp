#include <vector>
#include <iostream>
#include "json.hpp"

using json_t = nlohmann::json;
using namespace std;

int main(void) {
    json_t j;
    j["age"] = 23;
    j["name"] = "hellojson";

    vector<int> v = {1, 2, 3};
    j["v"] = v;

    cout << j.dump() << endl;

    return 0;
}
