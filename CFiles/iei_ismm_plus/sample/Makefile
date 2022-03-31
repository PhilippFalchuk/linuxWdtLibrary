# Makefile for sample programs

CC=gcc
CFLAGS := -Wall -O2 -I../include
LD_LIB := -L../lib -lismmplus 
                                                     
all:test 

test:
	gcc $(CFLAGS) -o diotest diotest.c $(LD_LIB)
	gcc $(CFLAGS) -o dioloop dioloop.c $(LD_LIB)
	gcc $(CFLAGS) -o wdttest wdttest.c $(LD_LIB)
clean:
	rm -f *.o diotest wdttest dioloop
