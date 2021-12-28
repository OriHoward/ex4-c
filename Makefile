CC = gcc
AR = ar
CFLAGS = -Wall -Werror

all: graph

graph: main.o algorithms.o
	${CC} ${CFLAGS} -o graph main.o algorithms.o


algorithms.o: algorithms.c graph.h
	${CC} ${CFLAGS} -c  algorithms.c

main.o: main.c graph.h
	${CC} ${CFLAGS} -c main.c

clean:
	rm -f *.a *.o graph