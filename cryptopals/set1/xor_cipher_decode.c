#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "include/hex.h"
#include "include/xor_decode_single_string.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        return 1;
    }

    int bytes_count;
    char *bytes = hex_decode(argv[1], &bytes_count);
    if (!bytes) {
        return 1;
    }

    char *alphabet = "abcdefghijklmnopqrstuvwxyz";

    float english_frequencies[256] = {};
    fill_with_english_frequencies(english_frequencies);

    struct decoded *x = xor_decode(bytes, bytes_count, alphabet, english_frequencies);
    if (!x) {
        return 1;
    }

    (void)printf("%d\n%f\n%s\n", x->key, x->score, x->text);

    free(x->text);
    free(x);

    free(bytes);

    return 0;
}
