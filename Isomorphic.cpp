#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree],T2[MaxTree];

Tree BuildTree(struct TreeNode T[]);
void PrintTree(struct TreeNode T[]);
int Isomorphic(Tree R1,Tree R2);

int main()
{
	Tree R1,R2;

	R1=BuildTree(T1);
	// printf("%d\n", R1);
	R2=BuildTree(T2);
	// printf("%d\n", R2);
	if (Isomorphic(R1,R2))
	{
		printf("Yes\n");
	}else
	{
		printf("No\n");
	}
	return 0;
}

Tree BuildTree(struct TreeNode T[])
{
	int N;
	Tree t=Null;
	scanf("%d\n",&N);
	int check[MaxTree]={};
	char data,cr,cl;
	if (N)
	{
		for (int i = 0; i < N; ++i)
		{
			scanf("%c %c %c",&data,&cl,&cr);
			getchar();
			T[i].Element=data;
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
void PrintTree(struct TreeNode T[])
{
	printf("----------------Let's Print!----------------\n");
	for (int i = 0; i < MaxTree; ++i)
	{
		printf("%c %d %d\n", T[i].Element,T[i].Left,T[i].Right);
	}
}
int Isomorphic(Tree R1,Tree R2)
{
	// printf("正在比较%c和%c\n",T1[R1].Element,T2[R2].Element) ;
	int result = 0;
	if (T1==NULL && T2==NULL)
	{
		// printf("整棵树为空\n");
		result=1;
	}else if ((T1==NULL && T2!=NULL) || (T1!=NULL && T2==NULL))
	{
		// printf("两棵树中有一个为空\n");
		result=0;
	}else if (R1==Null && R2==Null)
	{
		// printf("整棵树为空\n");
		result=1;
	}else if ((R1==Null && R2!=Null) || (R1!=Null && R2==Null))
	{
		// printf("两棵树中有一个为空\n");
		result=0;
	}else if (T1[R1].Element != T2[R2].Element)
	{
		// printf("%d %d根不相等\n", R1,R2);
		result=0;
	}else if (T1[R1].Element == T2[R2].Element 
		&& T1[R1].Left==Null
		&& T1[R1].Right==Null
		&& T2[R2].Left==Null
		&& T2[R2].Right==Null)
	{
		// printf("子树都为空，%d %d根相等\n", R1,R2);
		result = 1;
	}else if (T1[R1].Left==Null && T2[R2].Left==Null)//两个左为空
	{
		// printf("%d %d左子树为空，继续比较右子树\n", R1,R2);
		result=Isomorphic(T1[R1].Right,T2[R2].Right);
	}else if (T1[R1].Right==Null && T2[R2].Right==Null)
	{
		// printf("%d %d右子树为空，继续比较左子树\n", R1,R2);
		result=Isomorphic(T1[R1].Left,T2[R2].Left);
	}else if (T1[R1].Right==Null && T2[R2].Left==Null)
	{
		// printf("%d右子树为空， %d左子树为空，继续比较%d左子树， %d右子树\n", R1,R2, R1,R2);
		result=Isomorphic(T1[R1].Left,T2[R2].Right);
	}else if (T1[R1].Left==Null && T2[R2].Right==Null)
	{
		// printf("%d右子树为空， %d左子树为空，继续比较%d左子树， %d右子树\n", R2, R1,R2,R1);
		result=Isomorphic(T1[R1].Right,T2[R2].Left);
	}else
	{
		result=(Isomorphic(T1[R1].Left,T2[R2].Left)	//1 5
			&&Isomorphic(T1[R1].Right,T2[R2].Right))//2 1
		||(Isomorphic(T1[R1].Left,T2[R2].Right)		//1 1 
			&&Isomorphic(T1[R1].Right,T2[R2].Left));//2 5
	}
	return result;

}