#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int ceil_log2(uint32_t x)
{
    uint32_t r, shift;

    x--;
    r = (x > 0xFFFF) << 4;                 
    x >>= r;
    shift = (x > 0xFF) << 3;
    x >>= shift;
    r |= shift;
    shift = (x > 0xF) << 2;
    x >>= shift;
    r |= shift;
    shift = (x > 0x3) << 1;
    x >>= shift;
    return (r | shift | x >> 1) + 1;       
}

int ceil_log2_v2(uint32_t x) {
    uint8_t r = ((x & (x - 1)) != 0);
    // x |= x >> 16;
    // x |= x >> 8;
    // x |= x >> 4;
    // x |= x >> 2;
    // x |= x >> 1;
    return (32 - __builtin_clz(x) - 1 + r);
}

int ceil_log2_v3(uint32_t x) {
    uint32_t r = ((x & (x-1)) != 0);
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x++;
    return (32 - __builtin_clz(x-1) - 1 + r);
}


int main(int argc, char **argv)
{
    uint32_t a = 06534564;
    printf("%d\n", ceil_log2(a));
    printf("%d\n", ceil_log2_v2(a));
    printf("%d\n", ceil_log2_v3(a));
    return 0;
}