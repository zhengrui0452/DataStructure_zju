#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *PtrToNode;
struct PolyNode{
	int coef;
	int expon;
	PtrToNode Next;
};
typedef PtrToNode List;

List Read();
void Print(List L);
List MULT(List L1,List L2);
List ADD(List L1,List L2);

int main(){
	List L1,L2,mult,add;//
	L1=Read();
	L2=Read();
	// printf("---------------------------------\n");
	mult=MULT(L1,L2);
	Print(mult);
	// printf("---------------------------------\n");
	add = ADD(L1,L2);
	Print(add);
	return 0;
}
List Read(){
	int num;
	scanf("%d",&num);
	List L,last;
	L=(List)malloc(sizeof(struct PolyNode));
	last=L;
	last->Next=NULL;
	for (int i = 0; i < num; ++i)
	{
		List s=(List)malloc(sizeof(struct PolyNode));
		int coef,expon;
		scanf("%d %d",&coef,&expon);
		s->coef=coef;
		s->expon=expon;
		s->Next=NULL;
		last->Next=s;
		last= last->Next;
	}
	return L;
}
void Print(List L){
	List p=L->Next;
	if (p)
	{
		printf("%d %d", p->coef,p->expon);
		while(p=p->Next)
		{
			printf(" %d %d", p->coef,p->expon);
		}
		printf("\n");
	}else
	{
		printf("0 0");
		printf("\n");
	}
}
List MULT(List L1,List L2){
	List L=(List)malloc(sizeof(struct PolyNode));
	List l1=L1->Next;
	while(l1)
	{
		List LL=(List)malloc(sizeof(struct PolyNode));
		List p=LL;
		List l2=L2->Next;
		while(l2)
		{
			List s=(List)malloc(sizeof(struct PolyNode));
			s->expon=(l2->expon)+(l1->expon);
			s->coef=(l2->coef)*(l1->coef);
			s->Next=NULL;
			p->Next=s;
			p=p->Next;
			l2=l2->Next;
		}
		L=ADD(L,LL);
		// Print(L);
		l1=l1->Next;
	}
	return L;
}
List ADD(List L1,List L2)
{
	List L=(List)malloc(sizeof(struct PolyNode));
	List p=L;
	List l1=L1->Next;
	List l2=L2->Next;
	while (l1&&l2)
	{
		List s=(List)malloc(sizeof(struct PolyNode));
		if (l1->expon==l2->expon)
		{
			s->expon=l1->expon;
			s->coef=l1->coef+l2->coef;
			l1=l1->Next;
			l2=l2->Next;
		}else if (l1->expon>l2->expon)
		{
			s->expon=l1->expon;
			s->coef=l1->coef;
			l1=l1->Next;		
		}else
		{
			s->expon=l2->expon;
			s->coef=l2->coef;
			l2=l2->Next;
		}
		s->Next=NULL;
		if (s->coef!=0)
		{
			p->Next=s;
			p=p->Next;
		}
	}
	while (l1)
	{
		List s=(List)malloc(sizeof(struct PolyNode));
		s->expon=l1->expon;
		s->coef=l1->coef;
		s->Next=NULL;
		p->Next=s;
		l1=l1->Next;
		p=p->Next;
	}
	while (l2)
	{
		List s=(List)malloc(sizeof(struct PolyNode));
		s->expon=l2->expon;
		s->coef=l2->coef;
		s->Next=NULL;
		p->Next=s;
		l2=l2->Next;
		p=p->Next;
	}
	// Print(L);
	return L;
}