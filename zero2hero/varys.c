#include <stdio.h>
// global scope

int main(int argc, char **argv)
{
    int personID = 1;
    int personID2 = personID + 1;
    printf("This is the PersonId badge num: %d\n", personID);
    printf("This is the PersonId badge num: %d\n", personID2);
    printf("This is the PersonId badge num: %d\n", personID2 += 2);
    return 0;
}