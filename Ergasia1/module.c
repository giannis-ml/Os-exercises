#include "module.h"

int numOfLinesInTheFile(char *file_name)
{

    FILE *file = fopen(file_name, "r");

    if (!file)
    {
        printf("Error opening file\n");
        return 1;
    }

    int numOfLines = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file))
    {
        numOfLines += 1;
    }
    fclose(file);
    return numOfLines;
}

HashTable *createHashTable(int size)
{
    // create ht and its buckets with malloc
    // initialize hash table members
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->buckets_num = 2;
    table->update = table->buckets_num * 2;
    table->round = 0;
    table->pointer = 0;
    table->buckets = (Bucket **)malloc(table->buckets_num * sizeof(Bucket *));

    // allocate memory for each bucket
    // initialize bucket members
    for (int i = 0; i < table->buckets_num; i++)
    {
        table->buckets[i] = malloc(sizeof(Bucket *));
        table->buckets[i]->size = 2;
        table->buckets[i]->count = 0;
        table->buckets[i]->key = i;
        table->buckets[i]->voters = malloc(table->buckets[i]->size * sizeof(Human));
        for (int j = 0; j < table->buckets[i]->size; j++)
        {
            // set -1 as voter initial value
            table->buckets[i]->voters[j].id = -1;
        }
        table->buckets[i]->next = NULL;
    }

    return table;
}

void freeTable(HashTable *table)
{
    for (int i = 0; i < table->buckets_num; i++)
    {
        free(table->buckets[i]->voters);
    }
    free(table->buckets);
    free(table);
}

// hash function according to linear hashing paper
int hashCode(int key, int level, int buckets)
{
    return (key % ((int)pow(2, level) * buckets));
}

void insert_in_hashtable(HashTable *ht, Human item)
{
    float load_factor = 0;
    float limit = 0.75;
    int m = 2;

    // check if we moved to next round
    if (ht->buckets_num == ht->update)
    {
        ht->round += 1;
        ht->pointer = 0;
    }

    // find hash value
    int index = hashCode(item.id, ht->round, ht->buckets_num);

    if (index < ht->pointer)
        index = hashCode(item.id, ht->round + 1, ht->buckets_num);

    // adding voter to aproppriate bucket
    insert_in_bucket(ht, ht->buckets[index], item, index);
    ht->count += 1;

    // check if we moved to next round
    if (ht->buckets_num == ht->update)
    {
        ht->round += 1;
        ht->pointer = 0;
    }

    // compute load factor according to linear hashing paper
    load_factor = ht->count / ((ht->buckets_num * ht->size));
}

void insert_in_bucket(HashTable *ht, Bucket *bucket, Human voter, int index)
{

    Bucket *new = bucket;

    // find the last bucket in case of overflow buckets
    while (new->next != NULL)
        new = new->next;

    // search for free space to place record in the bucket
    for (int i = 0; i < new->size; i++)
    {
        if (new->voters[i].id != -1)
        {
            new->voters[i] = voter;
            new->count += 1;
            return;
        }
    }

    // construct overflow bucket
    Bucket *tmp = malloc(sizeof(Bucket));

    tmp->size = 2;
    tmp->count = 0;
    tmp->key = index;
    tmp->voters = malloc(tmp->size * sizeof(Human));
    for (int j = 0; j < tmp->size; j++)
    {
        tmp->voters[j].id = -1;
    }
    tmp->next = NULL;
    // put record in overflow bucket
    new->next = tmp;
    new->count += 1;
    ht->buckets_num += 1;
}