#include "/mnt/d/lowlevel2/includes/common.h"
#include "/mnt/d/lowlevel2/includes/file.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int create_db_file(char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd != -1)
    {
        perror("open");
        close(fd);
        printf("file already exsit\n");
        return STATUS_ERROR;
    }
    fd = open(filename, O_RDWR | O_CREAT, 0644);
    if (fd == -1)
    {
        perror("open");
        return STATUS_ERROR;
    }
    return fd;
}

int open_db_file(char *filename)
{
    int fd = open(filename, O_RDWR, 0644);
    if (fd == -1)
    {
        perror("open");
        printf("failed to open file\n");
        return STATUS_ERROR;
    }
    return fd;
}