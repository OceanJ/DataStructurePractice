
#include "Stack_List.h"

int IsEmpty(Stack S)
{
	return S->Next == NULL;
}

Stack CreateStack(void)
{
	Stack S=new Node;
	if (S == NULL)
	{
		cout << "Out of Space!"<<endl;
		return NULL;
	}
	S->Next = NULL;
	return S;
	
}
void DisposeStack(Stack S)
{
	MakeEmpty(S);
	free(S);
}

void MakeEmpty(Stack S)
{
	if (IsEmpty(S))
	{
		cout << "Empty stack";
		return;
	}
	while (!IsEmpty(S)) 
	{
		Pop(S);
	}
}

void Push(ElementType X, Stack S)
{
	PtrToNode Tmpcell = new Node;
	if (!Tmpcell)
	{
		cout << "Out of Space!" << endl;
		return ;
	}  
	//Notice the order
	Tmpcell->Element = X; 
	Tmpcell->Next = S->Next;
	S->Next = Tmpcell;
}

ElementType Top(Stack S)
{
	if (IsEmpty(S))
	{
		cout << "Empty stack";
		return 0;
	}

	return S->Next->Element;
}


void Pop(Stack S)
{
	if (IsEmpty(S))
	{
		cout << "Empty stack";
		return;
	}
	//Notice the order
	PtrToNode FirstCell = S->Next;
	S->Next = FirstCell->Next;
	free(FirstCell);

}