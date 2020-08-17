CFLAGS	=	-O0 -Wall -Werror

all: hex2base64 fixed-xor xor_cipher_decode

hex2base64: hex2base64.o lib/hex.o lib/bytes_to_b64.o

fixed-xor: fixed-xor.o lib/xor_string_in_place.o lib/hex.o

xor_cipher_decode: xor_cipher_decode.o lib/hex.o lib/xor_decode_single_string.o

clean:
	find . -name '*.o' -exec rm {} \;
	rm -f hex2base64 xor_cipher_decode fixed-xor
