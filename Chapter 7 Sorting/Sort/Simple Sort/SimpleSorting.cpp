#include"SimpleSorting.h"

void InsertionSort(ElementType  A[],int N)
{
	for (int i = 1; i < N; i++)
	{
		ElementType Tmp = A[i];
		int j;
		for (j= i; j>0 && A[j - 1] > Tmp; j--)
			A[j] = A[j - 1];
		A[j] = Tmp;
	}
}

void SelectionSort(ElementType A[], int N)
{
	for (int i = 0; i < N; i++)
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
}

void BubbleSort(ElementType A[],int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				ElementType Tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = Tmp;
			}
		}
	}
}
