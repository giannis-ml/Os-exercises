#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char *filename;
    int start_recid, end_recid = 0, ttime, shared_mem_id;

    for (int i = 1; i < argc; i += 1)
    {
        if (!strcmp(argv[i], "-f"))
        {
            filename = argv[i + 1];
        }
        if (!strcmp(argv[i], "-l"))
        {
            start_recid = atoi(argv[i + 1]);
        }
        if (!strcmp(argv[i], ","))
        {
            printf("%d\n", i);
            end_recid = atoi(argv[i + 1]);
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
    printf("Start record id: %d\n", start_recid);
    if (end_recid != 0)
        printf("end record id: %d\n", end_recid);
    printf("Time: %d\n", ttime);
    printf("Shared Memory id: %d\n", shared_mem_id);

    sleep(ttime);
}