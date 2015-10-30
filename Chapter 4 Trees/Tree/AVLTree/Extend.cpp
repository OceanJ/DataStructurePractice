#include "AvlTree.h"

Position NewDoubleRoatateWithLeft(Position K3)
{
	Position K1 = K3->Left;
	Position K2 = K1->Right;
	K3->Left = K2->Right;
	K1->Right = K2->Left;
	K2->Left = K1;
	K2->Right = K3;
	UpdateHeight(K1);
	UpdateHeight(K3);
	UpdateHeight(K2);

	return K2;
}
Position NewDoubleRoatateWithRight(Position K3)
{
	Position K1 = K3->Right;
	Position K2 = K1->Left;

	K3->Right = K2->Left;
	K1->Left = K2->Right;
	K2->Left = K3;
	K2->Right = K1;


	UpdateHeight(K1);
	UpdateHeight(K3);
	UpdateHeight(K2);

	return K2;

}
int CountNodes(AvlTree T)
{
	if (T == NULL)
		return 0;
	else
		return 1 + CountNodes(T->Left) + CountNodes(T->Right);
}
int CountLeaves(AvlTree T)
{
	if (T == NULL)
		return 0;
	else if (!T->Left&&!T->Right)
	{
		return 1;
	}
	else
		return CountLeaves(T->Left) + CountLeaves(T->Right);
}
int CountFull(AvlTree T)
{
	//Just use the proof
	return CountLeaves(T) - 1;
}
AvlTree GenMinAvlTree(int Height, int* LastNode)
{
	AvlTree T = NULL;
	if (Height >= 0)
	{
		T = new AvlNode;
		if (!T)
		{
			cerr << "Out of space!!!" << endl;
			return NULL;
		}
		T->Left = GenMinAvlTree(Height - 1, LastNode);
		T->Element = ++*LastNode;
		T->Right = GenMinAvlTree(Height - 2, LastNode);
	}
	return T;
}
AvlTree GenPerfectAvlTree(int Height, int* LastNode)
{
	AvlTree T = NULL;
	if (Height >= 0)
	{
		T = new AvlNode;
		if (!T)
		{
			cerr << "Out of space!!!" << endl;
			return NULL;
		}
		T->Left = GenMinAvlTree(Height - 1, LastNode);
		T->Element = ++*LastNode;
		T->Right = GenMinAvlTree(Height - 1, LastNode);
	}
	return T;
}

AvlTree MinAvlTree(int Height)
{
	int LastNodeAssigned = 0;
	return GenMinAvlTree(Height, &LastNodeAssigned);
}
AvlTree PerfectAvlTree(int Height)
{
	int LastNodeAssigned = 0;
	return GenPerfectAvlTree(Height, &LastNodeAssigned);
}

void PrintKeyBetween(int Lower, int Higher,AvlTree T)
{
	if (T)
	{
		if (Lower <= T->Element)
			PrintKeyBetween(Lower,Higher,T->Left);
		if (T->Element >= Lower&&T->Element <= Higher)
			cout << T->Element << "  ";
		if (Higher >= T->Element)
			PrintKeyBetween(Lower, Higher, T->Right);

	}
}