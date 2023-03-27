#include "fastdiv.h"

/* unsigned 32-bit log2, required for magic constant generation */
static inline uint32_t ulog2(uint32_t v)
{
    uint32_t r, shift;
    r = (v > 0xFFFF) << 4;
    v >>= r;
    shift = (v > 0xFF) << 3;
    v >>= shift;
    r |= shift;
    shift = (v > 0xF) << 2;
    v >>= shift;
    r |= shift;
    shift = (v > 0x3) << 1;
    v >>= shift;
    r |= shift;
    r |= (v >> 1);
    return r;
}

void fastdiv(div_t *d, uint32_t divisor)
{
    d->odiv = divisor;
    uint32_t l = ulog2(divisor);
    if (divisor & (divisor - 1)) { /* non-power-of-two? */
        uint64_t m = 1ULL << (l + 32);
        d->mul = (uint32_t) (m / divisor);
        uint32_t r = (uint32_t) m - d->mul * divisor;
        uint32_t e = divisor - r;
        if (e < (1UL << l)) {
            ++d->mul;
            d->add = 0;
        } else {
            d->add = d->mul;
        }
        d->shift = 32 + l;
    } else { /* power-of-two divisor */
        d->mul = 2;
        d->add = 0;
        d->shift = (divisor <= 1 ? 0 : l);
    }
}

/* fast division for 'small enough' unsigned numbers without intermediates
 * overflowing 64 bits.
 * see https://github.com/lemire/constantdivisionbenchmarks, "lkk" algorithm.
 */

/* up to 21 is fine to keep all intermediates in 64-bit range */
#define FASTDIV_B 21

/* 23 zeros and rest (41 = FASTDIV_C-1) ones */
#define FASTDIV_C (2 * FASTDIV_B)

#define FASTDIV_CMASK ((UINT64_C(1) << FASTDIV_C) - 1)
#define FASTDIV_SAFEMAX ((1U << FASTDIV_B) - 1U)

void fastdiv_bounded(div_t *d, uint32_t const divisor, uint32_t bound)
{
    uint32_t fastdiv_ops = 0U;
    fastdiv(d, divisor);
    if (d->mul != 1U)
        ++fastdiv_ops;
    if (d->add != 0U)
        ++fastdiv_ops;
    if (d->shift != 0U)
        ++fastdiv_ops;

    /* Often the full-range method finds a 2-op method with d->add=0U
     * If not, try another method ok for 21-bit numerator and denominator
     */
    if (fastdiv_ops == 0 && bound > 0U && bound <= FASTDIV_SAFEMAX) {
        d->mul = FASTDIV_CMASK / divisor + 1;
        d->add = 0U;
        d->shift = 21;
    }
}