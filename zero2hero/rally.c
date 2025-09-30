#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    STATUS_GOOD,
    STATUS_BAD,
} status_e;
size_t resize_mem(int **arr, size_t new_size)
{
    int *temp = NULL;
    temp = realloc(*arr, new_size * sizeof(int));
    if (temp == NULL)
    {
        *arr = NULL;
        printf("failed to reallacate memory\n");
        return STATUS_BAD;
    }
    *arr = temp;
    return STATUS_GOOD;
}
int main()
{
    size_t regular_size = 5;
    size_t bigger_size = 10;

    int *num = malloc(sizeof(int) * regular_size);
    if (num == NULL)
    {
        printf("could not allocate space\n");
        return STATUS_BAD;
    }
    for (int i = 0; i < regular_size; i++)
    {
        num[i] = i;
    }
    if (STATUS_BAD == resize_mem(&num, bigger_size))
    {
        printf("failed to add memeory\n");
        return -1;
    }
    for (size_t i = regular_size; i < bigger_size; i++)
    {
        num[i] = i;
    }
    for (size_t i = 0; i < bigger_size; i++)
    {
        printf("id: %d\n", num[i]);
    }
    free(num);
    num = NULL;

    return 0;
}