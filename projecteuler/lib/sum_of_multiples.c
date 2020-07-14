#include "utils.h"

long sum_of_multiples(long n, long mod)
{
    return (n * sum(mod / n));
}