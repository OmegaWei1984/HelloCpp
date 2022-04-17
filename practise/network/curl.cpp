#include <curl/curl.h>
#include <cassert>
#include <iostream>

using namespace std;

size_t write_callback(char *, size_t, size_t, void*);

int main(void) {
    auto curl = curl_easy_init();
    assert(curl);

    curl_easy_setopt(curl, CURLOPT_URL, "http://google.com");

    auto res = curl_easy_perform(curl);
    if (res != CURLE_OK)
        cout << curl_easy_strerror(res) << endl;

    curl_easy_cleanup(curl);

    auto curl2 = curl_easy_init();
    curl_easy_setopt(curl2, CURLOPT_URL, "http://google.com");
    curl_easy_setopt(curl2, CURLOPT_WRITEFUNCTION,
        (decltype(&write_callback))
        [](char *ptr, size_t size, size_t nmemb, void *userdata){
            cout << "size = " << size * nmemb << endl;
            return size * nmemb;
        }
    );

    auto res2 = curl_easy_perform(curl2);

    curl_easy_cleanup(curl2);

    return 0;
}
