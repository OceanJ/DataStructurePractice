#include "Stack_Array.h"

Stack CreateStack(int MaxElemnts)
{
	Stack S = new StackRecord;
	if (S == NULL)
	{
		cout << "Out of Space!!!";
		return NULL;
	}
	S->Array = new ElementType[MaxElemnts];
	if (S->Array == NULL)
	{
		cout << "Out of Space!!!";
		return NULL;
	}
	S->Capacity = MaxElemnts;
	MakeEmpty(S);

	return S;
}

void DisposeStack(Stack S)
{
	if (S != NULL)
	{
		free(S->Array);
		free(S);
	}
}
int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S)
{
	return S->TopOfStack >= S->Capacity - 1;
}

void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}

void Push(ElementType X, Stack S)
{
	if (IsFull(S))
	{
		cout << "Full Stack!!!";
		return;
	}
	/*Notice the order ,increase the index,then set the top value*/
	S->Array[++S->TopOfStack] = X;
}

ElementType Top(Stack S)
{
	if (IsEmpty(S))
	{
		cout << "Empty Stack!!!";
		return 0;
	}
	return S->Array[S->TopOfStack];
}

void Pop(Stack S)
{
	if (IsEmpty(S))
	{
		cout << "Empty Stack!!!";
		return;
	}
	S->TopOfStack--;
}

ElementType TopAndPop(Stack S)
{
	if (IsEmpty(S))
	{
		cout << "Empty Stack!!!";
		return 0;
	}
	/*Notice the order!Get the Top, then decrease index of Top */
	return S->Array[S->TopOfStack--];
}
