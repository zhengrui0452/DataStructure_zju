#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */
List Merge( List L1, List L2 );

int main()
{
    List L1, L2;
    List L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    printf("L:");
    Print(L);
    printf("L1:");
    Print(L1);
    printf("L2:");
    Print(L2);
    /*List L1;
    L1 = Read();
    Print(L1);*/
    return 0;
}

List Read(){
    int n;
    scanf("%d",&n);
    List L=(List)malloc(sizeof(struct Node));
    L->Next=NULL;
    List last=L;
    List s;
    for (int i = 1; i <= n; ++i)
    {
        s=(List)malloc(sizeof(struct Node));
        ElementType X;
        scanf("%d",&X);
        s->Data=X;
        s->Next=NULL;
        last->Next=s;
        last=s;
    }
    return L;
}
void Print(const List L ){
    List p=L->Next;
    while(p)
    {
        printf("%d ", p->Data);
        p=p->Next;
    };
    if (L->Next==NULL)
    {
        printf("NULL");
    }
    printf("\n");
}
List Merge( List L1, List L2 )
{
    List p1,p2,last;
    List L=(List)malloc(sizeof(struct Node));
    L->Next=NULL;
    p1=L1;p2=L2;
    last=L;
    while(L1->Next&&L2->Next)
    {
        p1=L1->Next;
        p2=L2->Next;

        List s=(List)malloc(sizeof(struct Node));
        if (p1->Data < p2->Data)
        {
            s->Data=p1->Data;
            s->Next=NULL;
            L1->Next=p1->Next;
            free(p1);
        }else
        {
            s->Data=p2->Data;
            s->Next=NULL;
            L2->Next=p2->Next;
            free(p2);
        }
        last->Next=s;
        last=s;
    }

    if (L1->Next)
    {
        last->Next=L1->Next;
        L1->Next=NULL;
    }
    if (L2->Next)
    {
        last->Next=L2->Next;
        L2->Next=NULL;
    }
    return L;
}