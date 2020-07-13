CFLAGS=-O0 -Wall -Werror

UTILS_SRC	=	$(wildcard lib/*.c)
UTILS_OBJ	=	$(UTILS_SRC:.c=.o)

all: problem1 problem2 problem3 problem1-slow problem2-slow

problem1: problem1.o
	echo $(UTILS_SRC)

problem2: problem2.o

problem1-slow: problem1-slow.o

problem2-slow: problem2-slow.o

problem3: problem3.o $(UTILS_OBJ)

clean:
	rm -f $(BINS)
	rm -f test_suite
	find . -name '*.o' -exec rm {} \;

TEST_SRC=$(wildcard test/*.c lib/*.c)
TEST_OBJ=$(TEST_SRC:.c=.o)
test/test_suite: $(TEST_OBJ)

test_suite: test/test_suite
	mv test/test_suite test_suite