#include <stdio.h>
#include <stdlib.h>

#define MaxSize 1001
#define MinH -10001
#define ElementType int

typedef struct HNode *Heap;
struct HNode
{
	ElementType *Data;
	int Size;
	int Capacity;
};
typedef Heap MinHeap;

MinHeap CreateHeap();
void Insert(MinHeap H,ElementType num);
int IsFull(MinHeap H);
void Print(MinHeap H);
void Find(MinHeap H,int index);

int main()
{
	int N,M,num;
	scanf("%d %d",&N,&M);
	MinHeap H=CreateHeap();
	for (int i = 0; i < N; ++i)
	{
		scanf("%d",&num);
		Insert(H,num);
	}
	// Print(H);
	int index;
	for (int i = 0; i < M; ++i)
	{
		scanf("%d",&index);
		Find(H,index);
		printf("\n");
	}
	// int a[M];
	// for (int i = 0; i < M; ++i)
	// {
	// 	scanf("%d",&a[i]);

	// }
	// for (int i = 0; i < M; ++i)
	// {
	// 	Find(H,a[i]);
	// 	printf("\n");
	// }
}

MinHeap CreateHeap()
{
	MinHeap H=(MinHeap)malloc(sizeof(struct HNode));
	H->Data=(ElementType *)malloc((MaxSize+1)*sizeof(ElementType));
	H->Size=0;
	H->Capacity=MaxSize;
	H->Data[0]=MinH;
	return H;
}
int IsFull(MinHeap H)
{
	if (H->Size>=MaxSize) return 1;
	else return 0;
}
void Insert(MinHeap H,ElementType num)
{
	if (IsFull(H))
	{
		printf("IS FULL!!!!\n");
		return;
	}
	int i=++H->Size;
	for (; H->Data[i/2]>num; i=i/2)
	{
		H->Data[i]=H->Data[i/2];
	}
	H->Data[i]=num;
}
void Print(MinHeap H)
{
	int i=1;
	while (H->Data[i])
	{
		printf("%d %d -- ", i, H->Data[i]);
		i++;
	}
	printf("\n");
}
void Find(MinHeap H,int index)
{
	for (int i = index; i > 0; i=i/2)
	{
		if (i==1) printf("%d", H->Data[i]);
		else printf("%d ", H->Data[i]);
	}
}