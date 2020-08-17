#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "include/hex.h"
#include "include/xor_decode_single_string.h"

/*
 * Frequency per letter in the English alphabet
 * source: https://gist.github.com/silveira/4661770
 */
void fill_with_english_frequencies(float *tab)
{
    tab['a'] = 0.082;
    tab['b'] = 0.015;
    tab['c'] = 0.028;
    tab['d'] = 0.043;
    tab['e'] = 0.127;
    tab['f'] = 0.022;
    tab['g'] = 0.020;
    tab['h'] = 0.061;
    tab['i'] = 0.070;
    tab['j'] = 0.002;
    tab['k'] = 0.008;
    tab['l'] = 0.040;
    tab['m'] = 0.024;
    tab['n'] = 0.067;
    tab['o'] = 0.075;
    tab['p'] = 0.019;
    tab['q'] = 0.001;
    tab['r'] = 0.060;
    tab['s'] = 0.063;
    tab['t'] = 0.091;
    tab['u'] = 0.028;
    tab['v'] = 0.010;
    tab['w'] = 0.023;
    tab['x'] = 0.001;
    tab['y'] = 0.020;
    tab['z'] = 0.001;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 3;

    int bytes_count;
    char *bytes = hex_decode(argv[1], &bytes_count);
    if (!bytes) {
        return 2;
    }

    char *alphabet = "abcdefghijklmnopqrstuvwxyz";

    float english_frequencies[256] = {};
    fill_with_english_frequencies(english_frequencies);

    struct decoded *x = xor_decode(bytes, bytes_count, alphabet, english_frequencies);
    if (!x)
        return 1;

    printf("%d\n%f\n%s\n", x->key, x->score, x->text);

    free(x->text);
    free(x);

    free(bytes);

    return 0;
}
