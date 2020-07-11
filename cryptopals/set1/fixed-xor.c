#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hex.h"

#include "fixed-xor.h"

int main(int argc, char *argv[])
{
    if (argc == 3) {

        int len1;
        char *bytes1 = hex_decode(argv[1], &len1);
        if (!bytes1)
            return (1);

        int len2;
        char *bytes2 = hex_decode(argv[2], &len2);
        if (!bytes2)
            return (1);

        if (len2 < len1)
            return (2);

        xor_strings_in_place(bytes1, bytes2, len1);

        int result_len;
        char *result = hex_encode(bytes1, &result_len, len1);
        printf("%s\n", result);

        free(result);
        free(bytes1);
        free(bytes2);
    }

    else if (argc >= 2 && !strcmp(argv[1], "-h")) {
        print_usage(argv[0]);
    }

    return (0);
}

void xor_strings_in_place(char *dest, char *src, int dest_len)
{
    for (int i = 0; i < dest_len; i++) {
        dest[i] ^= src[i];
    }
}

void print_usage(char *progname)
{
    printf("USAGE\n");
    printf("    %s hex_string1 hex_string2\n\n", progname);
    printf("EXAMPLES\n");
    printf("    %s 1c0111001f010100061a024b53535009181c 686974207468652062756c6c277320657965\n", progname);
    printf("    => 746865206b696420646f6e277420706c6179\n");
}