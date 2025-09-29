#include <stdio.h>
#include <string.h>

int main()
{
    size_t id[10];
    memset(id, 0, sizeof(id));
    int len = sizeof(id) / sizeof(id[0]);
    id[0] = 20;
    int l = len > 0 ? 5 : 6;
    printf("the size of this array is %d\n %08lx\n", l, sizeof(id));
    char buf[50];
    memset(buf, '\0', sizeof(buf));
    scanf("%s", buf);
    printf("%s\n", buf);
    return 0;
}