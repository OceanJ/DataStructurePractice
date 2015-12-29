#include "BinarySearchTree.h"

//To make the tree empty
SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		//类似后序遍历
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
		//Recursion base case 
		T = new TreeNode;
		if (T == NULL)
		{
			cerr << "Out of space" << endl;
			return NULL;
		}
		T->Element = X;
		T->Left = T->Right = NULL;
	}
	else if (X < T->Element)
		T->Left=Insert(X, T->Left);
	//啊啊啊 找了好久的Bug！！！
	//Attention:the return value must assign to itself
	//注意要把Insert返回值给到左树本身。
	else if (X > T->Element)
		T->Right=Insert(X, T->Right);
	//注意要把Insert返回值给到右树本身。	
	return T;
}

SearchTree Delete(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
		cerr << "Can't find "<< X<<endl;
		return NULL;
	}
	else if (X < T->Element)
		//Go Left
		T->Left = Delete(X, T->Left);
	else if (X > T->Element)
		//Go Right
		T->Right = Delete(X, T->Right);
	//Has found the element to be deleted
	else if (T->Left && T->Right)//Has two children
	{	
		//Replace its value with the min in right subtree
		T->Element = Retrieve(FindMin(T->Right));
		//Delete the min node in the right subtree
		T->Right = Delete(T->Element, T->Right);
	}
	else //One or zero children
	{
		Position TmpCell = T;
		//Also handles zero children
		T= T->Left ? T->Left : T->Right;
		free(TmpCell);
	}
	return T;//Don't forget to return T !!!
}

ElementType Retrieve(Position P)
{
	if (P == NULL)
	{
		cerr << "The position is invalid!" << endl;
		return 0;
	}
	else return P->Element;
}


//前序遍历
void PreOrder(SearchTree T)
{
	if (T)
	{
		cout << T->Element << "  ";
		InOrder(T->Left);
		InOrder(T->Right);
	}
}
//中序遍历
void InOrder(SearchTree T)
{
	if (T)
	{
		InOrder(T->Left);
		cout << T->Element << "  ";
		InOrder(T->Right);
	}
}
//后序遍历
void PostOrder(SearchTree T)
{
	if (T)
	{
		InOrder(T->Left);
		InOrder(T->Right);
		cout << T->Element << "  ";
	}
}
//递归求二叉树高度（动态规划）
int CalHeight(SearchTree T)
{
	int CurrentHeight,LeftHegiht,RightHeight;
	//设置递归终点
	if (!T)
		return 0;
	LeftHegiht = CalHeight(T->Left);
	RightHeight = CalHeight(T->Right);
	//树高为其左子树和右子树高中较大者加1
	CurrentHeight = (LeftHegiht > RightHeight ? LeftHegiht : RightHeight) + 1;
	return CurrentHeight;
}