#include "module.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *data_file;
    int num_of_children, i;
    char *sorting1, *sorting2;

    if (argc != 9)
    {
        printf("Wrong input. Correct input is: ./mysort -i DataFile -k NumofChildren -e1 sorting1 -e2 sorting2 \n"); // error handling
        exit(1);
    }

    // reading arguments from command line no matter what position they are in
    for (i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-i") == 0)
        {
            data_file = argv[i + 1];
        }
        if (strcmp(argv[i], "-k") == 0)
        {
            num_of_children = atoi(argv[i + 1]);
        }
        if (strcmp(argv[i], "-e1") == 0)
        {
            sorting1 = argv[i + 1];
        }
        if (strcmp(argv[i], "-e2") == 0)
        {
            sorting2 = argv[i + 1];
        }
    }

    int pipe_for_read_data[2];
    // pipe for reading the exit from file Verify.c
    pipe2(pipe_for_read_data, 0);

    // swap file descriptor for standard output
    // with file descriptor of writing in pipe.
    // so all the data will be written in the pipe instad of stdout
    //  dup2(pipe_for_read_data[1], fileno(stdout));

    char *command = "./testfiles-proj2/TestData-Proj2-03NOV2023/Verify.c";
    strcat(command, data_file);
    // system(command);
}