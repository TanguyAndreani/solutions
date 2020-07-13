#include <stdio.h>
#include <stdlib.h>

#include "lib/utils.h"

long n = 600851475143;

int main(int argc, char *argv[])
{
    if (argc >= 2) {
        n = strtol(argv[1], NULL, 10);
    }

    for (int i = 999; i >= 0; i--) {
        if (n % prime[i] == 0) {
            printf("%ld\n", prime[i]);
            break;
        }
    }
}