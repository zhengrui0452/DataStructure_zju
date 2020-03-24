#include <stdio.h>
#include <stdlib.h>

#define ElementType int

typedef struct AVLNode *Position;
typedef Position AVLTree; /* AVL树类型 */
struct AVLNode{
    ElementType Data; /* 结点数据 */
    AVLTree Left;     /* 指向左子树 */
    AVLTree Right;    /* 指向右子树 */
    int Height;       /* 树高 */
};
int Max ( int a, int b ); 
AVLTree NewNode(ElementType data);
AVLTree RR(AVLTree A);
AVLTree RL(AVLTree A);
AVLTree LL(AVLTree A);
AVLTree LR(AVLTree A);
AVLTree Insert(AVLTree T,ElementType data);
AVLTree BuildTree(int N);
void Print(AVLTree T);

int main()
{
	int N;
	scanf("%d",&N);
	if (N)
	{
		AVLTree T=BuildTree(N);
		printf("%d\n", T->Data);
	}
	
}

int Max ( int a, int b )
{
    return a > b ? a : b;
}

AVLTree NewNode(ElementType data)
{
	AVLTree T=(AVLTree)malloc(sizeof(struct AVLNode));
	T->Data=data;
	T->Left=T->Right=NULL;
	T->Height=0;
	return T;
}

int GetHeight(AVLTree T)
{
	int Height=0;
	if (!T)
	{
		Height=1;
	}
	else
	{
		Height=Max(GetHeight(T->Left),GetHeight(T->Right))+1;
	}
	return Height;
}

AVLTree RR(AVLTree A)
{
	AVLTree B=A->Right;
	A->Right=B->Left;
	B->Left=A;
	A->Height=Max(GetHeight(A->Left),GetHeight(A->Right))+1;
	B->Height=Max(GetHeight(B->Right),A->Height)+1;
	return B;
}
AVLTree RL(AVLTree A)
{
	A->Right=LL(A->Right);
	return RR(A);
}
AVLTree LL(AVLTree A)
{

	AVLTree B=A->Left;
	A->Left=B->Right;
	B->Right=A;
	B->Height=Max(GetHeight(B->Left),A->Height)+1;
	A->Height=Max(GetHeight(A->Left),GetHeight(A->Right))+1;
	return B;
}
AVLTree LR(AVLTree A)
{
	A->Left=RR(A->Left);
	return LL(A);
}

AVLTree Insert(AVLTree T,ElementType X)
{
	if (!T)
	{
		T=NewNode(X);
	}else if (X>T->Data)
	{
		// printf("insert into right\n");
		T->Right=Insert(T->Right,X);
		if (GetHeight(T->Right)-GetHeight(T->Left)==2)
		{
			if (X>T->Right->Data)
			{
				// printf("RR\n");
				T=RR(T);
			}else
			{
				// printf("RL\n");
				T=RL(T);
			}
		}
	}else if (X<T->Data)
	{
		// printf("insert into left\n");
		T->Left=Insert(T->Left,X);
		if (GetHeight(T->Left)-GetHeight(T->Right)==2)
		{
			if (X<T->Left->Data)
			{
				// printf("LL\n");
				T=LL(T);
			}else
			{
				// printf("LR\n");
				T=LR(T);
			}
		}
	}
	T->Height=Max(GetHeight(T->Left),GetHeight(T->Right))+1;

	// Print(T);
	return T;
}

void Print(AVLTree T)
{
	if (!T)
	{
		printf("%d : Left=%d Right=%d Height=%d\n", T->Data,T->Left->Data,T->Right->Data,T->Height);
		if (!(T->Left))
		{
			Print(T->Left);
		}
		if (!(T->Right))
		{
			Print(T->Right);
		}
	}
	
}

AVLTree BuildTree(int N)
{
	ElementType data;
	scanf("%d",&data);
	AVLTree T=NewNode(data);

	for (int i = 1; i < N; ++i)
	{
		scanf("%d",&data);
		T=Insert(T,data);
	}
	return T;
}