#include "LinkedList.h"

void PrintList(List L)
{
	Position P = L;
	cout << "List : ";
	while (P->Next != NULL)
	{
		P = P->Next;
		cout << P->Element << " --> ";
	}
	cout<<("\n");
}
void TestBasalOperation()
{
	cout << "Now test the bascal operation"<< endl;
	List TestList = NULL;
	TestList = MakeEmpty(TestList);
	Position P = TestList;
	cout << "Is L is Empty? " << IsEmpty(TestList) << endl;
	cout << "Is P is Last?  " << IsLast(P, TestList) << endl;
	for (int i = 1; i < 10; i++)
	{
		Insert(i*i, TestList, P);
		P = P->Next;
	}
	cout << "Insert:\n";
	PrintList(TestList);
	cout << "Delete the Last Positon:\n";
	DeleteFromPosition(P, TestList);
	PrintList(TestList);
	cout << "Delete the value of 25:\n";
	DeleteFromValue(25, TestList);
	PrintList(TestList);
	cout << "Make List empty..." << endl;
	TestList=MakeEmpty(TestList);
	cout << "The basal operation test success !!!" << endl;
}

void TestSwapWithNext()
{
	cout << "\nNow test swap two element" << endl;
	List TestList = MakeEmpty(NULL);
	Position P = TestList;
	for (int i = 1; i < 5; i++)
	{
		Insert(i*i, TestList, P);
		P = P->Next;
	}
	PrintList(TestList);
	cout << "Now swap first two element" << endl;
	SwapWithNext(TestList, TestList);
	PrintList(TestList);
	TestList=MakeEmpty(TestList);
}
void TestReverseList()
{
	List TestList = MakeEmpty(NULL);
	Position P = TestList;
	cout << "\nNow test reverse list" << endl;
	for (int i = 1; i < 5; i++)
	{
		Insert(i*i, TestList, P);
		P = P->Next;
	}
	cout << "Before Reverse the list : " << endl;
	PrintList(TestList);
	ReverseList(TestList);
	cout << "After Reverse the list : " << endl;
	PrintList(TestList);
	cout << "Reverse list test succeed!!!" << endl;

}
void TestIntersectAndUnion()
{
	List L1 = MakeEmpty(NULL);
	List L2 = MakeEmpty(NULL);
	cout << "\nNow test list intersect and union !" << endl;
	Position P1 = L1, P2 = L2;
	for (int i = 1; i < 10; i++)
	{
		Insert( i, L1, P1);
		P1 = P1->Next;
	}
	for (int i = 5; i <15 ; i++)
	{
		Insert(i, L2, P2);
		P2 = P2->Next;
	}
	cout << "L1 : ";
	PrintList(L1);
	cout << "L1 : ";
	PrintList(L2);

	cout << "The Intersect Result : " << endl;
	List InterResult = Intersect(L1, L2);
	PrintList(InterResult);

	cout << "The Union Result : " << endl;
	List UnionResult = Union(L1, L2);
	PrintList(UnionResult);

	cout << "Intersect and Union test succeed!!!" << endl;
	L1=MakeEmpty(L1);
	L2=MakeEmpty(L2);
}


int main(int argc, char* argvs[])
{
	TestBasalOperation();
	TestSwapWithNext();
	TestReverseList();
	TestIntersectAndUnion();
	getchar();
}