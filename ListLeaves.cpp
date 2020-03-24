#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxTree 10
#define ElementType int
#define Tree int
#define Null -1
#define ERROR -1


struct TreeNode
{
	// ElementType Element;
	Tree Left;
	Tree Right;
}T[MaxTree];

struct QNode
{
	ElementType *Data;
	int rear;
	int front;
};
typedef struct QNode *Queue;

Tree BuildTree(struct TreeNode T[]);
Queue CreateQueue();
void AddQ(Queue PerQ,ElementType R);
ElementType DeleteQ(Queue PerQ);
bool IsFull(Queue Q);
bool IsEmpty(Queue Q);
void LevelOrderTraversal(Queue Q,Tree R);

int main()
{
	Tree R;
	R=BuildTree(T);
	// printf("%d\n", R);

	//创建一个队列
	Queue q = CreateQueue();
	
	//层序遍历树的所有结点
	LevelOrderTraversal(q,R);
	//如果出栈时发现该结点是叶子结点则打印输出
	return 0;
}

Tree BuildTree(struct TreeNode T[])
{
	int N;
	Tree t=Null;
	scanf("%d\n",&N);
	int check[MaxTree]={};
	char cr,cl;
	if (N)
	{
		for (int i = 0; i < N; ++i)
		{
			scanf("%c %c",&cl,&cr);
			getchar();
			// T[i].Element=data;
			// T[i].Left=cl;
			// T[i].Right=cr;
			if (cl=='-')
			{
				T[i].Left=Null;
			}else
			{
				T[i].Left=cl-'0';
				check[T[i].Left]=1;
			}
			if (cr=='-')
			{
				T[i].Right=Null;
			}else
			{
				T[i].Right=cr-'0';
				check[T[i].Right]=1;
			}
			// printf("index=%d Element=%c Left=%d Right=%d\n", i,T[i].Element,T[i].Left,T[i].Right);
			// printf("index=%d Element=%c Left=%c Right=%c\n", i,data,cl,cr);
		}
		for (int i = 0; i < N; ++i)
		{
			if (check[i]==0)
			{
				t=i;
			}
		}
	}
	return t;
}
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
void LevelOrderTraversal(Queue Q, Tree R)
{
	bool first=false;
	if (R==Null && T==NULL)
	{
		printf("WO!!! Tree Is Empty!\n");
	}else
	{
		AddQ(Q,R);
		while (!IsEmpty(Q))
		{
			R=DeleteQ(Q);
			// printf("Traversal to %d\n", R);
			if (T[R].Left==Null && T[R].Right==Null)
			{
				if (first)
				{
					printf(" %d", R);
				}else
				{
					first=true;
					printf("%d", R);
				}
			}
			if (T[R].Left!=Null)
			{
				AddQ(Q,T[R].Left);
				// printf("%d has left,Traversal to left %d\n", R,T[R].Left);
			}
			if (T[R].Right!=Null)
			{
				AddQ(Q,T[R].Right);
				// printf("%d has right,Traversal to right %d\n", R,T[R].Left);
			}
		}
	}
}