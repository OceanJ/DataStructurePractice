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

Position FindMin(SearchTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}

Position FindMax(SearchTree T)
{
	if (T == NULL)
		return NULL;
	else if (T->Right == NULL)
		return T;
	else
		return FindMax(T->Right);
}

SearchTree Insert(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
		//�ȷ�ֹ��T����Ϊ�գ���Ϊ�ݹ��յ㡣
		T = new TreeNode;
		if (T == NULL)
		{
			cerr << "Out of space" << endl;
			return NULL;
		}
		T->Element = X;
		T->Left = T->Right = NULL;
		//˼��Ϊ�β����ⷵ��T��
	}
	else if (X < T->Element)
		T->Left=Insert(X, T->Left);
	//������ ���˺þõ�Bug������
	//ע��Ҫ��Insert����ֵ����������
	else if (X > T->Element)
		T->Right=Insert(X, T->Right);
	//ע��Ҫ��Insert����ֵ����������	
	return T;
}
SearchTree
Delete(ElementType X, SearchTree T)
{
	Position TmpCell;

	if (T == NULL)
	{
		cerr << "Element not found" << endl;
		return T;
	}
	else
	if (X < T->Element)  /* Go left */
		T->Left = Delete(X, T->Left);
	else
	if (X > T->Element)  /* Go right */
		T->Right = Delete(X, T->Right);
	else  /* Found element to be deleted */
	if (T->Left && T->Right)  /* Two children */
	{
		/* Replace with smallest in right subtree */
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(T->Element, T->Right);
	}
	else  /* One or zero children */
	{
		TmpCell = T;
		if (T->Left == NULL) /* Also handles 0 children */
			T = T->Right;
		else if (T->Right == NULL)
			T = T->Left;
		free(TmpCell);
	}

	return T;
}
// My failure code 
//SearchTree Delete(ElementType X, SearchTree T)
//{
//	Position P = Find(X, T);
//	if (P == NULL)
//	{
//		cerr << "X is not in this binary search tree!" << endl;
//		return T;
//	}
//	else if (P->Left == NULL&&P->Right == NULL)
//		free(P);
//	else if (P->Left == NULL||P->Right==NULL)
//	{
//		Position TmpPosition = P->Left?P->Left:P->Right;
//		P->Element = TmpPosition->Element;
//		P->Left = TmpPosition->Left;
//		P->Right = TmpPosition->Right;
//		free(TmpPosition);
//	}
//	else
//	{
//		Position MinPositon = FindMin(P->Right);
//		P->Element = MinPositon->Element;
//		MinPositon=Delete(MinPositon->Element,MinPositon);
//	}
//	return T;	
//}

ElementType Retrieve(Position P)
{
	if (P == NULL)
	{
		cerr << "The position is invalid!" << endl;
		return 0;
	}
	else return P->Element;
}