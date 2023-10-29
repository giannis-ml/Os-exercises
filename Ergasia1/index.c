#include "module.h"

int main(int argc, char **argv)
{

    // read the command line arguments
    char *registered_voters;
    int bucket_entries = 0;

    if (!strcmp(argv[1], "-f") && !strcmp(argv[3], "-b"))
    {
        registered_voters = argv[2];
        bucket_entries = atoi(argv[4]);
    }
    else if (!strcmp(argv[3], "-f") && !strcmp(argv[1], "-b"))
    {
        registered_voters = argv[4];
        bucket_entries = atoi(argv[2]);
    }
    else
    {
        printf("Wrong Input. Follow the correct format: \n%s\n", "./mvote -f registeredvoters -b bucketentries");
        return 1;
    }

    char line[MAX_LINE_LENGTH];

    int length;
    length = numOfLinesInTheFile(registered_voters);

    Human *voters;

    // array of structs
    voters = malloc(length * sizeof(Human));

    char delim[2] = " ";
    char *token; // Works fine

    char **info;
    info = malloc(length * sizeof(char *));

    for (int i = 0; i < length; i++)
    {
        info[i] = malloc(1024 * sizeof(char));
    }

    int num_of_index = 0;

    // iterate the file and fill an array with one word per position
    FILE *file = fopen(registered_voters, "r");
    while (fgets(line, MAX_LINE_LENGTH, file))
    {

        token = strtok(line, delim);
        while (token != NULL)
        {
            info[num_of_index] = strdup(token);
            token = strtok(NULL, " ");
            num_of_index++;
        }
    }

    int i, word_index;
    // fill the array of structs according to array with data
    for (i = 0; i < length; i++)
    {
        word_index = i * 4;
        voters[i].id = atoi(info[word_index]);
        voters[i].fname = info[word_index + 1];
        voters[i].lname = info[word_index + 2];
        voters[i].voted = "N";
        voters[i].zip = atoi(info[word_index + 3]);
    }
    int size_of_hash_table = num_of_index / 4;

    HashTable *ht = createHashTable(size_of_hash_table);

    for (int i = 0; i < ht->size; i++)
    {
        insert_in_hashtable(ht, voters[i]);
    }

    fclose(file);
    freeTable(ht);
}
