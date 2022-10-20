.PHONY : main

CC := gcc
CFLAGS := -I.
LIB := lib

INC_FILE := Stack.h

%.o: $(LIB)/Stack.c $(INC_FILE)
	$(CC) -c -o $@ $<

main: main.o $(LIB)/Stack.o
	$(CC) -o $@ main.o $(LIB)/Stack.o $(CFLAGS)
clean:
	rm -rf *.o $(LIB)/*.o main

