#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/utils.h"

char BASE16[] = "0123456789abcdef";

char *hex_decode(char *str, int *bytes_count)
{
    int len = strlen(str);
    int result_len = len / 2 + 1;

    char *bytes = malloc(result_len);
    if (!bytes)
        return (NULL);

    int j = 0;
    for (int i = 0; i < len - 1; i += 2, j++) {
        bytes[j] = (find_first_occurence_position(str[i], BASE16, 16) << 4) +
                    find_first_occurence_position(str[i + 1], BASE16, 16);
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
        bytes[i] = get_nth_or_zero(str[j] >> 4, BASE16, 16);
        bytes[i + 1] = get_nth_or_zero(str[j] & 15, BASE16, 16);
    }

    bytes[i] = '\0';
    *bytes_count = i;

    return (bytes);
}
