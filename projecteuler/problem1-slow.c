#include <stdio.h>

const int n = 1000;

int main(void)
{
    int sum;

    for (int i = 0; i < n; i++)
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;

    printf("%d\n", sum);

    return (0);
}