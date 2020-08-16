CFLAGS	=	-O0 -Wall -Werror

all: hex2base64 fixed-xor xor_cipher_decode

hex2base64: hex.o hex2base64.o

fixed-xor: fixed-xor.o hex.o

xor_cipher_decode: xor_cipher_decode.o hex.o

clean:
	rm -f *.o
	rm -f hex2base64 xor_cipher_decode fixed-xor
