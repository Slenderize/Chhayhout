CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = main.o generic_vector.o my_string.o

driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o driver $(OBJECTS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

generic_vector.o: generic_vector.c
	$(CC) $(CFLAGS) -c generic_vector.c
	
my_string.o: my_string.c
	$(CC) $(CFLAGS) -c my_string.c

clean:
	rm driver $(OBJECTS)