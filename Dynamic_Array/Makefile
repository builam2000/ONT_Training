.PHONY : main

CC := gcc
CFLAGS := -I.
LIB := lib

INC_FILE := DynamicArray.h

%.o: $(LIB)/DynamicArray.c $(INC_FILE)
	$(CC) -c -o $@ $<

main: main.o $(LIB)/DynamicArray.o
	$(CC) -o $@ main.o $(LIB)/DynamicArray.o $(CFLAGS)
clean:
	rm -rf *.o $(LIB)/*.o main


#token: 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
