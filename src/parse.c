#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#include "/mnt/d/lowlevel2/includes/common.h"
#include "/mnt/d/lowlevel2/includes/parse.h"

void output_file(int fd, struct dbheader_t *dbhdr)
{
    if (fd < 0)
    {
        printf("bad fd from user \n");
        return;
    }
    dbhdr->magic = htonl(HEADER_MAGIC);
    dbhdr->filesize = htonl(dbhdr->filesize);
    dbhdr->count = htons(dbhdr->filesize);
    dbhdr->version = htons(dbhdr->version);

    lseek(fd, 0, SEEK_SET);
    if (write(fd, dbhdr, sizeof(struct dbheader_t)) == -1)
    {
        perror("write");
        return;
    }
    return;
}
int validate_db_header(int fd, struct dbheader_t **headerOut)
{
    if (fd < 0)
    {
        printf("bad file discripter\n");
        return STATUS_ERROR;
    }
    struct dbheader_t *header = calloc(1, sizeof(struct dbheader_t));
    if (header == -1)
    {
        printf("malloc failed to create a dbheader\n");
        return STATUS_ERROR;
    }
    if (read(fd, header, sizeof(struct dbheader_t)) != sizeof(struct dbheader_t))
    {
        perror("read");
        free(header);
        return STATUS_ERROR;
    }
    header->version = ntohs(header->version);
    header->count = ntohs(header->count);
    header->magic = ntohl(header->magic);
    header->filesize = ntohl(header->filesize);
    if (header->magic != HEADER_MAGIC)
    {
        printf("improper header magic\n");
        free(header);
        return STATUS_ERROR;
    }
    if (header->version != 1)
    {
        printf("improper header version\n");
        free(header);
        return STATUS_ERROR;
    }
    struct stat dbstat = {0};
    fstat(fd, &dbstat);
    if (header->filesize != dbstat.st_size)
    {
        printf("currupted database\n");
        free(header);
        return STATUS_ERROR;
    }
    *headerOut = header;
}
int create_dbheader(int fd, struct dbheader_t **headerOut)
{
    struct dbheader_t *header = calloc(1, sizeof(struct dbheader_t));
    if (header == -1)
    {
        printf("malloc failed to create db header \n");
        return STATUS_ERROR;
    }
    header->version = 0x1;
    header->count = 0;
    header->magic = HEADER_MAGIC;
    header->filesize = sizeof(struct dbheader_t);

    *headerOut = header;
    return STATUS_GOOD;
}