#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define string char *

struct person_t
{
    int id;
    char name[256];
    bool employed;
};

void init_person(struct person_t *per)
{
    per->id = 50;
    char *name = "konraw";
    memset(per->name, '\0', sizeof(per->name));
    strcpy(per->name, name);
    per->employed = true;
}

int main()
{
    int num = 40;
    int n = 2;
    int *ptrNum = &num;
    string s = "hello";
    struct person_t *person = malloc(sizeof(struct person_t) * n);
    if (person == NULL)
    {
        printf("failed to allacate memory\n");
        return -1;
    }
    init_person(person);
    printf("%d\n", *ptrNum);
    printf("%p\n", ptrNum);
    printf("%d\n", person[0].id);
    printf("%s\n", person[0].name);
    free(person);
    person = NULL;
    return 0;
}