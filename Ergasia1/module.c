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
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->bucket = (Ht_item **)malloc(table->size * sizeof(Ht_item *));

    for (int i = 0; i < table->size; i++)
    {
        table->bucket[i] = createItem(i, NULL);
    }

    return table;
}

void freeTable(HashTable *table)

{
    for (int i = 0; i < table->size; i++)
    {
        Ht_item *item = table->bucket[i];

        if (item != NULL)
            freeItem(item);
    }

    free(table->bucket);
    free(table);
}

Ht_item *createItem(int key, Human *voter)
{
    Ht_item *tmp = (Ht_item *)malloc(sizeof(Ht_item));
    // tmp->key = malloc(sizeof(int));
    tmp->item = malloc(sizeof(struct Human *));

    tmp->key = key;
    tmp->item = voter;
    return tmp;
}

int hashCode(int key, int size)
{
    return key % size;
}

void freeItem(Ht_item *tmp)
{
    // free(tmp->key);
    free(tmp->item);
    free(tmp);
}

void insert(HashTable *ht, Human item)
{
    int hash_index = hashCode(item.id, ht->size);

    if (ht->bucket[hash_index]->item == NULL)
    {
        ht->bucket[hash_index]->item = &item;
        ht->count += 1;
    }
    else
    {
        bool flag = false;
        while (!flag)
        {
            if (hash_index == ht->size - 1)
            {
                hash_index = 0;
            }
            else
            {
                hash_index++;
            }

            if (ht->bucket[hash_index]->item == NULL)
            {
                ht->bucket[hash_index]->item = &item;
                ht->count += 1;
                flag = true;
            }
            else
            {
                continue;
            }
        }
    }
}