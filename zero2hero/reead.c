#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

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
    printf("%d\n%d\n%d\n", head.version, head.employees, head.filelenght);
    return 0;
}
