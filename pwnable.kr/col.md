# col

```c
#include <stdio.h>
#include <string.h>
unsigned long hashcode = 0x21DD09EC;
unsigned long check_password(const char* p){
	int* ip = (int*)p;
	int i;
	int res=0;
	for(i=0; i<5; i++){
		res += ip[i];
	}
	return res;
}

int main(int argc, char* argv[]){
	if(argc<2){
		printf("usage : %s [passcode]\n", argv[0]);
		return 0;
	}
	if(strlen(argv[1]) != 20){
		printf("passcode length should be 20 bytes\n");
		return 0;
	}

	if(hashcode == check_password( argv[1] )){
		system("/bin/cat flag");
		return 0;
	}
	else
		printf("wrong passcode.\n");
	return 0;
}
```

`check_password` will treat a 20 bytes array like a 5 integers array. One integer is 4 bytes here. Then it computes the sum. So we
need to have five 4 bytes numbers which will amount to `0x21DD09EC`. We just do the integer division of this number by 5. We obtain
`5 * 0x6c5cec8 + 4`, so we need four times `0x6c5cec8` and one time `0x6c5cecc`.

But how to encode that? We will just send raw bytes to the program, we'll send 20 bytes in total, and we'll take care of reversing them
to take the endianness of the machine into account.

## command

```bash
echo $(ruby -e 'print "\x06\xc5\xce\xc8".reverse*4 + "\x06\xc5\xce\xcc".reverse') \
  | ssh col@pwnable.kr -p2222 "xargs ./col"
```
