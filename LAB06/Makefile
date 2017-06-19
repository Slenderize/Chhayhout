
CC = gcc
CFLAGS = -Wall --std=c99
DRIVER_OBJECTS = main.o my_string.o
TEST_OBJECTS = unit_test.o test_def.o my_string.o

all: string_driver unit_test

string_driver: $(DRIVER_OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(DRIVER_OBJECTS)

unit_test: $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o unit_test $(TEST_OBJECTS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

my_string.o: my_string.c my_string.h generic.h
	$(CC) $(CFLAGS) -l my_string.h -l generic.h -c my_string.c -o my_string.o

unit_test.o: unit_test.c unit_test.h
	$(CC) $(CFLAGS) -l unit_test.h -c unit_test.c -o unit_test.o

test_def.o: test_def.c
	$(CC) $(CFLAGS) -c test_def.c -o test_def.o

clean:
	rm string_driver unit_test main.o $(TEST_OBJECTS)