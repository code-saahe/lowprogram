#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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
}

int main()
{
    int num = 40;
    int *ptrNum = &num;
    string s = "hello";
    struct person_t person;
    init_person(&person);
    printf("%d\n", *ptrNum);
    printf("%p\n", ptrNum);
    printf("%d\n", person.id);
    printf("%s\n", person.name);
    return 0;
}