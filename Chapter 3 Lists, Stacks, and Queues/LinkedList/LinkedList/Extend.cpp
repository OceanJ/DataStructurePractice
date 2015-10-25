#include "SimpleList.h"

/*打印L中那些由P所指定的位置上的元素 （P元素以升序排列）
  例如 p=1,3,5,7 则打印L中第1、第3、第5和第7个元素 
  复杂度为O(L+P)
*/
void PrintLots(List L, List P)
{
	Position Lpos=First(L), Ppos=First(P);
	int Counter=1;
	while (Lpos && Ppos )
	{
		int Index = Ppos->Element;
		while (Counter++<Index)
		{
			Lpos = Lpos->Next;
		}
		cout << Retrieve(Lpos);
		Ppos = Ppos->Next;
	}
}
/* BeforeP is the cell before the two adjacent cells that are to be swapped. */
/* Error checks are omitted for clarity. */
void SwapWithNext(Position BeforeP,List L)
{
	Position P = BeforeP->Next;
	Position PNext = P->Next;
	P->Next = PNext->Next;
	PNext->Next = P;
	BeforeP->Next = PNext;
}
/* Return the Intersection list between L1 and L2 */
List Intersect(List L1, List L2)
{
	List Result = MakeEmpty(NULL);
	Position ResultPos=Result;
	Position L1Pos = L1->Next, L2Pos = L2->Next;
	while (L1Pos&&L2Pos)
	{
		if (L1Pos->Element > L2Pos->Element)
			L2Pos = L2Pos->Next;
		else if (L1Pos->Element < L2Pos->Element)
			L1Pos = L1Pos->Next;
		else
		{
			Insert(L1Pos->Element, Result, ResultPos);
			L1Pos = L1Pos->Next; 
			L2Pos = L2Pos->Next;
			ResultPos = ResultPos->Next;
		}
	}

	return Result;
}

/*Return union list between L1 and L2*/
List Union(List L1, List L2)
{
	List Result=MakeEmpty(NULL);
	Position ResultPos = Result;
	Position L1Pos = L1->Next, L2Pos = L2->Next;
	while (L1Pos&&L2Pos)
	{
		if (L1Pos->Element < L2Pos->Element)
		{
			Insert(L1Pos->Element, Result, ResultPos);
			ResultPos = ResultPos->Next;
			L1Pos = L1Pos->Next;
		}
		else if (L1Pos->Element > L2Pos->Element)
		{
			Insert(L2Pos->Element, Result, ResultPos);
			ResultPos = ResultPos->Next;
			L1Pos = L2Pos->Next;
		}
		else
		{	
			Insert(L1Pos->Element, Result, ResultPos);
			ResultPos = ResultPos->Next;
			L1Pos = L1Pos->Next;
			L2Pos = L2Pos->Next;
		}
	}

	while (L1Pos)
	{
		Insert(L1Pos->Element, Result, ResultPos);
		L1Pos = L1Pos->Next;
		ResultPos = ResultPos->Next;
	}
	while (L2Pos)
	{
		Insert(L2Pos->Element, Result, ResultPos);
		L2Pos = L2Pos->Next;
		ResultPos = ResultPos->Next;
	}
	return Result;
}
/*Asume L has a header and is not empty*/
List ReverseList(List L)
{
	Position CurrentPos, NextPos, PreviousPos;
	PreviousPos = NULL;
	CurrentPos = L->Next;
	NextPos = CurrentPos->Next;
	while (NextPos)
	{
		CurrentPos->Next = PreviousPos; //Reverse the point
		PreviousPos = CurrentPos;  //Move on 
		CurrentPos = NextPos;
		NextPos = NextPos->Next;
	}
	CurrentPos->Next = PreviousPos; //deal the last node
	L->Next = CurrentPos;			//CurrentPos is the new fisrt node
	return L;
}