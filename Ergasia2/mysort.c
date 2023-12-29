#include "module.h"

int main(int argc, char *argv[])
{
    char *data_file;
    int num_of_children, i, j, child_pid, second_child;
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

    Parser *parser;
    parser = Parsing(data_file);

    printf("RECORDS BEFORE SORTING: \n");
    for (int i = 0; i < parser->num_of_records; i++)
    {
        printf("%d  %s  %s  %s\n", parser->records[i].custid, parser->records[i].LastName, parser->records[i].FirstName, parser->records[i].postcode);
    }

    // create pipes for passing records to children
    int pipes[num_of_children][2];
    for (int i = 0; i < num_of_children; ++i)
    {
        if (pipe(pipes[i]) == -1)
        {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }

    // make middle children
    for (i = 0; i < num_of_children; i++)
    {
        child_pid = fork();

        if (child_pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0)
        {
            // close the write fd because children will only read from this pipe
            close(pipes[i][1]);
            char *buffer;
            ssize_t bytesRead = read(pipes[i][0], buffer, sizeof(buffer));
            // Close read end in the child
            close(pipes[i][0]);

            if (bytesRead > 0)
            {
                buffer[bytesRead] = '\0';
                printf("%s\n", buffer);
            }

            // make leafs of tree
            for (int j = 0; j < num_of_children - i; j++)
            {
                second_child = fork();
                if (second_child == -1)
                {
                    perror("fork");
                    exit(EXIT_FAILURE);
                }
                if (second_child == 0)
                {
                    //....
                }
            }
            exit(EXIT_SUCCESS);
        }
        else
        {
            // close the read fd because parent will only write in this pipe
            close(pipes[i][0]);
            int share = parser->num_of_records / num_of_children;
            if (i + 1 == num_of_children)
            {
                share = (parser->num_of_records / num_of_children) + parser->num_of_records - num_of_children * (parser->num_of_records / num_of_children);
            }
            for (int k = i * share; k < (i + 1) * share; k++)
            {
                // write...
            }
        }
    }
    exit(EXIT_SUCCESS);
}