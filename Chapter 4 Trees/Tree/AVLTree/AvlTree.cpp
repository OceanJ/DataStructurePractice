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
	//Go Left
	else if (X < T->Element)
		return Find(X, T->Left);
	//Go Right
	else if (X>T->Element)
		return Find(X, T->Right);
	//Finded!
	else return T;
}
//Use  recursion method but waste stack space
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
//To get height of P
int Height(Position P)
{
	if (P == NULL)
		return -1;
	else
		return P->Height;
}
//To update height of P
int  UpdateHeight(Position P)
{
	if (P == NULL)
		return -1;
	P->Height = Max(Height(P->Left), Height(P->Right)) + 1;
	return P->Height;
}
//To get if P is balanced or not
int GetBalance(Position P)
{
	if (!P)
		return 0;
	return Height(P->Left) - Height(P->Right);
//0 ,1 ,-1: Balanced
//2       : Left subtree is higher
//-2      : Right subtree is higher

}
//Deal Left-Left situation
Position SingleRoatateWithLeft(Position K2)
{
	Position K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;

	//Update height
	UpdateHeight(K2);
	UpdateHeight(K1);

	//Return the new root
	return K1;
}

//Deal Right-Right situation
Position SingleRoatateWithRight(Position K2)
{
	Position K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;

	//Update height
	UpdateHeight(K2);
	UpdateHeight(K1);

	//Return the new root
	return K1;
}

	//Deal Left-Right situation
Position DoubleRoatateWithLeft(Position K3)
{
	//First do a Right Single Roatate
	K3->Left = SingleRoatateWithRight(K3->Left);
	
	//Then do a Left Single Rotate 
	//At Last, Return the new root
	return SingleRoatateWithLeft(K3);
}
Position DoubleRoatateWithRight(Position K3)
{
	//First do a Left Single Roatate
	K3->Right = SingleRoatateWithLeft(K3->Right);

	//Then do a Right Single Rotate 
	//At Last, Return the new root
	return SingleRoatateWithRight(K3);
}

AvlTree Insert(ElementType X, AvlTree T)
{
	if (T == NULL)
	{
		//Create a new Node
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
		if (GetBalance(T) == 2)
		{
			//Simplify the way to judge
			//if (Height(T->Left->Left)>Height(T->Left->Right))
			if (X<T->Left->Element)
				//Deal Left-Left case
				T = SingleRoatateWithLeft(T);
			else
				//Deal Left-Right case
				T = DoubleRoatateWithLeft(T);
		}
	}
	else if (X > T->Element)
	{
		T->Right= Insert(X, T->Right);
		if (GetBalance(T) == -2)
		{
			//if (Height(T->Right->Left)<Height(T->Left->Right))
			if (X>T->Right->Element)
				//Deal Right-Right case
				T = SingleRoatateWithRight(T);
			else
				//Deal Right-Left case
				T = DoubleRoatateWithRight(T);
		}
	}
	//If X=T->Element,  just ignore it...
	
	UpdateHeight(T);
	//Update height of this node

	return T;
}

/*
Let w be the node to be deleted
1) Perform standard BST delete for w.
2) Starting from w, travel up and find the first unbalanced node.
Let z be the first unbalanced node,
y be the larger height child of z,
and x be the larger height child of y.
Note that the definitions of x and y are different from insertion here.
3) Re-balance the tree by performing appropriate rotations on the subtree rooted with z.

There can be 4 possible cases that needs to be handled as x, y and z can be arranged in 4 ways.
Following are the possible 4 arrangements:
a) y is left child of z and x is left child of y (Left Left Case)
b) y is left child of z and x is right child of y (Left Right Case)
c) y is right child of z and x is right child of y (Right Right Case)
d) y is right child of z and x is left child of y (Right Left Case)

Like insertion, following are the operations to be performed in above mentioned 4 cases.
Note that, unlike insertion, fixing the node z won¡¯t fix the complete AVL tree.
After fixing z, we may have to fix ancestors of z as well

References :http://www.geeksforgeeks.org/avl-tree-set-2-deletion/
*/


AvlTree Delete(ElementType X, AvlTree T)
{
	if (T == NULL)
	{
		cerr << "Can't find " << X << endl;
		return NULL;
	}
	//Go Right 
	else if (X > T->Element)
	{
		T->Right = Delete(X, T->Right);
		//The Left subtree is probably higher than Right subtree
		if (GetBalance(T) == 2)
		{
			//Deal Left - Left case
			if (GetBalance(T->Left) >= 0)
				T= SingleRoatateWithLeft(T);
			
			else
			//Deal Left - Right case
				T= DoubleRoatateWithLeft(T);
		}
	}

	//Go Left
	else if (X < T->Element)
	{
		T->Left = Delete(X, T->Left);

		//Now the Right subtree is probably higher than Left subtree
		if (GetBalance(T) == -2)
		{
			//Deal Right-Right case
			if (GetBalance(T->Right)  <= 0)
				T= SingleRoatateWithRight(T);
			else
			//Deal Right-Left case
				T= DoubleRoatateWithRight(T);
		}
	}
	//Finded!
	//Deal the situation that node has Two child nodes
	else if (T->Left&&T->Right)
	{
		T->Element = Retrieve(FindMin(T->Right));
		T->Right = Delete(T->Element, T->Right);
	}
	//Deal the situation that node has One or Zero child nodes
	else
	{
		Position TmpCell = T;
		T = T->Left ? T->Left : T->Right;
		free(TmpCell);
	}

	//Must update height
	UpdateHeight(T);
	return T;
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
