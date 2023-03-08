#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "cpucycles.h"

#define NUM 100

#ifdef CYCLE
#define CHUNK_SIZE CYCLE
#else /* DEBUG */
#define CHUNK_SIZE 80000
#endif /* DEBUG */


size_t count_utf8(const char *buf, size_t len)
{
    const int8_t *p = (const int8_t *) buf;
    size_t counter = 0;
    for (size_t i = 0; i < len; i++) {
        /* -65 is 0b10111111, anything larger in two-complement's should start
         * new code point.
         */
        if (p[i] > -65)
            counter++;
    }
    return counter;
}

void fix_string(char *s)
{
    memset(s, 'a', CHUNK_SIZE - 1);
    s[CHUNK_SIZE - 1] = '\0';
}

void random_string(char *s)
{
    for (size_t i = 0; i < CHUNK_SIZE - 1; i++) {
        int x = rand();
        s[i] = x /*% 127 + 1*/;
    }
    s[CHUNK_SIZE - 1] = '\0';
}

size_t swar_count_utf8(const char *buf, size_t len)
{
    const uint64_t *qword = (const uint64_t *) buf;
    const uint64_t *end = qword + (len >> 3);

    size_t count = 0;
    for (; qword != end; qword++) {
        const uint64_t t0 = *qword;
        const uint64_t t1 = ~t0;
        const uint64_t t2 = t1 & 0x04040404040404040llu;
        const uint64_t t3 = t2 + t2;
        const uint64_t t4 = t0 & t3;
        count += __builtin_popcountll(t4);
    }

    count = (1 << 3) * (len / 8)  - count;
    count += (len & 7) ? count_utf8((const char *) end, len & 7) : 0;

    return count;
}

int main(int argc, char **argv)
{
    srand( time(NULL) );
    char *s = malloc(sizeof(char) * CHUNK_SIZE);
    random_string(s);
    uint64_t normal_ticks[2], swar_ticks[2];
    size_t count0, count1;
    normal_ticks[0] = cpucycles();
    count0 = count_utf8(s, CHUNK_SIZE);
    normal_ticks[1] = cpucycles();

    swar_ticks[0] = cpucycles();
    count1 = swar_count_utf8(s, CHUNK_SIZE);
    swar_ticks[1] = cpucycles();
    
    
    printf("\n\nNormal\t method: %ld\nCounts of UTF-8 : %ld\n\n", normal_ticks[1] - normal_ticks[0], count0);
    printf("SWAR\t method: %ld\nCounts of UTF-8 : %ld\n", swar_ticks[1] - swar_ticks[0], count1);
    free(s);
    printf("\n\nDone !\n");
    return 0;
}