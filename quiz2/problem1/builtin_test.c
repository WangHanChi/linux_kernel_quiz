#include <stdint.h>
#include <stdio.h>
static inline uint64_t pow2(uint8_t e) { return ((uint64_t)1) << e; }


int main(int argc, char **argv) {

  uint64_t a = 1025;
  
  printf("%d\n", 63 - __builtin_clzl(a));

  return 0;
}