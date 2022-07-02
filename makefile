CC=gcc

FLAGS= -Wall -g


all:signals  

signals: signals.c

	$(CC) $(FLAGS) signals.c -o signals

.PHONY: clean all

clean:

	rm -f *.o *.a  signals