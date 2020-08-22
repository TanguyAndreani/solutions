#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "../include/hex.h"
#include "../include/utils.h"
#include "../include/xor_decode_single_string.h"

/* scores above which we just ignore the string */
const float limit = 8.0;

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

void compute_frequency(char *s, char *letters, float *dest)
{
    int slen = strlen(s);
    for (int j = 0; s[j]; j++) {
        dest[(int)downcase(s[j])]++;
    }
    for (int j = 0; letters[j]; j++) {
        dest[(int)letters[j]] /= (float)slen;
    }
}

float compute_score(float *sentence_frequencies, float *language_frequencies, char *letters)
{
    float score = 0.0;
    for (int i = 0; letters[i]; i++) {
        score += fabs(language_frequencies[(int)letters[i]] - sentence_frequencies[(int)letters[i]]);
    }
    return score;
}

struct decoded *xor_decode(char *s, int slen, char *alphabet, float *language_frequencies)
{
    float scores[256];
    for (int i = 0; i < 256; i++) {
        scores[i] = 999.0;
    }

    struct decoded *result = malloc(sizeof(struct decoded));
    if (!result) {
        return NULL;
    }

    int bufsize = slen + 1;
    char *buf = malloc(bufsize);
    if (!buf) {
        return NULL;
    }
    memset(buf, 0, bufsize);

    for (int key = 0; key < 255; key++) {
        int has_space = 0;
        for (int j = 0; j < slen; j++) {
            int dec_c = s[j] ^ key;

            if ((dec_c < 32 || dec_c > 127) && dec_c != '\n')
                goto next;

            if (dec_c == ' ')
                has_space = 1;

            buf[j] = dec_c;
        }

        if (!has_space) {
            goto next;
        }

        float sentence_frequencies[256] = {0};
        compute_frequency(buf, alphabet, sentence_frequencies);

        scores[key] = compute_score(sentence_frequencies, language_frequencies, alphabet);

        continue;

next:
        ;
    }

    int min_score_key = 0;
    for (int i = 0; i < 255; i++) {
        if (scores[min_score_key] > scores[i]) {
            min_score_key = i;
        }
    }

    if (scores[min_score_key] >= limit) {
        free(buf);
        return NULL;
    }

    for (int i = 0; i < slen; i++) {
        buf[i] = s[i] ^ min_score_key;
    }

    result->text = buf;
    result->key = min_score_key;
    result->score = scores[min_score_key];

    return result;
}
