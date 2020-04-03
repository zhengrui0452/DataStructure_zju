#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 10
#define ElementType int
#define MaxTree 10
#define ERROR -1

struct QNode
{
	ElementType *Data;
	int rear;
	int front;
};
typedef struct QNode *Queue;

Queue CreateQueue()
{
	Queue Q=(Queue)malloc(sizeof(struct QNode));
	Q->Data=(ElementType *)malloc(MaxTree*sizeof(ElementType));
	Q->front=Q->rear=0;
	return Q;
}
bool IsFull(Queue Q)
{
	return ((Q->rear+1)%MaxTree == Q->front);
}
bool IsEmpty(Queue Q)
{
	return (Q->front == Q->rear);
}
void AddQ(Queue Q,ElementType R)
{
	if (IsFull(Q))
	{
		printf("Queue Is Full!\n");
	}else
	{
		Q->rear = (Q->rear+1)%MaxTree;
		Q->Data[Q->rear]=R;
	}
}
ElementType DeleteQ(Queue Q)
{
	if (Q->front == Q->rear)
	{
		printf("Queue Is Empty!\n");
		return ERROR;
	}else
	{
		Q->front=(Q->front+1)%MaxTree;
		return Q->Data[Q->front];
	}
}