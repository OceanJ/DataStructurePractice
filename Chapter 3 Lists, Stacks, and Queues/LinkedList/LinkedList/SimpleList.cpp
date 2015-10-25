#include "SimpleList.h"

List MakeEmpty(List L)
{
	if (L != NULL)
		DeleteList(L);
	L = (List)malloc(sizeof(Node));
	if (L == NULL)
	{
		cout<<"Out Of Space!!!"<<endl;
		return NULL;
	}
	L->Next = NULL;
	return L;
}

int IsEmpty(List L)
{
	return(L->Next == NULL); 
}

int IsLast(Position P, List L)
{
	return P->Next == NULL;
}
Position Find(ElementType X, List L)
{
	Position P=L->Next;
	while (P!=NULL&&P->Element!=X)
		P = P->Next;
	return P;
}
void DeleteFromPosition(Position P, List L)
{
	Position Previous,TmpCell ;
	Previous = L;
	while (Previous != NULL&&Previous->Next != P)
		Previous = Previous->Next;
	if (Previous != NULL)
	{
		TmpCell = Previous->Next;
		Previous->Next = TmpCell->Next;
		free(TmpCell);
	}
}

void DeleteFromValue(ElementType X, List L)
{
	Position Previous, TmpCell;
	Previous = L;
	while (Previous->Next!= NULL&&Previous->Next->Element != X)
		Previous = Previous->Next;
	if (Previous != NULL)
	{
		TmpCell = Previous->Next;
		Previous->Next = TmpCell->Next;
		free(TmpCell);
	}
}
/*Insert after legal position P*/
void Insert(ElementType X, List L, Position P)
{
	Position TmpCell = (Position)malloc(sizeof(struct Node));
	if (TmpCell == NULL)
	{
		cout << "Out of Space" << endl;
		exit(-1);
	}
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

void DeleteList(List L)
{
	Position P ,TmpCell;
	P = L;
	while (P!=NULL)
	{
		TmpCell = P->Next;
		free(P);
		P = TmpCell;
	}
}
Position Header(List L)
{
	return L;
}
Position First(List L)
{
	return L->Next;
}

Position Advance(Position P)
{
	return P->Next;
}
ElementType Retrieve(Position P)
{
	return P->Element;
}