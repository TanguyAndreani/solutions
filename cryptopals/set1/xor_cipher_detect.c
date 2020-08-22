#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "include/hex.h"
#include "include/xor_decode_single_string.h"

int main(int argc, char *argv[])
{
    if (argc != 3) {
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input < 0) {
        return 1;
    }

    int max_lines = atoi(argv[2]);

    struct decoded **tab = malloc(sizeof(struct decoded *) * max_lines);
    if (!tab) {
        return 1;
    }

    char *alphabet = "abcdefghijklmnopqrstuvwxyz";

    float english_frequencies[256] = {};
    fill_with_english_frequencies(english_frequencies);

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    int line_count = 0;
    while ((nread = getline(&line, &len, input)) != -1 && line_count < max_lines) {
        if (line[nread - 1] == '\n')
            line[nread - 1] = '\0';

        int bytes_count;
        char *bytes = hex_decode(line, &bytes_count);
        if (!bytes) {
            return 1;
        }

        tab[line_count] = xor_decode(bytes, bytes_count, alphabet, english_frequencies);
        if (tab[line_count]) {
            line_count++;
        }

        free(bytes);
    }

    free(line);

    int min_score_line = 0;
    for (int j = 0; j < line_count; j++) {
        if (tab[j]->score < tab[min_score_line]->score) {
            min_score_line = j;
        }
    }

    (void)printf("%d\n%f\n%s",
        tab[min_score_line]->key,
        tab[min_score_line]->score,
        tab[min_score_line]->text
    );

    fclose(input);

    return (0);
}
