#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char *filename;
    char *value;
    int recid, ttime, shared_mem_id;

    for (int i = 1; i < argc; i += 1)
    {
        if (!strcmp(argv[i], "-f"))
        {
            filename = argv[i + 1];
        }
        if (!strcmp(argv[i], "-l"))
        {
            recid = atoi(argv[i + 1]);
        }
        if (!strcmp(argv[i], "-v"))
        {
            value = argv[i + 1];
        }
        if (!strcmp(argv[i], "-d"))
        {
            ttime = atoi(argv[i + 1]);
        }
        if (!strcmp(argv[i], "-s"))
        {
            shared_mem_id = atoi(argv[i + 1]);
        }
    }
    printf("File name: %s\n", filename);
    printf("Record id: %d\n", recid);
    printf("Value: %s\n", value);
    printf("Time: %d\n", ttime);
    printf("Shared Memory id: %d\n", shared_mem_id);

    sleep(ttime);
}