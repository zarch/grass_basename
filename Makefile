CC=gcc
CFLAGS=-I.
DEPS = basename.h
OBJ = test.o basename.o
LIBS=-lm

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f *.o *~ test