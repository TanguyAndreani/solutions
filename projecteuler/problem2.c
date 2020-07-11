#include <stdio.h>
#include <stdlib.h>

/*
 * This one is not a success. It works, but it isn't faster than its obvious
 * counterpart. Again, I tried to reduce the use of modulo.
 * I neglected the fact that the fibonacci sequence grows rapidly, so
 * it doesn't have a lot of terms under the upper limit n.
 *
 * But hey, at least there are no modulo in this code :)
 */

long long n = 4000000;

int main(int argc, char *argv[])
{
    if (argc >= 2)
        n = atoll(argv[1]);

    long long s = 0;
    long long n1 = 0;
    long long n2 = 1;

    while (n1 < n) {
        long long old_n1 = n1;
        s += n1;
        n1 = n1 + n2 * 2;
        n2 = n1 + n2 + old_n1;
    }

    printf("%lld\n", s);

    return (0);
}