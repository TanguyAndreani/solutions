#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char BASE16[] = "0123456789abcdef";

int digit_to_int(char c, char *base, int base_n)
{
    for (int i = 0; i < base_n; i++) {
        if (base[i] == c) {
            return (i);
        }
    }
    return (0);
}

char int_to_digit(int c, char *base, int base_n)
{
    if (c >= 0 && c <= base_n)
        return (base[c]);
    return (0);
}

char *hex_decode(char *str, int *bytes_count)
{
    int len = strlen(str);
    int result_len = len / 2 + 1;

    char *bytes = malloc(result_len);
    if (!bytes)
        return (NULL);

    int j = 0;
    for (int i = 0; i < len - 1; i += 2, j++) {
        bytes[j] = (digit_to_int(str[i], BASE16, 16) << 4) +
                    digit_to_int(str[i + 1], BASE16, 16);
    }

    bytes[j] = '\0';
    *bytes_count = j;

    return (bytes);
}

char *hex_encode(char *str, int *bytes_count, int len)
{
    int result_len = len * 2 + 1;

    char *bytes = malloc(result_len);
    if (!bytes)
        return (NULL);

    int j = 0, i = 0;
    for (; i < result_len - 1; i += 2, j++) {
        bytes[i] = int_to_digit(str[j] >> 4, BASE16, 16);
        bytes[i + 1] = int_to_digit(str[j] & 15, BASE16, 16);
    }

    bytes[i] = '\0';
    *bytes_count = i;

    return (bytes);
}
