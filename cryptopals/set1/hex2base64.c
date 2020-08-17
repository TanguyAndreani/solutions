#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hex.h"

#include "hex2base64.h"

char BASE64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int main(int argc, char *argv[])
{
    if (argc == 2 && argv[1][0] != '-') {
        char *b64 = bytes2base64(argv[1], strlen(argv[1]));
        if (!b64)
            return (1);

        printf("%s\n", b64);

        free(b64);
    }

    else if (argc == 3 && !strcmp(argv[1], "-x")) {
        int len;
        char *bytes = hex_decode(argv[2], &len);
        if (!bytes)
            return (1);

        char *b64 = bytes2base64(bytes, len);
        if (!b64)
            return (1);

        printf("%s\n", b64);

        free(b64);

        free(bytes);
    }

    else if (argc >= 2 && !strcmp(argv[1], "-h")) {
        print_usage(argv[0]);
    }

    return (0);
}

/*void print_bytes2base64(char *bytes, int len)
{
    int i = 0;
    for (; i < len; i += 3) {
        int b1 = bytes[i];
        int b2 = (i + 1 >= len) ? 0 : bytes[i + 1];
        int b3 = (i + 2 >= len) ? 0 : bytes[i + 2];

        int three_in_one = (b1 << 16) + (b2 << 8) + b3;

        int n0 = (three_in_one >> 18) & 63;
        int n1 = (three_in_one >> 12) & 63;
        int n2 = (three_in_one >> 6) & 63;
        int n3 = (three_in_one) & 63;

        putchar(BASE64[n0]);
        putchar(BASE64[n1]);
        putchar((i + 1 >= len) ? '=' : BASE64[n2]);
        putchar((i + 2 >= len) ? '=' : BASE64[n3]);
    }

    putchar('\n');
}*/

char *bytes2base64(char *bytes, int len)
{
    char *buf = malloc(len * (4.0/3.0) + 1);
    if (!buf)
        return NULL;

    int i = 0;
    int buf_idx = 0;
    for (; i < len; i += 3) {
        int bs[3];
        bs[0] = bytes[i];
        bs[1] = (i + 1 >= len) ? 0 : bytes[i + 1];
        bs[2] = (i + 2 >= len) ? 0 : bytes[i + 2];

        int ss[4];
        ss[0] = (bs[0] >> 2);
        ss[1] = ((bs[0] & 3) << 4) + (bs[1] >> 4);
        ss[2] = ((bs[1] & 15) << 2) + (bs[2] >> 6);
        ss[3] = bs[2] & 63;

        buf[buf_idx++] = BASE64[ss[0]];
        buf[buf_idx++] = BASE64[ss[1]];
        buf[buf_idx++] = (i + 1 >= len) ? '=' : BASE64[ss[2]];
        buf[buf_idx++] = (i + 2 >= len) ? '=' : BASE64[ss[3]];
    }

    buf[buf_idx] = '\0';

    return buf;
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
