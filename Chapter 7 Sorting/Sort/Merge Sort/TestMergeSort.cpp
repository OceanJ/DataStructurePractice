#include "MergeSort.h"

void main()
{
	ElementType A[] = { 8, 6, 4, 2, 0, 9, 7, 5, 3, 1 };
	int N = sizeof(A) / sizeof(ElementType);
	ElementType * TmpArray = new ElementType[10];
	PrintArray(A, N);
	MergeSort(A, N);
	PrintArray(A, N);
	getchar();
}