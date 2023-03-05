#include <stdint.h>
#include <stdio.h>
static inline uint64_t pow2(uint8_t e) { return ((uint64_t)1) << e; }


uint64_t builtin_pow2(uint64_t x)
{
    if(x == 0) 
        return 0;
    return pow2(63 - __builtin_clzl(x) + 1);
}


int main(int argc, char **argv) {

    uint64_t a = 33;
    printf("%ld\n", builtin_pow2(a));


    return 0;
}