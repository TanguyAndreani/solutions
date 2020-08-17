#ifndef HEX2BYTES_H
#define HEX2BYTES_H

/*
 * ex: digit_to_int('a', "0123456789abcdef", 16) => 10
 * side effects: none
 */
char digit_to_int(char c, char *base, int base_n);

/*
 * ex: int_to_digit(10, "0123456789abcdef", 16) => 'a'
 * side effects: none
 */
char int_to_digit(int c, char *base, int base_n);

/*
 * ex: hex_decode("6d757368726f6f6d", NULL) => "mushroom"
 * side effects: puts the size of the new string in bytes_count,
 * allocates space for the result string.
 */
char *hex_decode(char *str, int *bytes_count);
char *hex_encode(char *str, int *bytes_count, int len);

#endif