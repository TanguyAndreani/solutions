# fd

## source code

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char buf[32];
int main(int argc, char* argv[], char* envp[]){
	if(argc<2){
		printf("pass argv[1] a number\n");
		return 0;
	}
	int fd = atoi( argv[1] ) - 0x1234;
	int len = 0;
	len = read(fd, buf, 32);
	if(!strcmp("LETMEWIN\n", buf)){
		printf("good job :)\n");
		system("/bin/cat flag");
		exit(0);
	}
	printf("learn about Linux file IO\n");
	return 0;

}
```

We want to enter this block:

```c
if(!strcmp("LETMEWIN\n", buf)){
  printf("good job :)\n");
	system("/bin/cat flag");
	exit(0);
}
```

So we need to set `buf` to `"LETMEWIN\n"`.

`fd` depends on this statement a few lines above:

```c
len = read(fd, buf, 32);
```

Where we have control on `fd` a file descriptor. But there is no `open` in this code, so we have to se fd to match an already opened file descriptor, `0`
for example, which is linked to `stdin`, the standard input by default.

We have `fd = atoi( argv[1] ) - 0x1234`. So we need `atoi(argv[1]) = 0x1234`. So we need to pass 4660 as an argument to `./fd`, then the call to read won't fail.

We can now enter the `LETMEWIN` string, and the flag will be displayed.

### Command

```bash
echo -ne "LETMEWIN\n" | ssh fd@pwnable.kr -p2222 "./fd 4660"
```
