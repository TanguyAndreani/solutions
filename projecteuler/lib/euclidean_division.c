#include "utils.h"

void euclidean_division(long a, long b, long *q, long *r)
{
    *q = 0;

    long sign = b > 0 ? 1 : -1;
    b = absl(b);

    if (a >= 0) {
        while (a >= b) {
            a -= b;
            (*q)++;
        }
    } else {
        while (a < 0) {
            a += b;
            (*q)--;
        }
    }

    *r = a;
    *q *= sign;

    return;
}