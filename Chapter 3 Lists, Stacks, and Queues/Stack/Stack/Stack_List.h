
/* Stack implemention is a linked list with a header*/

#ifndef _Stack_List_h
#define _Stack_List_h
#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
	ElementType Element;
	PtrToNode Next;
};

typedef PtrToNode Stack;
int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);


#endif  /* _Stack_List_h*/


