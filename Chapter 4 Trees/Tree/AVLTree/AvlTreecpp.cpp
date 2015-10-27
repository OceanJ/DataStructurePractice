#include "AvlTree.h"

AvlTree MakeEmpty(AvlTree T)
{
	
}
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
int Max(int a, int b)
{
	return a > b ? a : b;
}
int Height(Position P)
{
	if (P == NULL)
		return -1;
	else
		return P->Height;
}
AvlTree SingleRoatateWithLeft(AvlTree K2)
{
	Position K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;

	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), Height(K2)) + 1;

	return K2;
}

AvlTree SingleRoatateWithRight(AvlTree K2)
{
	Position K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Right = K2;

	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), Height(K2)) + 1;

	return K2;
}

AvlTree DoubleRoatateWithLeft(AvlTree K3)
{
	K3->Left = SingleRoatateWithRight(K3->Left);

	return SingleRoatateWithLeft(K3);
}
AvlTree DoubleRoatateWithRight(AvlTree K3)
{
	K3->Right = SingleRoatateWithLeft(K3->Right);

	return SingleRoatateWithRight(K3);
}

AvlTree Insert(ElementType X, AvlTree T)
{//Todo here!
	/*
	if (T == NULL)
	{
		T = new AvlNode;
		
	}*/
}
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);
