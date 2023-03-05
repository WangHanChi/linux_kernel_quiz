#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>   

static inline uint64_t pow2(uint8_t e) { return ((uint64_t)1) << e; }

uint64_t next_pow2(uint64_t x)
{
    x |= x >> 1;
    x |= x >> 1;
    x |= x >> 1;
    x |= x >> 1;
    x |= x >> 1;
    x |= x >> 1;
    x |= x >> 1;
    x |= x >> 1;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    return x + 1;
}

uint64_t builtin_pow2(uint64_t x)
{
    if(x == 0) 
        return 0;
    return pow2(63 - __builtin_clzl(x) + 1);
}

int main(int argc, char ** argv)
{
    srand( time(NULL) );
    int num = 0;
    for(int i = 0; i < 50000; ++i){
        uint64_t x = rand();
        (next_pow2(x) - builtin_pow2(x)) ? :num++;
    }
    num ? printf("PASS!\n") : printf("FAIL\n");
    return 0;
}