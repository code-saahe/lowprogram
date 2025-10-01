#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char **argv)
{
    struct stat s = {0};
    int fd = open("/mnt/d/lowlevel2/zero2hero/rally.c", O_RDONLY, 0644);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }
    if (stat("/mnt/d/lowlevel2/zero2hero/rally.c", &s) == 0)
    {
        printf("%s\n", ctime(&s.st_atime));
    }
    char buf[4096];
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