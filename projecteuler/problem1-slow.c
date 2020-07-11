#include <stdio.h>
#include <stdlib.h>

int n = 1000;

int main(int argc, char *argv[])
{
    if (argc >= 2)
        n = atoi(argv[1]);

    int sum;

    for (int i = 0; i < n; i++)
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;

    printf("%d\n", sum);

    return (0);
}