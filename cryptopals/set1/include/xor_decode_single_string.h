#ifndef XORDECODESINGLE_H
#define XORDECODESINGLE_H

struct decoded {
    int key;
    float score;
    char *text;
};

char downcase(char c);
int count_letter(char *s, char letter);
void compute_frequency(char *s, char *letters, float *dest);
float compute_score(float *sentence_frequencies, float *language_frequencies, char *letters);
struct decoded *xor_decode(char *s, int slen, char *alphabet, float *language_frequencies);

#endif
