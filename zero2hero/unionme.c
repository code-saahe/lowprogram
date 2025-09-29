#include <stdio.h>
typedef union
{
    int id;
    char buf[120];
} spacer_u;
int main()
{
    printf("%ld\n", sizeof(spacer_u));
    return 0;
}