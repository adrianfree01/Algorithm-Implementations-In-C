#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct person
{
    int *preference;
    bool taken;    
} person;

int isSingle(int* men)
{
    
}

int main()
{
    int size;
    printf("Enter number of pairs\n");
    scanf("%d", &size);

    person *men = malloc(sizeof(person)*size);
    person *women = malloc(sizeof(person)*size);

    for(int i = 0; i < size; i++)
    {
        men[i].preference = malloc(sizeof(int)*size);
        women[i].preference = malloc(sizeof(int)*size);
    }

    for(int i = 0; i < size; i++)
    {
        printf("Enter preference order of women for man #%d\n", i);
        for(int j = 0; j < size; j++)
        {
            scanf("%d", &men[i].preference[j]);
        }
    }

    for(int i = 0; i < size; i++)
    {
        printf("Enter preference order of men for woman #%d\n", i);
        for(int j = 0; j < size; j++)
        {
            scanf("%d", &women[i].preference[j]);
        }
    }



    

}