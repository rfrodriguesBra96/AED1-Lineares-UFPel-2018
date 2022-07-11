CC=gcc

CFLAGS=-Wall -Wextra -Werror -O0 -g -std=c11 -I.. 
LDLIBS=-lm

all: teste
	./teste

pilha.o: pilha.c
	

# Supondo que está usando a implementação de lista implementada anteriormente
teste:  pilha.o teste.c

clean:
	rm -f pilha.o teste