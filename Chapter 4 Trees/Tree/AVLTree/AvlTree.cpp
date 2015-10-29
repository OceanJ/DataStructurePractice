#include "AvlTree.h"

AvlTree MakeEmpty(AvlTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
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
//Use  recursion method 

//Position FindMin(AvlTree T)
//{
//	if (T == NULL)
//		return NULL;
//	else if (T->Left == NULL)
//		return T;
//	else
//		return FindMin(T->Left);
//}
//Position FindMax(AvlTree T)
//{
//	if (T == NULL)
//		return NULL;
//	else if (T->Right == NULL)
//		return T;
//	else
//		return FindMin(T->Right);
//}

//Use Loop Method 
Position FindMin(AvlTree T)
{
	if (T)
	{
		while (T->Left)
			T = T->Left;
	}
	return T;
}
Position FindMax(AvlTree T)
{

	if (T)
	{
		while (T->Right)
			T = T->Right;
	}
	return T;
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
int  UpdateHeight(Position P)
{
	P->Height = Max(Height(P->Left), Height(P->Right)) + 1;
	return P->Height;
}
Position SingleRoatateWithLeft(Position K2)
{
	Position K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;
	UpdateHeight(K2);
	UpdateHeight(K1);
	return K1;
}

Position SingleRoatateWithRight(Position K2)
{
	Position K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;
	UpdateHeight(K2);
	UpdateHeight(K1);
	return K1;
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
	UpdateHeight(T);
	//Notice :Must update height ...
	
	return T;
}

AvlTree Delete(ElementType X, AvlTree T)
{
	if (T == NULL)
	{
		cerr << "Can't find " << X << endl;
		return NULL;
	}
	else if (X < T->Element)
	{
		T->Left = Delete(X, T->Left);
		if (Height(T->Right) - Height(T->Left) == 2)
		{
			if (X>T->Left->Element)
				T->Left = SingleRoatateWithLeft(T->Left);
			else
				T->Left = DoubleRoatateWithLeft(T->Left);
		}
	}
	else if (X > T->Element)
	{
		T->Right = Delete(X, T->Right);
		if (Height(T->Left) - Height(T->Right) == 2)
		{
			if (X<T->Right->Element)
				T->Right = SingleRoatateWithRight(T->Right);
			else
				T->Right= DoubleRoatateWithRight(T->Right);
		}
	}
	else if (T->Left&&T->Right)
	{
		T->Element = Retrieve(FindMin(T->Right));
		T->Right = Delete(T->Element, T->Right);
	}
	else
	{
		Position TmpCell = T;
		T = T->Left ? T->Left : T->Right;
		free(TmpCell);
	}

	UpdateHeight(T);
	return T;
}
//Reference :http://www.geeksforgeeks.org/avl-tree-set-2-deletion/
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
