#pragma once

#include <stdint.h>

/** divide-by-\c odiv via mul-add-shift */
typedef struct {
    /* mul is uint32_t for fastdiv method,
     * but can be uint64_t for bounded method.
     */
    uint64_t mul;
    uint32_t add;
    uint32_t shift;
    uint32_t odiv; /* save original divisor for modulo calc */
} div_t;

/* - For \c N in \b uint32_t range,
 *   - but perhaps in a \c uint64_t register,
 * - find \c N/odiv by evaluating
 *   - \f$(N * mul + add) >> shift\f$
 * - using \b uint64_t intermediates.
 *
 * - Do not use for signed ops.
 * - \b Do use an additional mul-sub for a fast divmod op.
 *
 * For scalars, the compiler will automatically use a similar approach
 * for compile-time constants, but it can help in case of
 * runtime scalar division with very high repetition count.
 *
 * Power of two \c odiv should give mul by 1 and add zero.
 *
 * Essential number of jit ops is 3 in worst case, but better if
 * \c mul is one or \add is zero or \c shift is zero.
 */
void fastdiv(div_t *d, uint32_t const divisor);

/** For \c divisor<=bound O(2^21), we may be able
 * to find a \c fastdiv that has \c add==0.
 *
 * If used, this alternative method uses a 42-bit multiplier and right-shift
 * of 21.
 */
void fastdiv_bounded(div_t *d, uint32_t const divisor, uint32_t bound);