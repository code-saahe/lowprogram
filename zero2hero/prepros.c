#include <stdio.h>
#define MAX_AGE 200

int main()
{
#ifdef DEBUGGING
    printf("we are in debugging mode status code %d\n", MAX_AGE);
#endif
    return 0;
}