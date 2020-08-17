char downcase(char c)
{
    if (c > 'A' && c < 'Z') {
        return c - ('A' - 'a');
    }
    return c;
}

int count_letter(char *s, char letter)
{
    int count = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == letter)
            count++;
    }
    return count;
}

int find_first_occurence_position(char c, char *s, int slen)
{
    for (int i = 0; i < slen; i++) {
        if (s[i] == c) {
            return (i);
        }
    }
    return (0);
}

char get_nth_or_zero(int c, char *base, int base_n)
{
    if (c >= 0 && c <= base_n)
        return (base[c]);
    return (0);
}
