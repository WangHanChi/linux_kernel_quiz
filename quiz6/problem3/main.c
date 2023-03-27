#include <assert.h>
#include <stdio.h>

#include "fastdiv.h"

int main(int argc, char **argv)
{
    const uint64_t MAX_NUM = 1 << 16;
    const uint64_t MAX_DIV = 1 << 14;

    for (uint64_t d = 1U; d < MAX_DIV; ++d) {
        div_t fd;        /* general method */
        fastdiv(&fd, d); /* divide-by-d */
        const uint64_t mul = fd.mul, add = fd.add, shift = fd.shift;

        div_t fd2;                         /* bounded method optimization */
        fastdiv_bounded(&fd2, d, MAX_DIV); /* divide-by-d */
        const uint64_t mul2 = fd2.mul, add2 = fd2.add, shift2 = fd2.shift;
        assert(mul2 == 1U || add2 == 0U || shift2 == 0U);
        assert(add2 == 0U);
        for (uint64_t num = 0; num < MAX_NUM; ++num) {
            const uint64_t normal = num / d;
            const uint64_t general = (num * mul + add) >> shift;
            const uint64_t bounded = (num * mul2) >> shift2;
            assert(general == normal);
            assert(bounded == normal);
        }
    }
}