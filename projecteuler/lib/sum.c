#include "utils.h"

long sum(long n)
{
    if (n < 0)
        return (0);

    return ((n * (n + 1)) / 2);
}