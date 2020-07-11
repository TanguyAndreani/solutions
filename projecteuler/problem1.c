#include <stdio.h>
#include <stdlib.h>

/*
 * This is the most efficient way I found. I just tried to reduce as most as
 * possible the use modulos.
 *
 * Here are some benchmarks for n=100'000'000:
 *
 * $ time ./problem1-slow
 * real 0m0,288s
 * user    0m0,288s
 * sys 0m0,000s
 *
 * $ time ./problem1
 * real    0m0,132s
 * user    0m0,132s
 * sys 0m0,000s
 */

int n = 1000;

int main(int argc, char *argv[])
{
    if (argc >= 2)
        n = atoi(argv[1]);

    int sum = 0;

    for (int i = 0; i < n; i += 3)
        sum += i;

    for (int i = 0, j = 0; i < n; i += 5, j++)
        if (j % 3 != 0)
            sum += i;

    printf("%d\n", sum);

    return (0);
}