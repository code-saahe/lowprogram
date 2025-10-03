#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <getopt.h>
#include "/mnt/d/lowlevel2/includes/common.h"
#include "/mnt/d/lowlevel2/includes/file.h"

int print_usage(char *argv[])
{
    printf("Usage: %s -n -f <database file>\n", argv[0]);
    printf("\t -n -create a new database file\n");
    printf("\t -f -(required) path to database file\n");
    return 0;
}
int main(int argc, char *argv[])
{
    char *filepath = NULL;
    bool newfile = false;
    int c = 0;
    int dbfd;
    while ((c = getopt(argc, argv, "nf:")) != -1)
    {
        switch (c)
        {
        case 'n':
            newfile = true;
            break;
        case 'f':
            filepath = optarg;
            break;
        case '?':
            printf("unknown option -%c\n", c);
        default:
            return -1;
            break;
        }
    }
    if (filepath == NULL)
    {
        printf("filepath is required argument\n");
        print_usage(argv);
        return 0;
    }
    if (newfile)
    {
        dbfd = create_db_file(filepath);
        if (dbfd == STATUS_ERROR)
        {
            printf("unable to craate database file");
            return -1;
        }
        else
        {
            dbfd = open_db_file(filepath);
            if (dbfd == STATUS_ERROR)
            {
                printf("unable to open database file");
                return -1;
            }
        }
    }

    printf("Newfile %d\n", newfile);
    printf("file path %s\n", filepath);
    return 0;
}