CC=g++
CFLAGS=-I.
DEPS =
OBJ = randomCards.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

randomCards: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 

.PHONY: clean

clean:
	rm -f randomCards.o randomCards
