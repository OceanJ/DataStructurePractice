#include "SimpleList.h"
void PrintList(List L)
{
	Position P = L;
	while (P->Next != NULL)
	{
		P = P->Next;
		printf("%d --->", P->Element);
	}
	printf("\n");
}
int main(int argc, char* argvs[])
{
	List TestList=NULL ;
	TestList = MakeEmpty(TestList);
	Position P = TestList;
	printf("Is L is Empty:%d\n", IsEmpty(TestList));
	printf("Is P is Last:%d\n", IsLast(P, TestList));
	for (int i = 0; i < 10; i++)
	{
		Insert(i*i, TestList, P);
		P = P->Next;
	}
	printf("Insert:\n");
	PrintList(TestList);
	printf("Delete the Last Positon:\n");
	DeleteFromPosition(P, TestList);
	PrintList(TestList);
	printf("Delete the value of 25:\n");
	DeleteFromValue(25, TestList);
	PrintList(TestList);
	getchar();
}