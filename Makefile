CC = gcc
AR = ar
CFLAGS = -Wall -Werror

all: graph

graph: main.o algorithms.o priorityQueue.o
	${CC} ${CFLAGS} -o graph main.o algorithms.o priorityQueue.o


algorithms.o: algorithms.c graph.h minQueue.h
	${CC} ${CFLAGS} -c  algorithms.c

priorityQueue.o:priorityQueue.c graph.h minQueue.h
	${CC} ${CFLAGS} -c priorityQueue.c

main.o: main.c graph.h minQueue.h
	${CC} ${CFLAGS} -c main.c

clean:
	rm -f *.a *.o graph