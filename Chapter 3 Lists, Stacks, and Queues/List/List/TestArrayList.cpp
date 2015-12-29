#include "ArrayList.h"
int main()
{
	ArrayList ArrayList1 = CreateArrayList(10);
	for (int i = 0; i < 8; i++){
		printf("Inserting %d \n", i);
		InsertNum(ArrayList1->N, i, ArrayList1);
		PrintList(ArrayList1);
	}
	PrintList(ArrayList1);
	printf("Deleting Fisrt Element:\n");
	DeleteFromIndex(0, ArrayList1);
	PrintList(ArrayList1);
	printf("Deleting  %d:\n", ArrayList1->Elements[ArrayList1->N - 1]);
	DeleteFromValue(ArrayList1->Elements[ArrayList1->N - 1], ArrayList1);
	PrintList(ArrayList1);

	//Test Merge
	printf("Now Test Merge ArrayList:\n");
	int data1[] = { 123, 53, 64, 23, 67, 2, 4, 67 };
	int data2[] = { 23, 345, 78, 79, 3, 667, 98, 22, 42, 13 };
	ArrayList L1 = CreateArrayList(20, data1, sizeof(data1)/sizeof(int));
	ArrayList L2 = CreateArrayList(20, data2, sizeof(data2) / sizeof(int));
	ArrayList L3 = MergeList(L1, L2);
	PrintList(L1);
	PrintList(L2);
	PrintList(L3);
	DistroyList(L1);
	DistroyList(L2);
	DistroyList(L3);
	getchar();

}