.PHONY : main

CC := gcc
CFLAGS := -I.

INC_FILE := linked_list.h

%.o: %.c $(INC_FILE)
	$(CC) -c -o $@ $<

main: main.o linked_list.o
	$(CC) -o $@ main.o linked_list.o $(CFLAGS)
clean:
	rm -rf *.o

#token: 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
