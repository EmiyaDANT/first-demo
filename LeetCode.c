#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENTH 100
#define true 1
#define false 0
#define notExsit 0

typedef int Bool;
typedef int HaoMa;
typedef int status;

typedef struct List_W
{
    HaoMa ID[MAX_LENTH];
    int Length;
} Element,*PElement;

// 初始化一个空的线性表
void InitList(Element *L)
{
    L = (PElement)calloc(1,sizeof(Element));
    memset(L->ID,0,sizeof(MAX_LENTH));
    L->Length=0;
    fprintf(stdout,"初始化线性表成功\n");
}

// 判断一个线性表是否为空
Bool ListEmpty(Element L)
{
    if(L.Length>0)
    {
        return false;
    }
    return true;
}

// 清空线性表
void ClearList(Element *L)
{
    free(L);
    fprintf(stdout,"线性表清空成功\n");
}

// 将线性表中的第n个元素返回给e
void GetElem(Element L,int n,HaoMa *e)
{
    if (n>MAX_LENTH)
    {
        fprintf(stderr,"返回失败,请输入小于最大长度的元素\n");
    }
    *e=L.ID[n-1];
}

// 将找value在线性表中的序号，若不存在返回该fail,
status LocateElem(Element L,HaoMa value)
{
    for (int i = 0; i < L.Length; i++)
    {
        if (value==L.ID[i])
        {
            return i+1;
        }
    }
    return notExsit;
}

// 在线性表L中第i个位置插入新元素e
void ListInsert(Element *L,int i,HaoMa e)
{
    (L->Length)++;
    if (i<1 || i>L->Length || L->Length > MAX_LENTH)
    {
        (L->Length)--;
        fprintf(stderr,"插入失败,超出范围\n");
    }
    else
    {
        // 非常之巧妙                                                                                                               
        for (int j = i; j < L->Length; j++)
        {
            L->ID[j]=L->ID[j-1];
        }
        L->ID[i-1]=e;
        printf("插入成功\n");
    }
}

// 删除线性表L中第i个位置的元素，并用e返回其值
void ListDelete(Element *L,int i,HaoMa *e)
{
    if (i < 1 || i>L->Length)
    {
        fprintf(stderr,"没有你要删除的元素\n");
    }
    else
    {
        *e=L->ID[i-1];
        for (int j = i; j < L->Length; j++)
        {
            L->ID[i-1]=L->ID[i];
        }
        (L->Length)--;
        L->ID[L->Length]=0;
    }
}



void main()
{
    Element *L;
    InitList(L);
    for (int i = 1; i <= 200; i++)
    {
        ListInsert(L,i,i*2);
    }
    for (int i = 0; i < 100; i++)
    {
        printf("%d ",L->ID[i]);
    }
    status i = LocateElem(*L,100);
    printf("\n%d",i);
}









