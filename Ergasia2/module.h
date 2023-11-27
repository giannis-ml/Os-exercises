#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZEofBUFF 20
#define SSizeofBUFF 6
typedef struct
{
    int custid;
    char LastName[SIZEofBUFF];
    char FirstName[SIZEofBUFF];
    char postcode[SSizeofBUFF];
} MyRecord;

typedef struct
{
    MyRecord *records;
    int num_of_records;
} Parser;

Parser *Parsing(char *);