#include"ShellSort.h"
void PrintArray(ElementType A[], int N)
{
	cout << "Array: {";
	for (int i = 0; i < N; i++)
	{
		cout << A[i] << "  ";
	}
	cout << "}" << endl;
}
void Swap(ElementType &A, ElementType &B)
{
	ElementType Tmp = A;
	A = B;
	B = Tmp;
}
void ShellSort(ElementType A[], int N)
{
	int i,Increment;
	for (Increment = N / 2; Increment > 0; Increment /= 2)
	{
		for (i = 0; i < N - Increment; i++)
		{
			if (A[i]>A[i + Increment])
				Swap(A[i], A[Increment]);
		}
		cout << "Increment: " << Increment;
		PrintArray(A, N);
	}
	
}