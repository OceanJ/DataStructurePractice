
#ifndef _AvlTree_H
#define _AvlTree_H
typedef int ElementType;
#include <iostream>
using namespace std;
struct AvlNode
{
	ElementType Element;
	AvlNode * Left;
	AvlNode * Right;
	int Height;
};

typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);


//Some Extend Function from the exercise
Position NewDoubleRoatateWithLeft(Position K3);
Position NewDoubleRoatateWithRight(Position K3);
int CountNodes(AvlTree T);
int CountLeaves(AvlTree T);
int CountFull(AvlTree T);
int  UpdateHeight(Position P);
AvlTree MinAvlTree(int Height);
AvlTree PerfectAvlTree(int Height);
void PrintKeyBetween(ElementType Lower,ElementType Higher, AvlTree T);
#endif  /* _AvlTree_H */
/* END */
