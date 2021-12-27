CC = gcc
AR = ar
CFLAGS = -Wall -Werror

all: graph

graph: main.o
	${CC} ${CFLAGS} -o graph main.o

main.o: main.c
	${CC} ${CFLAGS} -c main.c

clean:
	rm -f *.a *.o graph