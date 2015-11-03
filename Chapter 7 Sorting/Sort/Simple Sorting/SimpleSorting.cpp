#include"SimpleSorting.h"

ElementType * InsertionSort(ElementType  A[],int N)
{
	for (int i = 1; i < N; i++)
	{
		ElementType Tmp = A[i];
		int j;
		for (j= i; j>0 && A[j - 1] > Tmp; j--)
			A[j] = A[j - 1];
		A[j] = Tmp;
	}
	return A;
}

ElementType * SelectionSort(ElementType A[], int N)
{
	for (int i = 1; i < N; i++)
	{
		int MinIndex = i;
		for (int j = i; j < N; j++)
		{
			if (A[j] < A[MinIndex])
				MinIndex = j;
		}
		ElementType Tmp = A[i];
		A[i] = A[MinIndex];
		A[MinIndex] = Tmp;
	}
	return A;
}

ElementType * BobbleSort(ElementType A[],int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				ElementType Tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = A[j];
			}
		}
	}
	return A;
}
