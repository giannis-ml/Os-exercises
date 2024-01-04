#Makefile
SETUP = setup.c

READER = reader.c

FILENAME = SampleDataSetPrj3/SampleData4Proj3/accounts50.bin

RECID_R = 10

TIME_R = 3

SHMID = 6

WRITER = writer.c

RECID_W = 5

VALUE = 50 fifty five  123 

TIME_W = 5

PROG1 = reader
PROG2 = writer
PROG3 = setup

ARGS_R = -f $(FILENAME) -l $(RECID_R) -d $(TIME_R) -s $(SHMID)
ARGS_W = -f $(FILENAME) -l $(RECID_W) -v $(VALUE) -d $(TIME_W) -s $(SHMID)

all: $(PROG1) $(PROG2) $(PROG3)

$(PROG1): $(READER)
	$(CC) -o  $(PROG1) $(READER) -pthread

$(PROG2): $(WRITER)
	$(CC) -o  $(PROG2) $(WRITER) -pthread

$(PROG3): $(SETUP)
	$(CC) -o  $(PROG3) $(SETUP) -pthread

run1: $(PROG1)
	./$(PROG1) $(ARGS_R)

run2: $(PROG2)
	./$(PROG2) $(ARGS_W)

run3: $(PROG3)
	./$(PROG3)

clean:
	rm *.o $(PROG1) $(PROG2) 
