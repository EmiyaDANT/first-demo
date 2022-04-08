#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct List
{
    char name[128];
    struct List *next;
} List;

void InitList(List *head)
{
    *head=calloc(1,sizeof(List));
}

_Bool ListEmpty(List *head)
{
    if (head->next==NULL)
    {
        return 1;
    }
    return 0;
}

void ClearList(List *head)
{
    struct List *node;
    head=head->next;
    while(head!=NULL)
    {
        node=head->next;
        free(head);
        head=node;
    }
}

void GetElem(List head,int i,char *e)
{
    int j=1;
    List *node=head.next;
    while(j<i || node!=NULL)
    {
        node=node->next;
        j++;
    }
    if (node!=NULL)
    {
        strcpy(e,node->name);
    }
    else
    {
        printf("超出范围\n");
    }
}

void LocateElem(List L,char *e)
{
    List *node=L.next;
    while(node!=NULL)
    {
        if (!strcmp((node->name),e))
        {
            break;
        }
    }
    if (node!=NULL)
    {
        strcpy(e,node->name);
    }
    else
    {
        printf("没有你要查找的值\n");
    }
}

void ListInsert(List *L,int i,char *e)
{
    int j=0;
    while(j<i-1 || L==NULL)
    {
        L=L->next;
        j++;
    }
    if(L!=NULL)
    {
        struct List *node = (List *)malloc(sizeof(List));
        strcpy(node->name,e);
        node->next=L->next;
        L->next=node;
    }
    else
    {
        printf("超出线性表范围\n");
    }
}



void main()
{
    List head;
    InitList(&head);

}