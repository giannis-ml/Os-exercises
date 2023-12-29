# Makefile

CC=gcc

CFLAGS= -Wall -Werror -g -I$(INCLUDE)

MODULE1 = module.c
INCLUDE = module.h

OBJ1= mysort.o
OBJ2= module.o

EXEC= mysort.c

PROGRAM= mysort

DATA_FILE = TestData-Proj2-03NOV2023/voters50.bin

NUM_OF_CHILDREN = 4

SORTING1 = sorting1.c

SORTING2 = sorting2.c

all: $(PROGRAM)

$(PROGRAM): $(OBJ1) $(OBJ2)
	$(CC) -o  $(PROGRAM) $(OBJ1) $(OBJ2) -lm

$(OBJ1): $(EXEC)
	$(CC) -c $(EXEC)

$(OBJ2): $(MODULE1)
	$(CC) -c $(MODULE1)



clean:
	rm *.o $(PROGRAM) 

run: $(PROGRAM)
	./$(PROGRAM) -i $(DATA_FILE) -k $(NUM_OF_CHILDREN) -e1 $(SORTING1) -e2 $(SORTING2)