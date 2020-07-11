CFLAGS	=	-O0 -Wall -Werror

all: hex2base64 fixed-xor

hex2base64: hex.o hex2base64.o

fixed-xor: fixed-xor.o hex.o

clean:
	rm -f *.o
	rm -f hex2base64