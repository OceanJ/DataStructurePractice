#include "BinarySearchTree.h"

SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(ElementType X, SearchTree T)
{
	if (T == NULL)
		return NULL;
	else if (X > T->Element)
		return Find(X, T->Right);
	else if (X < T->Element)
		return Find(X, T->Left);
	else
		return T;
}

Position FindMin(ElementType X, SearchTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
		return T;
	else
		return FindMin(X, T->Left);
}

Position FindMax(ElementType X, SearchTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Right == NULL)
		return T;
	else
		return FindMax(X, T->Right);
}

SearchTree Insert(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
		//既防止了T本身为空，又为递归终点。
		T = new TreeNode;
		if (T == NULL)
		{
			cerr << "Out of space" << endl;
			return NULL;
		}
		T->Element = X;
		T->Left = T->Right = NULL;
		//思考为何不在这返回T？
	}
	else if (X < T->Element)
		Insert(X, T->Left);
	else if (X > T->Element)
		Insert(X, T->Right);
	return T;
}


SearchTree Delete(ElementType X, SearchTree T)
{
	Position P = Find(X, T);
	if (P == NULL)
	{
		cerr << "X is not in this binary search tree!" << endl;
		return T;
	}
	else if (P->Left == NULL&&P->Right == NULL)
		free(P);
	else if (P->Left == NULL||P->Right==NULL)
	{
		Position TmpPosition = P->Left?P->Left:P->Right;
		P->Element = TmpPosition->Element;
		P->Left = TmpPosition->Left;
		P->Right = TmpPosition->Right;
		free(TmpPosition);
	}
	else
	{
		Position MinPositon = FindMin(P->Right);
		P->Element = MinPositon->Element;
		Delete(MinPositon->Element,MinPositon);
	}
	return T;	
}

ElementType Retreve(Position P)
{
	if (P != NULL)
	{
		cerr << "The position is invalid!" << endl;
		return 0;
	}
	else return P->Element;
}