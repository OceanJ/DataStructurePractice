/* Assumption of header use */
#ifndef _SimpleList_H

#include <iostream>
using namespace std;

typedef int ElementType;

typedef struct Node
{
	ElementType Element;
	Node* Next;
}*PtrToNode;

typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void DeleteFromPosition(Position P, List L);
void DeleteFromValue(ElementType X, List L);
void Insert(ElementType X, List L,Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);


/*Some extend function  */

void PrintLots(List L, List P);
void SwapWithNext(Position BeforeP, List L);
List Intersect(List L1, List L2);
List Union(List L1, List L2);
List ReverseList(List L);

#endif