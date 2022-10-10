.PHONY : main

CC := gcc
CFLAGS := -I.

INC_FILE := function.h

%.o: %.c $(INC_FILE)
	$(CC) -c -o $@ $<

main: main.o function.o
	$(CC) -o $@ main.o function.o $(CFLAGS)
clean:
	rm -rf *.o
