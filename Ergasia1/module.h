#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

// struct for voter
typedef struct Human
{
    int id;
    char *lname;
    char *fname;
    int zip;
    char *voted;
} Human;

// struct for implementing bucket
typedef struct Bucket
{
    int key;
    int size;            // number of items in bucket
    int count;           // count of items in bucket
    Human *voters;       // records of bucket
    struct Bucket *next; // pointer to next bucket in case of overflow buckets
} Bucket;

// struct for implementing Hashtable
typedef struct HashTable
{
    Bucket **buckets; // pointer to buckets
    int size;         // number of total entries
    int count;        // counter of total entries
    int buckets_num;  // number of buckets
    int update;       // number of buckets when we will move to next round
    int round;
    int pointer; // index for the bucket that will be split
} HashTable;

int numOfLinesInTheFile(char *);

HashTable *createHashTable(int);

void freeTable(HashTable *);

int hashCode(int, int, int);

void insert_in_hashtable(HashTable *, Human);

void insert_in_bucket(HashTable *, Bucket *, Human, int);
