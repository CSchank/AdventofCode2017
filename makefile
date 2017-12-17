CFLAGS = -Wall -g -ansi -O2 -std=c99
UTILS = readlines.o split.o printart.o

day1a: day1a.o $(UTILS)
	$(CC) -o $@ day1a.o $(UTILS)

day2: day2.o $(UTILS)
	$(CC) -o $@ day2.o $(UTILS)

day3: day3.o $(UTILS)
	$(CC) -o $@ day3.o $(UTILS)

c: clean

clean:
	rm -rf *.o *~ day1a day2 day3