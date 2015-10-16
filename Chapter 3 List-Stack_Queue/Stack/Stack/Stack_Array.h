

#ifndef _Stack_Array_h
#define _Stack_Array_h
typedef int ElementType;
/*Stack implementation is a dynamically array*/
#include <iostream>
using namespace std;
#define EmptyTOS (-1)
struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType* Array;
};
typedef struct StackRecord *Stack;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

#endif  /* _Stack_h */

/* END */
