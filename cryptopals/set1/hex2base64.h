#ifndef HEX2BASE64_H
#define HEX2BASE64_H

/*
 * takes three bytes, divide them into four six bits chunks, and
 * output the corresponding char in BASE64
 */
char *bytes2base64(char *bytes, int len);

void print_usage(char *progname);

#endif
