#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define SIZEofBUFF 20
#define SSizeofBUFF 6
typedef struct
{
    int custid;
    char LastName[SIZEofBUFF];
    char FirstName[SIZEofBUFF];
    char postcode[SSizeofBUFF];
} MyRecord;
