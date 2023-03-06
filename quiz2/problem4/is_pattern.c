#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

bool is_pattern(uint16_t x)
{
    if (!x)
        return 0;

    for (; x > 0; x <<= 1) {
        if (!(x & 0x8000))
            return false;
    }

    return true;
}


bool is_pattern_new(uint16_t x)
{
    //printf("%x\t", x);
    const uint16_t n = -x;
    //printf("%x\t", n);
    return (n ^ x) < x;
}

int main(int argc, char **argv)
{
    uint16_t x = 0xF000;
    printf("%d\n", is_pattern(x));
    printf("%d\n", is_pattern_new(x));
    return 0;
}