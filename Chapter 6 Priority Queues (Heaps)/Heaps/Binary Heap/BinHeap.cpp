#include "BinHeap.h"
PriorityQueue Initialize(int MaxElements)
{
	PriorityQueue H = new HeapStruct;
	if (!H)
	{
		cerr << "Out of Space!!!" << endl;
		return NULL;
	}
	H->Elements = new ElementType[MaxElements];
	if (!H->Elements)
	{
		cerr << "Out of Space!!!" << endl;
		return NULL;
	}
	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = MinElement;
}
void Destroy(PriorityQueue H)
{
	if (!H)
	{
		cerr << "Heap is invalid" << endl;
		return;
	}
	free(H->Elements);
	free(H);
}
void MakeEmpty(PriorityQueue H)
{
	if (!H)
	{
		cerr << "Heap is invalid" << endl;
		return;
	}
	H->Size = 0;
}
void Insert(ElementType X, PriorityQueue H)
{
	int i;
	if (IsFull(H))
	{
		cerr << "Priority is full!!!" << endl;
		return;
	}

	for (i = ++H->Size; H->Elements[i/2]>X; i /= 2)
	{
		H->Elements[i] = H->Elements[i / 2];
	}
	H->Elements[i] = X;
}
ElementType DeleteMin(PriorityQueue H)
{
	int i, Child;
	ElementType MinElement, LastElement;
	if (IsEmpty(H))
	{
		cerr << "Priority is empty!!!" << endl;
		return;
	}
	MinElement = H->Elements[1];
	LastElement = H->Elements[H->Size--];
	for (i = 1,Child=1; i <= H->Size; i = Child)
	{
		Child = i * 2;
		if (Child!=H->Size&&H->Elements[Child] > H->Elements[Child + 1])
			Child++;
		if (H->Elements[i]<LastElement)
			H->Elements[i] = H->Elements[Child];
	}
	H->Elements[i] = LastElement;
	return MinElement;

}
ElementType FinMin(PriorityQueue H)
{
	if (IsEmpty(H))
	{
		cerr << "Priority Queue is Empty";
		return H->Elements[0];

	}
	return H->Elements[1];

}
int IsEmpty(PriorityQueue H)
{
	return H->Size == 0;
}
int IsFull(PriorityQueue H)
{
	return H->Size >= H->Capacity;
}