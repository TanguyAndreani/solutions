void xor_string_in_place(char *dest, char *src, int dest_len)
{
    for (int i = 0; i < dest_len; i++) {
        dest[i] ^= src[i];
    }
}
