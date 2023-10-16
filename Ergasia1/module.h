#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

typedef struct
{
    int id;
    char *lname;
    char *fname;
    int zip;
    char voted;
} Human;

typedef struct Ht_item
{
    int key;
    Human *item;
} Ht_item;

typedef struct HashTable
{
    Ht_item **bucket;
    int size;
    int count;
} HashTable;

int numOfLinesInTheFile(char *);

HashTable *createHashTable(int);

void freeTable(HashTable *);

Ht_item *createItem(int, Human *);

void freeItem(Ht_item *);

int hashCode(int, int);

void insert(HashTable *, Human);