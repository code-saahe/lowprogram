#include <stdio.h>

#define MAX_PEOPLE 30
int main()
{
    /*
    make an array of intergers with max people
    loop thru the array adding a number to array
    print each number in the array
    */
    int arr[MAX_PEOPLE];
    int i = 0;
    for (; i < MAX_PEOPLE; i++)
    {
        arr[i] = i * 2;
        printf("person id: %d\n", arr[i]);
    }
    int count = 0;
    do
    {
        arr[count];
        printf("im a happy person\n");
        count++;
    } while (arr[count] < 57);

    return 0;
}