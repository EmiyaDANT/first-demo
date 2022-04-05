#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Book
{
    int id[3];
} Element;

void main()
{
    Element a;
    Element *p=&a;
    a.id[0] = 1;
    a.id[1] = 3;
    a.id[2] = 5;
    for (int i = 0; i < 3; i++)
    {
        printf("%d ",a.id[i]);
    }
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", p->id[i]);
    }
}