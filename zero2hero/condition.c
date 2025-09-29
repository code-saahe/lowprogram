#include <stdio.h>

int main()
{
    int temp;
    printf("whats the tempature for today\n");
    scanf("%d", &temp);
    if (temp >= 60)
    {
        if (temp > 80)
        {
            printf("Its hot as shit outside smh\n");
            return 0;
        }
        printf("Its getting pretty warm out is %d degrees\n", temp);
        return 0;
    }
    if (temp < 60 && temp > 40)
    {
        printf("Its getting pretty cold out soon its %d degrees\n", temp);
        return 0;
    }
    else
    {
        printf("Its cold as shit outside\n");
        return 0;
    }

    return 0;
}