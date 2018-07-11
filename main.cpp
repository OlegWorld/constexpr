#include <iostream>

constexpr size_t bin_id(size_t x)
{
    if (x == 0)
        return 0;

    size_t pos = 0;
    for (size_t y = x; y != 0; y >>= 1, pos++)
        if (y == 1)
            break;

    return !(x & (x - 1)) ? pos : pos + 1;
}

int main() {
    static_assert(bin_id(0) == 0);
    static_assert(bin_id(1) == 0);
    static_assert(bin_id(2) == 1);
    static_assert(bin_id(3) == 2);
    static_assert(bin_id(4) == 2);
    static_assert(bin_id(7) == 3);
    static_assert(bin_id(8) == 3);
    static_assert(bin_id(9) == 4);
    static_assert(bin_id(1023) == 10);
    static_assert(bin_id(1024) == 10);
    static_assert(bin_id(1025) == 11);
    static_assert(bin_id(1024*1024-33) == 20);
    static_assert(bin_id(1024*1024) == 20);
    static_assert(bin_id(1024*1024+33) == 21);
    static_assert(bin_id(1024*1024*1024-127) == 30);
    static_assert(bin_id(1024*1024*1024) == 30);
    static_assert(bin_id(1024*1024*1024+127) == 31);

    return 0;
}