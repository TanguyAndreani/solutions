#include <stdlib.h>

char BASE64[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

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
