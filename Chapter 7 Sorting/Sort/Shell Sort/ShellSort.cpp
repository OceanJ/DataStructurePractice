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
	int i,j,Increment;
	ElementType Tmp;
	for (Increment = N / 2; Increment > 0; Increment /= 2)
	{
		for (i = Increment;i < N; i+=Increment)
		{
			Tmp = A[i];
			//相当于对N/Increment个数组执行选择排序
			for (j = i; j>=Increment; j -= Increment)
			{
				if (Tmp < A[j-Increment])
					A[j] = A[j - Increment];
				else
					break;
			}
			A[j] = Tmp;				
		}
		cout << "Increment: " << Increment;
		PrintArray(A, N);
	}
}