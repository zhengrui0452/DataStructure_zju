#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    // printf("%d\n", L->Last);
    // for (int i = 1; i <= L->Last; ++i)
    // {
    //     printf("%d\n", L->Data[i]);
    // }
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

List ReadInput()
{
    int N;
    ElementType X;
    List L=(List)malloc(sizeof(struct LNode));
    
    scanf("%d",&N);
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d",&X);
        L->Data[i]=X;
        L->Last=i;
    }
    return L;
} 
Position BinarySearch( List L, ElementType X )
{
    Position left,right,mid;
    Position index=0;
    if (L)
    {
        left=1;
        right=L->Last;
        while(left<=right)
        {
            mid=(left+right)/2;
            // printf("%d %d %d\n", left,mid,right);
            if (L->Data[mid]>X)
            {
                right=mid-1;
            }else if (L->Data[mid]<X)
            {
                left=mid+1;
            }else
            {
                index=mid;
                break;
            }
        }
    }
    if (index==0)
    {
        return NotFound;
    }else
    {
        return index;
    }
    
}