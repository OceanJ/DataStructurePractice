#ifndef _BinHeap_H_
#include <iostream>
using namespace std;
typedef int ElementType;
const ElementType MinElement = -1e8;
struct HeapStruct
{
	int Capacity;
	int Size;
	ElementType *Elements;
};

typedef struct HeapStruct * PriorityQueue;
PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FinMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);
#endif