# Makefile

CC=gcc

CFLAGS= -Wall -Werror -g -I$(INCLUDE)

MODULE1 = module.c
INCLUDE = module.h

OBJ1= index.o
OBJ2= module.o

EXEC= index.c

PROGRAM= mvote

REGISTERED_VOTERS= voters50.csv
KEY_PER_BUCKET= 1

all: $(PROGRAM)

$(PROGRAM): $(OBJ1) $(OBJ2)
	$(CC) -o  $(PROGRAM) $(OBJ1) $(OBJ2) 

$(OBJ1): $(EXEC)
	$(CC) -c $(EXEC)

$(OBJ2): $(MODULE1)
	$(CC) -c $(MODULE1)



clean:
	rm *.o $(PROGRAM) 

run: $(PROGRAM)
	./$(PROGRAM) -f $(REGISTERED_VOTERS) -b $(KEY_PER_BUCKET)