#include <stdio.h>


int concatenatedBinary(int n)
{
    const int M = 1e9 + 7;
    int len = 0; /* the bit length to be shifted */
    /* use long here as it potentially could overflow for int */
    long ans = 0;
    for (int i = 1; i <= n; i++) {
        /* removing the rightmost set bit
         * e.g. 100100 -> 100000
         *      000001 -> 000000
         *      000000 -> 000000
         * after removal, if it is 0, then it means it is power of 2
         * as all power of 2 only contains 1 set bit
         * if it is power of 2, we increase the bit length
         */
        if (!(i & (i - 1)))
            len++;
        ans = (i | (ans << len)) % M;
    }
    return ans;
}

int concatenatedBinary_new(int n)
{
    const int M = 1e9 + 7;
    int len = 0; /* the bit length to be shifted */
    /* use long here as it potentially could overflow for int */
    long ans = 0;
    for (int i = 1; i <= n; i++) {

        len = 32 - __builtin_clz(i);
        ans = ((ans << len) % M + i) % M;
    }
    return ans;
}

int main(int argc, char **argv)
{
    int test1 = 1, test2 = 3, test3 = 12;
    printf("\ntest 1 : %d\n", concatenatedBinary(test1));
    printf("test 2 : %d\n", concatenatedBinary(test2));
    printf("test 3 : %d\n", concatenatedBinary(test3));
    printf("--------------------\n");
    printf("test 1 : %d\n", concatenatedBinary_new(test1));
    printf("test 2 : %d\n", concatenatedBinary_new(test2));
    printf("test 3 : %d\n", concatenatedBinary_new(test3)); 
    return 0;
}