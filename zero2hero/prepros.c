#include <stdio.h>
#define MAX_AGE 200

int main()
{
#ifdef DEBUGGING
    printf("we are in debugging mode status code %d file: %s\n", MAX_AGE, __FILE__);
#endif
    return 0;
}