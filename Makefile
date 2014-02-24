OBJECTS = client.o
CC = gcc

client.out: main.c $(OBJECTS)
	$(CC) -o $@ $^

clean:
	rm -f client.out $(OBJECTS)