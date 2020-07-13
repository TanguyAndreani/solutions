#include "utils.h"

long gcd(long a, long b)
{
    a = absl(a);
    b = absl(b);

    long dividend = maxl(a, b);
    long divisor = minl(a, b);

    long remainder = 0;
    long quotient = 0;

    while (1) {
        euclidean_division(dividend, divisor, &quotient, &remainder);
        if (remainder == 0)
            return divisor;
        else {
            dividend = divisor;
            divisor = remainder;
        }
    }

    return -1;
}