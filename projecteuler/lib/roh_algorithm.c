#include "utils.h"

/*
    x ← 2
    y ← 2
    d ← 1

    while d = 1:
        x ← g(x)
        y ← g(g(y))
        d ← gcd(|x - y|, n)

    if d = n: 
        return failure
    else:
        return d
*/

long roh_algorithm(long n, long (*f)(long), long start)
{
    long x = start;
    long y = start;
    long d = 1;

    while (d == 1) {
        x = f(x);
        y = f(f(y));
        d = gcd(absl(x - y), n);

    }

    if (d == n)
        return -1;
    
    return d;
}