#include <cpr/cpr.h>
#include <iostream>

using namespace std;

int main(void) {
    auto res = cpr::Get(cpr::Url{"http://nginx.org"});
    cout << res.elapsed << endl;
    cout << res.url << endl;
    cout << res.status_code << endl;
    cout << res.text.length() << endl;

    for (auto& x : res.header) {
        cout << x.first << " => " << x.second << endl;
    }

    const auto url = "http://openresty.org"s;
    auto res1 = cpr::Head(cpr::Url{url});
    auto res2 = cpr::Get(
        cpr::Url{url},
        cpr::Parameters{{"a", "1"}, {"b", "2"}}
    );
    auto res3 = cpr::Post(
        cpr::Url{url},
        cpr::Header{
            {"x", "xxx"}, {"expect", ""}
        },
        cpr::Body{"post data"},
        cpr::Timeout{200ms}
    );

    auto f = cpr::GetAsync(cpr::Url{"http://openresty.org"});
    auto res_async = f.get();
    cout << res.elapsed << endl;

    return 0;
}
