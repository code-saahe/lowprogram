#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd = open("giuyhgwedic.txt", O_RDONLY, 0644);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }
    return 0;
}