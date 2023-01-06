#include <iostream>

using namespace std;

float fast_sqrt(float x) {
    uint32_t x_bits = 0;
    x_bits = *((uint32_t*) & x);
    x_bits = (x_bits >> 1) + 0x1FBB4F2E;
    return *((float*) & x_bits);
}

int main() {
    cout << fast_sqrt(3.5) << endl;
}
