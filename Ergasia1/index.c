#include "module.h"

int main(int argc, char **argv)
{

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

    voters = malloc(length * sizeof(Human)); // Works fine

    char delim[2] = " ";
    char *token; // Works fine

    int *id = malloc(length * sizeof(int));
    char **fname = malloc(length * sizeof(char *));

    for (int i = 0; i < length; i++)
    {
        fname[i] = malloc(MAX_LINE_LENGTH * sizeof(char));
    }

    char **lname = malloc(length * sizeof(char *));

    for (int i = 0; i < length; i++)
    {
        lname[i] = malloc(MAX_LINE_LENGTH * sizeof(char));
    }

    int *zip = malloc(length * sizeof(int)); // Works fine

    int num_of_index = 0;

    FILE *file = fopen(registered_voters, "r");
    while (fgets(line, MAX_LINE_LENGTH, file))
    {

        token = strtok(line, delim);
        id[num_of_index] = atoi(token);

        token = strtok(NULL, delim);
        fname[num_of_index] = token;

        token = strtok(NULL, delim);
        lname[num_of_index] = token;

        token = strtok(NULL, delim);
        zip[num_of_index] = atoi(token);

        voters[num_of_index].id = id[num_of_index];
        voters[num_of_index].fname = fname[num_of_index];
        voters[num_of_index].lname = lname[num_of_index];
        voters[num_of_index].zip = zip[num_of_index];

        num_of_index++;
    }

    for (int i = 0; i < length; i++)
    {
        // printf("Id: %d\n", voters[i].id);
        printf("FirstName: %s\n", fname[i]);
        // printf("Last Name: %s\n", voters[i].lname);
        // printf("Zip: %d\n", voters[i].zip);
    }

    // int size_of_hash_table = num_of_index;

    // HashTable *ht = createHashTable(num_of_index);

    // for (int i = 0; i < ht->size; i++)
    // {
    //     insert(ht, voters[i]);
    // }

    // for (int i = 0; i < ht->size; i++)
    // {
    //     if (ht->bucket[i]->item != NULL)
    //         printf("%s\n", ht->bucket[i]->item->fname);
    //     else
    //         printf("Empty\n");
    // }

    // fclose(file);
}
