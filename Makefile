CFLAGS=-std=c11 -g -static

9cc: 9cc.c
test: 9cc
				sh test.sh

clean:
				rm -f 9cc *.0 *~ tmp*

.PHONY: test clean				