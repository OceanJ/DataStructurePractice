#include "AvlTree.h"

AvlTree MakeEmpty(AvlTree T)
{
	if (T != NULL)
	{
		free(T->Left);
		free(T->Right);
		free(T);
	}
	return NULL;
}
Position Find(ElementType X, AvlTree T)
{
	if (T == NULL)
	{
		cerr << "Can't find " << X << endl;
		return NULL;
	}
	else if (X < T->Element)
		return Find(X, T->Left);
	else if (X>T->Element)
		return Find(X, T->Right);
	else return T;
}
Position FindMin(AvlTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}
Position FindMax(AvlTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Right == NULL)
		return T;
	else
		return FindMin(T->Right);
}
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
{
	if (T == NULL)
	{
		T = new AvlNode;
		if (T == NULL)
		{
			cerr << "Out of space!!!" << endl;
			return NULL;
		}
		T->Element = X;
		T->Height = 0;
		T->Left = T->Right = NULL;
	}
	else if (X < T->Element)
	{
		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2)
		{
			//Simplify the way to judge
			//if (Height(T->Left->Left)>Height(T->Left->Right))
			if (X<T->Left->Element)
				T = SingleRoatateWithLeft(T);
			else
				T = DoubleRoatateWithLeft(T);
		}
	}
	else if (X > T->Element)
	{
		T->Right= Insert(X, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
		{
			//if (Height(T->Right->Left)<Height(T->Left->Right))
			if (X>T->Right->Element)
				T = SingleRoatateWithRight(T);
			else
				T = DoubleRoatateWithRight(T);
		}
	}
	//If X=T->Element,  just ignore it...
	T->Height = Max(Height(T->Left), Height(T->Right))+1;
	//Notice :Must plus one ...
	
	return T;
}

AvlTree Delete(ElementType X, AvlTree T)
{
  //Todo
}

ElementType Retrieve(Position P)
{
	if (!P)
	{
		cerr << "The position is invalid!" << endl;
		return 0;
	}
	else
		return P->Element;
}
