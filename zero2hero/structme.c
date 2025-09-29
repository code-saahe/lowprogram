#include <stdio.h>
#include <string.h>
/*
make a struct that has an id field and name field
make an array of 2 structs and set the id and name thru a loop
grab the name from the command line
copy those name to the struct using the string.h package
*/
#define MAX_IDS 2
typedef struct
{
    int id;
    char name[256];
} person_info_t;
int setup_person(person_info_t p[])
{

    int check_buf_size = 256;
    for (int i = 0; i < MAX_IDS; i++)
    {
        char buf[256] = {0};
        p[i].id = i * 5;
        if (p[i].id == 0)
        {
            p[i].id = 2 * 5;
        }
        scanf("%s", buf);
        if (strlen(buf) > check_buf_size)
        {
            printf("you tried to commit a overflow but you failed\n");
            return -1;
            break;
        }
        strcpy(p[i].name, buf);
    }
    return 0;
}
void print_person_info(person_info_t p[])
{
    for (int i = 0; i < MAX_IDS; i++)
    {
        if (p[i].id == 0)
        {
            printf("person index %d not init\n", i);
            break;
        }
        printf("my badge num:%d\n my name is %s\n", p[i].id, p[i].name);
    }
}
int main(int argc, char *argv[])
{
    person_info_t person[MAX_IDS] = {0};
    setup_person(person);
    print_person_info(person);
    return 0;
}