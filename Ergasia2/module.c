#include "module.h"

// Parsing the file, store the data in one array of structs and returns it to main
Parser *Parsing(char *data_file)
{
    int fd = open(data_file, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int fileSize = lseek(fd, 0, SEEK_END);
    int numRecords = fileSize / sizeof(MyRecord);

    Parser *tmp = (Parser *)malloc(sizeof(Parser));

    tmp->records = (MyRecord *)malloc(numRecords * sizeof(MyRecord));

    MyRecord rec;

    lseek(fd, 0, SEEK_SET);

    tmp->num_of_records = numRecords;
    for (int i = 0; i < tmp->num_of_records; ++i)
    {
        ssize_t bytesRead = read(fd, &rec, sizeof(MyRecord));
        if (bytesRead == -1)
        {
            perror("Error reading file");
            close(fd);
            exit(EXIT_FAILURE);
        }

        tmp->records[i].custid = rec.custid;
        strcpy(tmp->records[i].LastName, rec.LastName);
        strcpy(tmp->records[i].FirstName, rec.FirstName);
        strcpy(tmp->records[i].postcode, rec.postcode);
    }
    close(fd);

    return tmp;
}