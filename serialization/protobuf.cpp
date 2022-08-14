#include "sample.pb.h"

using vendor_t = sample::Vendor;

int main(void) {
    vendor_t v;
    assert(!v.IsInitialized());

    v.set_id(1);
    v.set_name("name");
    v.set_valid(true);

    return 0;
}
