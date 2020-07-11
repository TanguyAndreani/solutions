#include <stdio.h>
#include <stdlib.h>

long long n = 4000000;

int main(int argc, char *argv[])
{
    if (argc >= 2)
        n = atoll(argv[1]);

    long long n1 = 1, n2 = 2;
    long long s = 2;

    while (n1 < n) {
        n1 = n1 + n2;
        n2 = n1 + n2;

        if (n1 % 2 == 0)
            s += n1;

        if (n2 % 2 == 0)
            s += n2;
    }

    printf("%lld\n", s);

    return (0);
}