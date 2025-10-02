#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

struct db_head_t
{
    unsigned short version;
    unsigned short employees;
    unsigned int filelenght;
};

int main()
{
    char *file_path_db = "/mnt/d/lowlevel2/./my-db.db";
    struct db_head_t head = {0};
    struct stat db_stat = {0};
    int fd = open(file_path_db, O_RDONLY, 0644);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }
    if (read(fd, &head, sizeof(head)) == -1)
    {
        perror("read");
        close(fd);
        return -1;
    }
    if (fstat(fd, &db_stat) == -1)
    {
        perror("fstat");
        close(fd);
        return -1;
    }
    printf("%d\n%d\n%d\n", head.version, head.employees, head.filelenght);
    printf("the stat size is %lu\n", db_stat.st_size);
    close(fd);
    return 0;
}
