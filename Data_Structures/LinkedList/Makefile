CC = gcc
CFLAGS = -g -Wall -std=c99

.PHONY: all build clean

SRC_DIR = src

all: build

build: linked_list

linked_list.o: ${SRC_DIR}/linked_list.c ${SRC_DIR}/linked_list.h
	${CC} ${CFLAGS} -c ${SRC_DIR}/linked_list.c -o $@

main.o: ${SRC_DIR}/main.c ${SRC_DIR}/linked_list.h
	${CC} ${CFLAGS} -c ${SRC_DIR}/main.c -o $@

linked_list: main.o linked_list.o ${SRC_DIR}/linked_list.h
	${CC} ${CFLAGS} main.o linked_list.o -o $@

clean:
	rm *.o linked_list