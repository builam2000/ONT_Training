.PHONY : main

CC := gcc
CFLAGS := -I.
LIB := lib

INC_FILE := queue.h

%.o: $(LIB)/queue.c $(INC_FILE)
	$(CC) -c -o $@ $<

main: main.o $(LIB)/queue.o
	$(CC) -o $@ main.o $(LIB)/queue.o $(CFLAGS)
clean:
	rm -rf *.o $(LIB)/*.o main

