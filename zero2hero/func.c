#include <stdio.h>

void print_binary_func()
{
    size_t let = 9;
    printf("%ld\n", let);
    return;
}
int main(int argc, char **argv)
{
    print_binary_func();
    printf("%s\n", argv[1]);
    return 0;
}