#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    struct stat s = {0};
    int fd = open("/mnt/d/lowlevel2/zero2hero/func.c", O_RDONLY, 0644);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }
    if (stat("func.c", &s) == 0)
    {
        printf("%ld\n", s.st_atime);
    }
    int amout = s.st_size;
    char buf[amout + 1];
    buf[-1] = 0;
    if (read(fd, &buf, sizeof(buf)) == -1)
    {
        perror("read");
        close(fd);
        return -1;
    }
    printf("%s\n", buf);
    close(fd);
    return 0;
}