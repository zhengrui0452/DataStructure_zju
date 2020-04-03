#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 10
#define ElementType int
#define MaxTree 10
#define ERROR -1
#define MaxVertexNum 10
#define INFINITY 65535
typedef int Vertex;
typedef int WeightType;
typedef int DataType;

typedef struct ENode *PtrToENode;
struct ENode
{
	Vertex V1,V2;
	WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct GNode *PtrToGNode;
struct GNode
{
	int Nv;
	int Ne;
	int G[MaxVertexNum][MaxVertexNum];
	DataType Data[MaxVertexNum];
};
typedef PtrToGNode MGraph;

struct QNode
{
	ElementType *Data;
	int rear;
	int front;
};
typedef struct QNode *Queue;

bool Visited1[MaxVertexNum]={false};
bool Visited2[MaxVertexNum]={false};


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

MGraph CreateGraph(int VertexNum)
{
	Vertex V,W;
	MGraph Graph;

	Graph=(MGraph)malloc(sizeof(struct GNode));
	Graph->Nv=VertexNum;
	Graph->Ne=0;
	for (V = 0; V < Graph->Nv; ++V)
	{
		for (W = 0; W < Graph->Nv; ++W)
		{
			Graph->G[V][W]=INFINITY;
		}
	}
	return Graph;
}

void InsertEdge(MGraph Graph,Edge E)
{
	Graph->G[E->V1][E->V2]=E->Weight;
	Graph->G[E->V2][E->V1]=E->Weight;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	int Nv;
	scanf("%d",&Nv);
	Graph = CreateGraph(Nv);
	scanf("%d",&(Graph->Ne));
	if (Graph->Ne!=0)
	{
		E=(Edge)malloc(sizeof(struct ENode));
		for (int i = 0; i < Graph->Ne; ++i)
		{
			scanf("%d %d",&E->V1,&E->V2);
			E->Weight=1;
			InsertEdge(Graph,E);
		}
	}
	return Graph;
}

void Print(MGraph Graph)
{
	Vertex V,W;
	for (V = 0; V < Graph->Nv; ++V)
	{
		for (W = 0; W < Graph->Nv; ++W)
		{
			printf("%d ", Graph->G[V][W]);
		}
		printf("\n");
	}
}
void Visit( Vertex V)
{
	printf("Visiting Node %d\n", V);
}


bool IsEdge(MGraph Graph,Vertex V,Vertex W)
{
	return Graph->G[V][W]<INFINITY?true:false;
}
void DFS(MGraph Graph,Vertex X)
{
	Vertex W;
	Visited1[X]=true;
	printf("%d ", X);
	for (W = 0; W < Graph->Nv; ++W)
	{
		if (!Visited1[W]&&IsEdge(Graph,X,W))
		{
			Visited1[W]=true;
			DFS(Graph,W);
		}
	}
	
}
void BFS(MGraph Graph,Vertex S)
{
	Queue Q;
	Vertex V,W;
	Q=CreateQueue();
	// Visit(S);
	Visited2[S]=true;
	AddQ(Q,S);

	while(!IsEmpty(Q))
	{
		V=DeleteQ(Q);
		printf("%d ", V);
		for (W = 0; W < Graph->Nv; ++W)
		{
			if (!Visited2[W]&&IsEdge(Graph,V,W))
			{
				// Visit(W);
				Visited2[W]=true;
				AddQ(Q,W);
			}
		}
	}
	
}

int main()
{
	MGraph Graph = BuildGraph();
	// Print(Graph);
	
	int j=0;
	while(j<Graph->Nv)
	{
		if (!Visited1[j])
		{
			printf("{ ");
			DFS(Graph,j);
			printf("}\n");
		}
		j++;
	}

	int i=0;
	while(i<Graph->Nv)
	{
		if (!Visited2[i])
		{
			printf("{ ");
			BFS(Graph,i);
			printf("}\n");
		}
		i++;
	}
	
}