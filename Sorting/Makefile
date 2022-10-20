.PHONY : main

CC := gcc
CFLAGS := -I.
LIB := lib

INC_FILE := Sorting.h

%.o: $(LIB)/Sorting.c $(INC_FILE)
	$(CC) -c -o $@ $<

main: main.o $(LIB)/Sorting.o
	$(CC) -o $@ main.o $(LIB)/Sorting.o $(CFLAGS)
clean:
	rm -rf *.o $(LIB)/*.o main


#token: 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
