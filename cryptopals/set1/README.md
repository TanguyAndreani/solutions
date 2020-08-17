# Cryptopals set1

## Important note

Most of these takes *hexadecimal* strings as input. But we don't manipulate them as is. We use the `hex_decode` function like that:

```c
int bytes_count;
hex_decode("6d757368726f6f6d", &bytes_count);
// => "mushroom"
```

## Binaries

|File|Description|
|----|----------|
|fixed-xor|xors two hexadecimal strings together|
|hex2base64|convert an hexadecimal string to its base64 representation|
|xor_cipher_decode|bruteforce a xor-ed string and compute a score to select the most probable key|
|xor_cipher_detect|will call `xor_decode()` on several hexadecimal string and select the best decoded string|

## Functions

|Name|File|Description|
|----|-----|----------|
|hex_decode|lib/hex.c|convert the hexadecimal representation of a string to the corresponding ascii string|
|hex_encode|lib/hex.c|convert an ascii string to it's hexadecimal representation|
|xor_string_in_place|lib/xor_string_in_place.c|simply perform a bitwise xor on a string against another string|
|xor_decode|lib/xor_decode_single_string.c|bruteforce a xor-ed string and compute a score to select the most probable key|
