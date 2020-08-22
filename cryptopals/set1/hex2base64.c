#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/hex.h"
#include "include/bytes_to_b64.h"

void print_usage(char *progname);

int main(int argc, char *argv[])
{
    if (argc == 2 && argv[1][0] != '-') {
        char *b64 = bytes2base64(argv[1], strlen(argv[1]));
        if (!b64) {
            return 1;
        }

        (void)printf("%s\n", b64);

        free(b64);

        return 0;
    }

    else if (argc == 3 && !strcmp(argv[1], "-x")) {
        int len;
        char *bytes = hex_decode(argv[2], &len);
        if (!bytes) {
            return (1);
        }

        char *b64 = bytes2base64(bytes, len);
        if (!b64) {
            return (1);
        }

        (void)printf("%s\n", b64);

        free(b64);

        free(bytes);

        return 0;
    }

    else if (argc >= 2 && !strcmp(argv[1], "-h")) {
        print_usage(argv[0]);
        return 0;
    }

    print_usage(argv[0]);
    return 1;
}

void print_usage(char *progname)
{
    printf("USAGE\n");
    printf("    %s [-x|-h] text\n\n", progname);
    printf("DESCRIPTION\n");
    printf("            text to base64\n");
    printf("    -x      hexadecimal to base64\n");
    printf("    -h      print usage\n\n");
    printf("EXAMPLES\n");
    printf("    %s \"I'm killing your brain like a poisonous mushroom\"\n", progname);
    printf("    => SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t\n\n");
    printf("    %s -x \"49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d\"\n", progname);
    printf("    => SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t\n");
}
