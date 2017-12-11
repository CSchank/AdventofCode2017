CFLAGS = -Wall -g -ansi -O2 -std=c99
OBJS1 = day1a.o readlines.o

day*a: $(OBJS1)
	$(CC) -o $@ $(OBJS1)

c: clean

clean:
	rm -rf $(OBJS1)  $(OBJS2) $(programs) *~ 